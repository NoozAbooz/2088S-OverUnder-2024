"""
Super basic code to scan for and connect to v5 devices using the python bleak library. Prints out all data read over the user port.
"""

import argparse
import asyncio

from bleak import BleakScanner, BleakClient

SERVICE_UUID = "08590f7e-db05-467e-8757-72f6faeb13d5"


CHAR1_UUID = "08590f7e-db05-467e-8757-72f6faeb1306"
CHAR2_UUID = "08590f7e-db05-467e-8757-72f6faeb1316"

CHAR3_UUID = "08590f7e-db05-467e-8757-72f6faeb13e5"


def char2_callback(characteristic, data: bytearray):
    print(data)


async def main(args: argparse.Namespace):
    print("scanning for 5 seconds, please wait...")

    devices = await BleakScanner.discover(
        return_adv=True, cb=dict(use_bdaddr=args.macos_use_bdaddr), timeout=5.0
    )

    # Find all devices with characteristic 08590f7e-db05-467e-8757-72f6faeb13d5
    # and that are from texas instruments (54:6C:0E:*:*:*)
    devs = []

    for k, (d, a) in devices.items():
        # We want to scan for texas instruments devices:
        # 54:6C:0E:*:*:*
        # if not k.startswith("54:6C:0E"):
        #    continue

        # We are also trying to identify services with UUID
        # 08590f7e-db05-467e-8757-72f6faeb13d5
        if SERVICE_UUID not in a.service_uuids:
            continue

        devs.append((d, a))

    # Sort by largest rssi
    devs = sorted(devs, key=lambda v: v[0].rssi)

    # If there are no devices, exit
    if len(devs) < 1:
        print("No V5 Brains Found")
        return

    # Get the first device
    device = devs[0]

    async with BleakClient(device[0]) as client:
        # Read CHAR3. It should return 0xdeadface (big endian)
        magic = await client.read_gatt_char(CHAR3_UUID)

        # If not, drop the device
        if int.from_bytes(magic, "big") != 0xDEADFACE:
            print("No V5 Devices Found")
            return

        # Now, write 0xffffffff to CHAR3
        await client.write_gatt_char(CHAR3_UUID, bytes([0xFF, 0xFF, 0xFF, 0xFF]))

        out = str()

        while True:
            # At this point, the brain will show a message with a number. The number needs to be read
            # from the user as a string, and each digit converted into a byte and send as a payload of four bytes
            confirm = input("Enter Code On Brain's Screen > ")

            if len(confirm) != 4 or not confirm.isnumeric():
                print("Code must be four numeric characters")
                continue

            out = confirm
            break

        if len(confirm) != 4 or not confirm.isnumeric():
            print("Internal error")
            exit()

        # Convert to bytes
        confirm_bytes = bytes(int(c) for c in out)

        # Write these bytes to CHAR3
        await client.write_gatt_char(CHAR3_UUID, confirm_bytes)

        # Now read from CHAR3 until we get the confirm bytes back
        cresp = bytes([])
        while cresp != confirm_bytes:
            cresp = await client.read_gatt_char(CHAR3_UUID)

        print("Confirmation Complete")

        # Now CHAR3 can be communicated with using regular V5 serial commands!
        # Make sure to respect MTU and everything else should work just like a serial port.

        # VEXCode sets up notifications for characteristics 1 and 2
        # Char2 is the user port. Char3 is the system port.
        await client.start_notify(CHAR2_UUID, char2_callback)

        while True:
            await asyncio.sleep(10 / 1000)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()

    parser.add_argument(
        "--macos-use-bdaddr",
        action="store_true",
        help="when true use Bluetooth address instead of UUID on macOS",
    )

    args = parser.parse_args()

    asyncio.run(main(args))

#include "main.h"

namespace strait
{
	namespace selector
	{
		int auton = 9;
		void tabWatcher() {
			while (1) {
				if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
					auton = auton + 1;

					if(auton > 10) {
						auton = 0;
					}
				}

				pros::delay(10);
			}
		}

		void init() {
			// start tab watcher
			pros::Task tabWatcher_task(tabWatcher);
		}
	}
}

// Inspired by https://github.com/Adam-Salem-Codes/Vex-Autonomous-Selector
#include "main.h"
#include "selector.hpp"
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <string>

namespace strait
{
	namespace selector
	{
		int auton = 10;
		
		void tabWatcher() {
			//readIntFromFile();

			while (1) {
				if(potentiometer.get_angle() > 15) {
					auton = 1;
				} else if (potentiometer.get_angle() > 30)

				if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
					auton = auton + 1;

					if(auton > 10) {
						auton = 0;
					}

					//writeIntToFile(auton);
				}

				pros::delay(10);
			}
		}

		void init() {
			// start tab watcher
			pros::Task tabWatcher_task(tabWatcher);
		}

		void writeIntToFile(int num) {
    		FILE *save_file;
    		char buffer[51]; // 50 bytes for data, 1 byte for '\0'

    		if (num != -1) { // If num is not -1, write it to the file
    		    save_file = fopen("/usd/auton.txt", "w");
    		    if (save_file != NULL) {
    		        fprintf(save_file, "%d", num);
    		        fclose(save_file);
    		    } else {
    		        printf("Error opening file for writing\n");
    		    }
    		}
		}
	}
}

// Inspired by https://github.com/Adam-Salem-Codes/Vex-Autonomous-Selector
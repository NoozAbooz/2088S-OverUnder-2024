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

		void readIntFromFile() {
			FILE *load_file;
			int num;

			load_file = fopen("/usd/auton.txt", "r");
			fscanf(load_file, "%d", &num); // Read an integer from the file
			
			//printf("%d\n", std::stof(auton)); // print the string read from the file
			fclose(load_file); // always close files when you're done with them
		}
	}
}

// Inspired by https://github.com/Adam-Salem-Codes/Vex-Autonomous-Selector
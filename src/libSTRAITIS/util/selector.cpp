#include "main.h"
#include "pros/rtos.h"
#include "selector.hpp"
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <string>

namespace strait
{
	namespace selector
	{
		int auton;
		void tabWatcher() {
			//readIntFromFile();

			while (true) {
				auton = round(((4096.0 - potentiometer.get_value()) / 4096.0) * 10);

    			// Ensure auton is within the range 1-10
    			if (auton < 1) {
    			    auton = 1;
    			} else if (auton > 10) {
    			    auton = 10;
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
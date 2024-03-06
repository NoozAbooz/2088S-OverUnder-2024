#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

namespace strait
{
	namespace selector
	{
		int auton;
		
		void tabWatcher() {
			writeOrReadIntToFile(-1);

			while (1) {
				if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
					auton = auton + 1;

					if(auton > 10) {
						auton = 0;
					}

					writeOrReadIntToFile(auton);
				}

				pros::delay(10);
			}
		}

		void init() {
			// start tab watcher
			pros::Task tabWatcher_task(tabWatcher);
		}

		void writeOrReadIntToFile(int num = -1) {
    		FILE *file;
    		char buffer[51]; // 50 bytes for data, 1 byte for '\0'
    		int readNum;

    		if (num != -1) { // If num is not -1, write it to the file
    		    file = fopen("/usd/auton.txt", "w");
    		    if (file != NULL) {
    		        fprintf(file, "%d", num);
    		        fclose(file);
    		    } else {
    		        printf("Error opening file for writing\n");
    		    }
    		} else { // If num is -1, read from the file
    		    file = fopen("/usd/auton.txt", "r");
    		    if (file != NULL) {
    		        if (fgets(buffer, 51, file) != NULL) {
    		            auton = atoi(buffer);
    		        }
    		        fclose(file);
    		    } else {
    		        printf("Error opening file for reading\n");
    		    }
    		}
		}
	}
}

// Inspired by https://github.com/Adam-Salem-Codes/Vex-Autonomous-Selector
#include "main.h"

namespace strait
{
	namespace selector
	{
		int auton;
		void tabWatcher() {
			while (true) {
				auton = 6; // lock for elims

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
	}
}
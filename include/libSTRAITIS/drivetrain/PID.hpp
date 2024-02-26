#include "iostream"

namespace strait {
	class LateralPID {
		public:
			LateralPID();
			double kp;
			double kd;
			double timeOut;

			void set_constants(double kp, double kd, double timeOut);
			void set_lateral_pid(double target, double maxSpeed);	

	};
	extern strait::LateralPID pid;
}

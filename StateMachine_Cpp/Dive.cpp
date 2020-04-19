#include "Dive.h"
#include "AUV_StateContext.h"
#include <iostream>

using namespace std;

Dive::~Dive() = default;

Dive::Dive() {

}

void Dive::Execute() {
	do {
		this->barometricPressure = 0;
		//Update barometricPressure with value from barometer
		this->altitude = 0;
		//Update altitude = barometricPressure converted to altitude using
		//					correct scientific formula

		if (this->altitude > this->requiredAltitude) {
			//Thruster full power
			cout << "Moving down!" << endl;

			// update altitude value. This is only a test value
			this->altitude = this->altitude - 20;
		}
	} while (this->altitude > this->requiredAltitude);

	AUV_StateContext context;
	context.SetState(AUV_StateContext::SEARCH);
	context.Execute();
}

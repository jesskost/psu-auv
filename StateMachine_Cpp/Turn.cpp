#include "Turn.h"
#include "AUV_StateContext.h"
#include <iostream>

using namespace std;

Turn::~Turn() = default;

Turn::Turn() {
	this->degrees = 0;
}

void Turn::SetDegrees(double value) {
	this->degrees = value;
}

void Turn::Execute() {
	cout << "Turning AUV!" << endl;

	if (this->degrees >= 0 && this->degrees < 180) {
		//Turn thrusters to the left

	}
	else {
		//Turn thrusters to the right

	}
	AUV_StateContext context;
	//Depending on which stage the AUV is currently in, go back to SEARCH or DECIDE
	/*context.SetState(AUVStateContext::SEARCH);
	context.SetState(AUVStateContext::DECIDE);*/
	context.Execute();
}

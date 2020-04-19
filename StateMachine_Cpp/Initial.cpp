#include "Initial.h"
#include "AUV_StateContext.h"
#include <iostream>

using namespace std;

Initial::~Initial() = default;

Initial::Initial() {

}

void Initial::Execute() {
	if (this->switch_mode == "OFF") {

		//Execute necessary code

		cout << "Hardware components reset." << endl;
	}
	else {
		//Execute code to start thrusters

		cout << "Power on thrusters" << endl;

		AUV_StateContext context;
		context.SetState(AUV_StateContext::DIVE);
		context.Execute();
	}
	cout << "Go to starting position" << endl;

}
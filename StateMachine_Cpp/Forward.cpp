#include "Forward.h"
#include <iostream>

using namespace std;

Forward::~Forward() = default;

Forward::Forward() {
	this->distance = 0;
}

void Forward::SetDistance(double value) {
	this->distance = value;
}

void Forward::Execute() {

	//Move forward until required distance reached

	for (int position = 0; position < distance; position++) {
		//Power thrusters forward
		cout << "Moving Forward!" << endl;
	}

}
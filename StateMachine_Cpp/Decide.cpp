#include "Decide.h"
#include "AUV_StateContext.h"

Decide::~Decide() = default;

Decide::Decide() {
	this->objectFound = false;
}

void Decide::SetObjectOfChoice(string object) {
	this->objectOfChoice = object;
}

void Decide::Execute() {
	//Activate object detection functionality

	while (objectFound == false) {
		//Determine if objectOfChoice in current frame
		bool inCurrentFrame = true; 
		if (inCurrentFrame) {

			objectFound = true;

			AUV_StateContext context;
			context.SetState(AUV_StateContext::FORWARD);
			context.Execute();
		}
		else {
			AUV_StateContext context;
			context.SetState(AUV_StateContext::TURN);
			context.Execute();
		}

	}
}
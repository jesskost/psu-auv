#include "Search.h"
#include "AUV_StateContext.h"
#include <iostream>

using namespace std;

Search::~Search() = default;

Search::Search() {

}

void Search::Execute() {
	//Activate object detection unit
	//Set objectFound = whether object(gate) detected/not
	

	while (this->objectFound == false) {
		cout << "Searching for gate" << endl;
		bool objectInCurrentFrame = true;

		if (objectInCurrentFrame) {
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
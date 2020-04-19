#include "AUV_StateContext.h"
#include "Initial.h"
#include "Dive.h"
#include "Search.h"
#include "Turn.h"
#include "Forward.h"
#include "Decide.h"
#include "Next.h"
enum States { INITIAL, DIVE, SEARCH, TURN, FORWARD, DECIDE, NEXT };

AUV_StateContext::AUV_StateContext() {
	this->currentState = INITIAL;
}

void AUV_StateContext::SetState(AUV_StateContext::States state) {
	this->currentState = state;
}

void AUV_StateContext::Execute() {
	switch (this->currentState)
	{
		case INITIAL:
		default: {
			Initial obj;
			obj.Execute();
			break;
		}
		case DIVE: {
			Dive obj;
			obj.Execute();
			break;
		}
		case SEARCH: {
			Search obj;
			obj.Execute();
			break;
		}
		case TURN: {
			Turn obj;
			obj.Execute();
			break;
		}
		case FORWARD: {
			Forward obj;
			obj.Execute();
			break;
		}
		case DECIDE: {
			Decide obj;
			obj.Execute();
			break;
		}
		case NEXT: {
			Next obj;
			obj.Execute();
			break;
		}
	};

}
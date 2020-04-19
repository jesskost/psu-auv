#include "Next.h"
#include "AUV_StateContext.h"

Next::~Next() = default;

Next::Next() {

}

void Next::Execute() {

	//Enter the next phase of the competition
	//after going through the gate

	AUV_StateContext context;
	context.SetState(AUV_StateContext::FORWARD);
	context.Execute();
}
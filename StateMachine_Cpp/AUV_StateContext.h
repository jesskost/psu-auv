#pragma once
class AUV_StateContext
{
public:
	AUV_StateContext();
	enum States { INITIAL, DIVE, SEARCH, TURN, FORWARD, DECIDE, NEXT };
	void Execute();
	void SetState(States state);
	States currentState;
};


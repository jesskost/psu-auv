#include "ICurrentState.h"
#include "AUV_StateContext.h"
#include <iostream>

using namespace std;

class Decide:public ICurrentState
{
private:
	string objectOfChoice;
	bool objectFound;
public:
	Decide();
	void SetObjectOfChoice(string object);
	void Execute();
	~Decide();
};


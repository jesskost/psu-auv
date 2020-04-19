#include "ICurrentState.h"
#include "AUV_StateContext.h"
#include <string>

class Initial:public ICurrentState
{
public:
	Initial();
	std::string switch_mode = "OFF";
	void Execute();
	~Initial();
};


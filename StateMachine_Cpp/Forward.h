#include "ICurrentState.h"
#include "AUV_StateContext.h"

class Forward: public ICurrentState
{
private:
	double distance;
public:
	Forward();
	void SetDistance(double value);
	void Execute();
	~Forward();
};


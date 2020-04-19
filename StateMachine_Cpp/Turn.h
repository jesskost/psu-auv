#include "ICurrentState.h"
#include "AUV_StateContext.h"

using namespace std;

class Turn: public ICurrentState
{
private:
	double degrees;
public:
	Turn();
	void SetDegrees(double value);
	void Execute();
	~Turn();
};


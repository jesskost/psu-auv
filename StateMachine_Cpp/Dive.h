#include "ICurrentState.h"
#include "AUV_StateContext.h"

class Dive : public ICurrentState
{
private:
	double barometricPressure;
	double altitude;
	const double requiredAltitude = 150; // update value as necessary
public:
	Dive();
	void Execute();
	~Dive();
};


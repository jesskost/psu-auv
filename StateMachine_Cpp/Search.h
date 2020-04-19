#include "ICurrentState.h"
#include "AUV_StateContext.h"

class Search: public ICurrentState
{
private:
	bool objectFound;
public:
	Search();
	void Execute();
	~Search();
};


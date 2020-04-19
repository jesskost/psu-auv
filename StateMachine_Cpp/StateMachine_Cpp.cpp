#include <iostream>
#include <string>
#include "AUV_StateContext.h"

using namespace std;

int main()
{
    AUV_StateContext context;
    context.SetState(AUV_StateContext::INITIAL);
    context.Execute();
}

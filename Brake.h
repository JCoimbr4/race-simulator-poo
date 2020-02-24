#pragma 
#include "Speed.h"
class Brake
{
	Speed* carSpeed;
public:
	Brake();
	~Brake();
	void pressBrake(int value);
	void setCarSpeed(Speed* speed);
};

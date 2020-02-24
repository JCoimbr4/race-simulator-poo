#pragma once
#include "Speed.h"
class Accelerator
{
	Speed* carSpeed;
public:
	Accelerator();
	~Accelerator();
	void pressAccelerator(int value);
	void setCarSpeed(Speed* speed);
};


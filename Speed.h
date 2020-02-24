#pragma once
class Speed {
	int currentSpeed, maxSpeed;
public:
	Speed();
	~Speed();

	void setCurrentSpeed(int value);
	void setMaxSpeed(int value);
	void addSpeed(int value);
	void subSpeed(int value);

	int getCurrentSpeed()const;
	int getMaxSpeed()const;
};
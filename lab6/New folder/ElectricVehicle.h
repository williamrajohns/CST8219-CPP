#pragma once
#include "Vehicle.h"


class ElectricVehicle : virtual public Vehicle {
	float currentCharge;
	float maximumCharge;

public:
	ElectricVehicle();
	ElectricVehicle(float max, float efficiency);
	virtual ~ElectricVehicle();

	float calculateRange();
	float percentEnergyRemaining();
	void drive(float km);


};

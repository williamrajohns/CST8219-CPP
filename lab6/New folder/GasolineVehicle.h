#pragma once
#include "Vehicle.h"

class GasolineVehicle : virtual public Vehicle {
	float currentGasoline;
	float maximumGasoline;

public:
	GasolineVehicle();
	GasolineVehicle(float max, float efficiency);
	virtual ~GasolineVehicle();

	float calculateRange();
	float percentEnergyRemaining();
	void drive(float km);
};



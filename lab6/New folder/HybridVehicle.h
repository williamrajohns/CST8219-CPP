#pragma once
#include "Vehicle.h"
#include "ElectricVehicle.h"
#include "GasolineVehicle.h"

class HybridVehicle : virtual public GasolineVehicle, virtual public ElectricVehicle {

	float currentCharge;
	float maximumCharge;
	float currentGasoline;
	float maximumGasoline;

public:
	HybridVehicle();
	HybridVehicle(float maxGas, float efficiency, float maxEle, float efficiencyEle);
	virtual ~HybridVehicle();

	float calculateRange();
	float percentEnergyRemaining();
	void drive(float km);
};




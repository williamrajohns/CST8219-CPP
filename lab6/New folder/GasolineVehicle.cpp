#pragma once
#include <iostream>
#include "GasolineVehicle.h"

using namespace std;

GasolineVehicle::GasolineVehicle() : GasolineVehicle(0, 0) {

}

GasolineVehicle::GasolineVehicle(float max, float efficiency) {
	maximumGasoline = max;
	currentGasoline = maximumGasoline;
	engineEfficiency = efficiency;
}

GasolineVehicle::~GasolineVehicle() {
	cout << "In Gasoline Destructor" << endl;   //Change ClassName to either Vehicle, Hybrid, Gasoline, Electric,
}


float GasolineVehicle::calculateRange() {
	return currentGasoline * 100 / engineEfficiency;
}

float GasolineVehicle::percentEnergyRemaining() {
	return currentGasoline / maximumGasoline * 100.0f;
}

void GasolineVehicle::drive(float km) {
	currentGasoline -= (km / 100) * engineEfficiency;
}
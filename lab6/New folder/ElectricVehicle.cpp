#pragma once
#include <iostream>
#include "ElectricVehicle.h"

using namespace std;

ElectricVehicle::ElectricVehicle() : ElectricVehicle(0, 0) {

}

ElectricVehicle::ElectricVehicle(float max, float efficiency) {
	maximumCharge = max;
	currentCharge = maximumCharge;
	engineEfficiency = efficiency;
}

ElectricVehicle::~ElectricVehicle() {
	cout << "In Electric Destructor" << endl;   //Change ClassName to either Vehicle, Hybrid, Gasoline, Electric,
}


float ElectricVehicle::calculateRange() {
	return currentCharge * 100 / engineEfficiency;
}

float ElectricVehicle::percentEnergyRemaining() {
	return currentCharge / maximumCharge *100.0f;
}

void ElectricVehicle::drive(float km) {
	currentCharge -= (km / 100) * engineEfficiency;
}
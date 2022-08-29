#pragma once
#include <iostream>
#include "HybridVehicle.h"

using namespace std;

HybridVehicle::HybridVehicle() : HybridVehicle(0, 0,0,0) {

}

HybridVehicle::HybridVehicle(float maxGas, float efficiencyGas, float maxEle, float efficiencyEle) {
	//gas
	maximumGasoline = maxGas;
	currentGasoline = maxGas;
	GasolineVehicle::engineEfficiency = efficiencyGas;
	//electric
	maximumCharge = maxEle;
	currentCharge = maxEle;
	ElectricVehicle::engineEfficiency = efficiencyEle;
}

HybridVehicle::~HybridVehicle() {
	cout << "In Hybrid Destructor" << endl;   //Change ClassName to either Vehicle, Hybrid, Gasoline, Electric,
}


float HybridVehicle::calculateRange() { //not sure what formula to use
	return ((currentGasoline * 100) / GasolineVehicle::engineEfficiency) + ((currentCharge * 100) / ElectricVehicle::engineEfficiency); 
}

float HybridVehicle::percentEnergyRemaining() {
	return ((currentGasoline / maximumGasoline * 100.0f) + (currentCharge / maximumCharge * 100.0f)) / 2;
}

void HybridVehicle::drive(float km) {
	float change = 0;
	if (currentCharge > 0) { //if it has a charge
			change = (km / 100) * ElectricVehicle::engineEfficiency; //check to see if the change of charge would make it negative
			if (change >= currentCharge) { //if it would make it negative
				change -= currentCharge; //remove the part from currentCharge
				currentCharge = 0; //set the new currentCharge to 0 (as the change would make it negative)
			}
			else  //else the change doesn't make it negative
			{ 
				currentCharge -= change; //reduce charge by the change
				change = 0; //set change to 0;
			}
	}
	
	if (change > 0 ){ //if there is still a change left 
		cout << "Your car is out of energy!" << endl;
		float newkm = change * 100 / ElectricVehicle::engineEfficiency;
		currentGasoline -= (newkm / 100) * GasolineVehicle::engineEfficiency;
	}
}
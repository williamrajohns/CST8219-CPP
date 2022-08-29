#include <iostream>
#include "Vehicle.h"

using namespace std;

//Vehicle::Vehicle(): Vehicle( 0, 0) { 
//
//}
Vehicle::Vehicle() : Vehicle(0, 1) {
	cout << "In constuctor with 0 parameters" << endl;
}

Vehicle::Vehicle(int w) : Vehicle(4, w) {
		cout << "In constuctor with 1 parameters, wheels = " << w << endl;
}
Vehicle::Vehicle(int d, int w) {
	numWheels = w;
	numDoors = d;
	cout << "In constuctor with 2 parameters, doors = " << d << " wheels = " << w << endl;
}

Vehicle::~Vehicle() {
	cout << "In destuctor" << endl;
}



Vehicle::Vehicle(Vehicle& copy) {
	cout << "In copy by reference constuctor " << endl;
	numDoors = copy.numDoors;
	numWheels = copy.numWheels;
}

Vehicle::Vehicle(Vehicle* copy) :Vehicle(copy->numDoors, copy->numWheels) {
	cout << "In copy by pointer constuctor " << endl;
}

void Vehicle::printVehicle(void) {
	cout << "wheels: " << numWheels << " doors: " << numDoors << endl;
}

	
	/*
	Vehicle::Vehicle() : Vehicle(4) {
		cout << "In constuctor with 0 parameters" << endl;
	}
	Vehicle::Vehicle(int w) : Vehicle(4, w) {

		cout << "In constuctor with 1 parameters, wheels = " << w << endl;
	}
	Vehicle::Vehicle(int d, int w) {
		numWheels = w;
		numDoors = d;
		cout << "In constuctor with 2 parameters, doors = " << d << " wheels = " << w << endl;
	}

	Vehicle::~Vehicle() {
		cout << "In destuctor" << endl;
	}
	*/

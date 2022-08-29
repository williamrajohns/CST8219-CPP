#include <iostream>
#include "Vehicle.h"

using namespace std;

//Vehicle::Vehicle(): Vehicle( 0, 0) { 
//
//}

Vehicle::Vehicle() : Vehicle(0, 1) {
	//cout << "In constuctor with 0 parameters" << endl;
}

Vehicle::Vehicle(int w) : Vehicle(4, w) {
	//	cout << "In constuctor with 1 parameters, wheels = " << w << endl;
}
Vehicle::Vehicle(int d, int w) {
	numWheels = w;
	numDoors = d;
//	cout << "In constuctor with 2 parameters, doors = " << d << " wheels = " << w << endl;
}

Vehicle::~Vehicle() {
	cout << "In Vehicle Destructor" << endl;   //Change ClassName to either Vehicle, Hybrid, Gasoline, Electric,
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
	cout << "pv: wheels: " << numWheels << " doors: " << numDoors << endl;
}


// ------ CODE FROM LAB 5 ------- 

//output operator
std::ostream& operator<<(std::ostream& output, const Vehicle& v)
{
	return cout << " wheels: " << v.numWheels << " doors: " << v.numDoors << endl;;
}


//copy
Vehicle& Vehicle::operator=(const Vehicle& v) {
	numWheels = v.numWheels;
	numDoors = v.numDoors;
	return *this;
}

//compare
bool operator==(const Vehicle& v1, const Vehicle& v2) {
	return (v1.numWheels == v2.numWheels && v1.numDoors == v2.numDoors); //true if it the condition is true	
}

//negation of compare
bool operator!=(const Vehicle& v1, const Vehicle& v2) {
	return !(v1==v2); //returns negation
}

//pre increment
Vehicle& Vehicle::operator++() {
	numDoors++;
	numWheels++;
	return *this;
}
//post increment
Vehicle& Vehicle::operator++(int) {
	Vehicle& temp(*this);
	++(*this);
	return temp;
}

//pre decrement
Vehicle& Vehicle::operator--() {
	numDoors--;
	numWheels--;
	return *this;
}
//post decrement
Vehicle& Vehicle::operator--(int) {
	Vehicle &temp(*this);
	--(*this);
	return temp;
}


// ----- lab6 -----

float Vehicle::calculateRange() {
	return 0;
}

float Vehicle::percentEnergyRemaining(){
	return 0;
}

void Vehicle::drive(float km) {
	return;
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

#pragma once

class Vehicle {
//private:
	int numWheels;
	int numDoors;
public:

	Vehicle();
	Vehicle(int w);
	Vehicle(int d, int w);
	~Vehicle();

	//Vehicle();
	Vehicle(Vehicle &);
	Vehicle(Vehicle*);
	void printVehicle(void);

/*
	Vehicle() : Vehicle(4) { }
	Vehicle(int w) : Vehicle(4, w) { }
	Vehicle(int d, int w) { }
	~Vehicle() { }
	*/


};

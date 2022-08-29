#pragma once

class Vehicle {

private:
	int numWheels;
	int numDoors;

public:
	float engineEfficiency = 0; //recheck this - set to 0 as default 

	Vehicle();
	Vehicle(int w);
	Vehicle(int d, int w);
	virtual ~Vehicle();

	//Vehicle();
	
	Vehicle(Vehicle &);
	Vehicle(Vehicle*);
	
	void printVehicle(void);

	// ----- Code for lab 5 -----
	//outstream
	friend std::ostream& operator<<(std::ostream& output, const Vehicle& v);

	//copy 
	Vehicle& operator=(const Vehicle& v);

	//equal/not equal
	friend bool operator==(const Vehicle& v1, const Vehicle& v2);
	friend bool operator!=(const Vehicle& v1, const Vehicle& v2);

	//increment, post then pre
	Vehicle& operator++(int);
	Vehicle& operator++();

	//decrement, post then pre
	Vehicle& operator--(int);
	Vehicle& operator--();

	virtual float calculateRange();
	virtual float percentEnergyRemaining();
	virtual void drive(float km);


/*
	Vehicle() : Vehicle(4) { }
	Vehicle(int w) : Vehicle(4, w) { }
	Vehicle(int d, int w) { }
	~Vehicle() { }
	*/


};

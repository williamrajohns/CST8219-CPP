
#include<iostream>
#include "Vehicle.h"
using namespace std;

void CreateVehicle(Vehicle& v, int w = 4, int d = 2) {
	Vehicle vehic (d, w);
	
};

int main(int argc, char** argv)
{

	Vehicle original;    //empty constructor no ( )

	Vehicle copy(original); // copy constructor by reference

	Vehicle secondCopy(&original); //copy constructor by pointer
	copy.printVehicle();
	CreateVehicle(copy, 2); //wheels is 2, everything else is default value
	copy.printVehicle();
	CreateVehicle(copy, 2, 3); //wheels is 2, doors is 3
	copy.printVehicle();
	copy = secondCopy;
	copy.printVehicle();	// copy is same as second copy
	return 0;
}

	/*
	Vehicle veh1;
	Vehicle veh2(4);
	Vehicle veh3(4, 2);

	Vehicle* pVehicle; 
	int w, d;
	int isCreated = 0;
	string whatDo = "a";


	do {
		cout << "What would you like to do? " << endl;
		cout << "To create new vehicle type: n " << endl;
		cout << "To quit type: q " << endl;
		cin >> whatDo;
		if (whatDo == "n") {
			if (isCreated == 1)
			{
				delete pVehicle;
				isCreated = 0;
			}
			cout << "Enter number of doors " << endl;
			while (!(cin >> d && d >  0)) {
				cout << "Not a valid number above 0 " << endl;
				cout << "Enter number of doors " << endl;
				cin.clear();
				cin.ignore(256, '\n');
			}

			cout << "Enter number of wheels " << endl;
			while (!(cin >> w && w > 0)) {
				cout << "Not a valid number above 0 " << endl;	\
				cout << "Enter number of wheels " << endl;
				cin.clear();
				cin.ignore(256, '\n');
			}
			
			pVehicle = new Vehicle(d, w);
			isCreated = 1;
		}
		else if (whatDo == "q") {
			if (isCreated == 1)
			{
				delete pVehicle;
			}
			break;
		}
		else {
			cout << "Not a valid input" << endl;
		}
		whatDo = "a";
	} while (whatDo != "q");

	cout << "I made a vehicle" << endl;
	
	cout << "Vehicle takes " << sizeof(veh1) << endl;
	cout << "Vehicle takes " << sizeof(veh2) << endl;
	cout << "Vehicle takes " << sizeof(veh3) << endl;
	cout << "isCreated takes " << sizeof(isCreated) << endl;
	cout << "d takes " << sizeof(d) << endl;
	cout << "w takes " << sizeof(w) << endl;
	cout << "pVehicle takes " << sizeof(Vehicle*) << endl;
	cout << "whatDo takes " << sizeof(whatDo) << endl;
	*/

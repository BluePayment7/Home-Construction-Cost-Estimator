//report implementation file
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
//header files
#include "report.h"
#include "conObj.h"

using namespace std;

//constructor
report::report(conObj material[]) //this cycles through every object in the conObj array passed to it to create a copy used as a private member of the report class
{
    int i = 0;
    while (material[i].getMaterialName() != "") {//go through the array unti there are no objects left in the array to process
        reportList[i] = material[i];//sets internal class list to that of the array passed to it
        i++;
    }
}

//setters
void report::clearList(conObj material[]) {//this funciton goes through all objects in the conObj array passed to it and sets them empty
    int i = 0;
    while (material[i].getMaterialName() != "") {
        material[i].setConObj("", 0, 0.00);
        i++;
    }
}

//getters
double report::getEstimation() {//calculates the total home construction cost 
    double estimation = 0;
    int i = 0;
    while (reportList[i].getMaterialName() != "") {
        estimation += reportList[i].getTotalPrice();//adds up each onject's total price
        i++;
    }
    return estimation;//returns the total cost estimation to be used elsewhere in the class (printers and getters)
}

//printers
void report::printReport() {//prints the report to the screen
    int i = 0;
    while (reportList[i].getMaterialName() != "") {
        reportList[i].printAll();//prints each object to the screen
        i++;
    }
    cout << fixed << showpoint << setprecision(2);//sets the precision of the estimation to two decimal places to better reflect money
    cout << "\nCost Estimation: $" << getEstimation() << endl << endl;
}

//savers
void report:: saveReport() {//saves the report to an external text file named "home_estimator_report"
    ofstream outData;//establishes an output stream called outData
    outData.open("home_estimator_report.txt");//this opens up the file to be written to
    int i = 0;
    while (reportList[i].getMaterialName() != "") {//as long as the object isn't empty
        outData << reportList[i].getDisplay() << endl;//output the data from the object to the outData data stream to be saved to the file
        i++;
    }
    outData << fixed << showpoint << setprecision(2);
    outData << "Total Home Construction Estimation: $" << getEstimation() << endl;
    outData.close();//need to close the output stream
}
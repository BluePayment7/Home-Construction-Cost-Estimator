#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "report.h"
#include "conObj.h"

using namespace std;

//constructor
report::report() {
    cout << "Initializing..." << endl;
}

report::report(conObj material[]) 
{
    int i = 0;
    while (material[i].getMaterialName() != "") {
        reportList[i] = material[i];
        i++;
    }
}

//setters
void report::clearList(conObj material[]) {
    int i = 0;
    while (material[i].getMaterialName() != "") {
        material[i].setConObj("", 0, 0.00);
        i++;
    }
}

//getters
double report::getEstimation() {
    double estimation = 0;
    int i = 0;
    while (reportList[i].getMaterialName() != "") {
        estimation += reportList[i].getTotalPrice();
        i++;
    }
    return estimation;
}

//printers
void report::printReport() {
    int i = 0;
    while (reportList[i].getMaterialName() != "") {
        reportList[i].printAll();
        i++;
    }
    cout << fixed << showpoint << setprecision(2);
    cout << "\nCost Estimation: $" << getEstimation() << endl << endl;
}

//savers
void report:: saveReport() {
    ofstream outData;
    outData.open("home_estimator_report.txt");
    int i = 0;
    while (reportList[i].getMaterialName() != "") {
        outData << reportList[i].getDisplay() << endl;
        i++;
    }
    outData << fixed << showpoint << setprecision(2);
    outData << "Total Home Construction Estimation: $" << getEstimation() << endl;
    outData.close();
}
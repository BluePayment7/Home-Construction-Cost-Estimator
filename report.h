//report class file
#ifndef report_H
#define report_H
//header files needed to use conObj class
#include "conObj.h"

using namespace std;
//This class is built from conObj class to create a private member that is a copy of whatever conObj object array is passed to it. 
//This report class will be used to print and save the report
class report : public conObj
{
    public:
        //constructor
        report(conObj material[]); //the constructor need to be initialized with a conObj object array as it uses the array to build it own array to use for reporting and saving functionality
        //setters
        void clearList(conObj material[]);//This takes in the conObj object array and sets all objects' members to empty
        //printers and savers
        void printReport();//prints the report to the screen
        void saveReport();//saves the report to a text file
        double getEstimation();//cycles through all the objects total cost and adds them up for the total cost estimation for the end of the report

    private:
        conObj reportList[500];//This conObj array holds the list of objects passed to it from the class constructor
};

#endif

//report
#ifndef report_H
#define report_H

#include "conObj.h"

using namespace std;

class report : public conObj
{
    public:
        //constructor
        report();
        report(conObj material[]);
        //setters
        void clearList(conObj material[]);
        //printers and savers
        void printReport();
        void saveReport();
        double getEstimation();
        

    private:
        conObj reportList[500];
};

#endif
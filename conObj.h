#ifndef conObj_H
#define conObj_H
#include <string>

using namespace std;

class conObj {
    public:
        //constructor
        conObj(string name = "", int quan = 0, double price = 0.0);
        //setters
        void setConObj(string name, int quan, double price);
        void setMaterialName(string name);
        void setQuantity(int quan);
        void setPrice(double price);
        //getters
        string getMaterialName();
        int getQuantity();
        double getPricePerUnit();
        string getDisplay();
        double getTotalPrice();
        // printers
        void printAll();
        void printMaterialName();
        void printQuantity();
        void printPricePerUnit();
        //savers

    private:
        string materialName;
        int quantity;
        double pricePerUnit;
        double totalPrice;
};

#endif
//conObj class
#ifndef conObj_H
#define conObj_H
//header files
#include <string>

using namespace std;

class conObj {//This class has four total variable members and 13 function members that do something with those variable members
    public:
        //constructor
        conObj(string name = "", int quan = 0, double price = 0.0);//constructor that takes three parameters and defaults
        //setters
        void setConObj(string name, int quan, double price);//takes in the name of the material, the quantity of the material, and the price per unit of the material.
        void setMaterialName(string name);//just sets the name of the material
        void setQuantity(int quan);//sets the quantity of the material
        void setPrice(double price);//sets the price of the material
        //getters
        string getMaterialName();//returns the name of the material
        int getQuantity();//returns the quantity of the material
        double getPricePerUnit();//returns the price per unit of the material
        string getDisplay();//returns the string display of all the material's information
        double getTotalPrice();//calculates the total price of the material by multiplying the quantity of the material by the price per unit of the material
        // printers
        void printAll();//prints the materials information to the screen.
        void printMaterialName();//prints the name of the material
        void printQuantity();//prints the quantity of the material
        void printPricePerUnit();//prints the price per unit of the material
        //savers

    private:
        string materialName; //string variable member to hold the name of the material
        int quantity;//integer variable member to hold the quantity of the material
        double pricePerUnit;//double variable member to hold the price per unit of the material
        double totalPrice;//double variable member to hold the total price of the material
};

#endif
//conObj Implementation File
#include <iostream>
#include <string>
//header files
#include "conObj.h"

using namespace std;

//constructor
conObj::conObj(string name, int quan, double price) {//constructor that sets the values of all member variables
    materialName = name;
    quantity = quan;
    pricePerUnit = price;
    totalPrice = pricePerUnit * quantity;
}

//setters
void conObj::setConObj(string name, int quan, double price) {//sets the values of all member variables
    materialName = name;
    quantity = quan;
    pricePerUnit = price;
    totalPrice = pricePerUnit * quantity;
}
void conObj::setMaterialName(string name) {//sets the name of the material
    materialName = name;
}
void conObj::setQuantity(int quan) {//sets the quantity of the material
    quantity = quan;
}
void conObj::setPrice(double price) {//sets the price per unit of the material
    pricePerUnit = price;
}

//getters
string conObj::getMaterialName() {//returns the name of the material
    return materialName;
}
int conObj::getQuantity() {//returns the quantity of the material
    return quantity;
}
double conObj::getPricePerUnit() {//returns the price per unit of the material
    return pricePerUnit;

}
string conObj::getDisplay() {//returns the display string of the material to show all information about the material object
    string temp = "*************************************************************************************************\n"
                  "Material Name: " +
                  materialName + "  Quantity: " + to_string(quantity) + "  Price per Unit: " + to_string(pricePerUnit) + "  Total Price: " + to_string(totalPrice);
    return temp;
}
double conObj::getTotalPrice() {//returns the total price for the member variable
    totalPrice = quantity * pricePerUnit;
    return totalPrice;
}

//printers
void conObj::printAll() {//prints to the screen all the material objects information
    cout << getDisplay() << endl;
}
void conObj::printMaterialName() {//prints to the screen the name of the material
    cout << getMaterialName() << endl;
}
void conObj::printQuantity() {//prints to the screen the quantity of the material
    cout << getQuantity() << endl;
}
void conObj::printPricePerUnit() {//prints to the screen the price per unit of the material
    cout << getPricePerUnit() << endl;
}
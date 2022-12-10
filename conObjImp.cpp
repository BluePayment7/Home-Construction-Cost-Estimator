#include <iostream>
#include <string>

#include "conObj.h"

using namespace std;



//setters
void conObj::setConObj(string name, int quan, double price) {
    materialName = name;
    quantity = quan;
    pricePerUnit = price;
    totalPrice = pricePerUnit * quantity;
}
void conObj::setMaterialName(string name) {
    materialName = name;
}
void conObj::setQuantity(int quan) {
    quantity = quan;
}
void conObj::setPrice(double price) {
    pricePerUnit = price;
}

//getters
string conObj::getMaterialName() {
    return materialName;
}
int conObj::getQuantity() {
    return quantity;
}
double conObj::getPricePerUnit() {
    return pricePerUnit;

}
string conObj::getDisplay() {
    string temp = "*************************************************************************************************\n"
                  "Material Name: " +
                  materialName + "  Quantity: " + to_string(quantity) + "  Price per Unit: " + to_string(pricePerUnit) + "  Total Price: " + to_string(totalPrice);
    return temp;
}
double conObj::getTotalPrice() {
    totalPrice = quantity * pricePerUnit;
    return totalPrice;
}

//printers
void conObj::printAll() {
    cout << getDisplay() << endl;
}
void conObj::printMaterialName() {
    cout << getMaterialName() << endl;
}
void conObj::printQuantity() {
    cout << getQuantity() << endl;
}
void conObj::printPricePerUnit() {
    cout << getPricePerUnit() << endl;
}

//savers

//constructor
conObj::conObj(string name, int quan, double price) {
    materialName = name;
    quantity = quan;
    pricePerUnit = price;
    totalPrice = pricePerUnit * quantity;
}
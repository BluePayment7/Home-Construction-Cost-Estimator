/*
Unionize the Devs! Final Project
Members: Jacob Weldon, Amanda Cordray, Kyle Nguyen, Brayden Steffen
Title: Home Construction Cost Estimator
https://github.com/BluePayment7/Home-Construction-Cost-Estimator
 */

/* 
This program runs on a desktop computer from the terminal and provides a material cost estimate reporting tool that can output to the terminal directly, 
or have it saved as a home_estimator_report.txt file. The program will prompt the client to add in the name, quantity, and unit price for each material 
that will be a part of the estimation. Once all items have been entered into the program, the client will see the report printed to the screen and a backup 
text file will be saved of that estimation. 
The program starts by displaying the main menu of choices. There are 6 choices in total.
Enter 1 to add material
Enter 2 to print report to screen
Enter 3 to save report to the text file home_estimator_report.txt
Enter 4 to clear material list
Enter 5 to view list of common construction materials
Enter 9 to terminate the program
*/

//header files
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>

//class header files
#include "conObjImp.cpp"
#include "reportImp.cpp"

using namespace std;
//Initializing List of Construction Objects
conObj materialList[500];

//function prototype declarations
int welcome();
void menu(int);
void enterInfo();
void exampleFile();

int count = 0;//to index array for object storage

int main() {
    int sel = welcome();
    menu(sel);
    return 0;
}
//welcome function that will print the menu to the screen and allow for user selection. It returns the number of the user's choice
int welcome() {
    report repList(materialList);//Builds the report object in order to use the funciton getEstimation() to provide total display above the menu
    cout << "\n\t\t\tCurrent Home Construction Cost Estimation: $" << repList.getEstimation() << endl;//displays the current total cost estimate
    string temp = "*************************************************************************************************"//Menu Display
                  "\nThis is the Home Construction Estimator Program."
                  "\nSimply select from the Menu below to begin building your Bill of Materials(BOM)."
                  "\nEnter 1 to add in a material name, then a material quantity, then a material price per unit."
                  "\nEnter 2 to print the report to the screen."
                  "\nEnter 3 to save the report to a text file."
                  "\nEnter 4 to reset the program and start again with an empty material list."
                  "\nEnter 5 to see a list of common construction materials."
                  "\nEnter 9 to terminate the program."
                  "\n*************************************************************************************************";
    cout << temp << endl;//print menu to screen
    int num;//initializing number variable to store user's menu choice
    cin >> num;//puts user's choice into the variable
    if (num == 9)
    { // if the user selects number 9 terminate the program
        exit(0);
    }
    if (num != 1 && num != 2 && num != 3 && num != 4 && num != 5) {
        welcome();//if the user enters an invalid number, call the function again to allow an appropriate choice
    }
    return num;//returns the number of the user's choice
}
//menu function takes in the user's choice and uses if statements to call the appropriate function
void menu(int num) {
    report repList(materialList);//initializes the report list using the list of construction objects
    if (num == 1) {//choice one calls the function enterInfo() to allow the user to enter in an item
        enterInfo();
    }
    else if (num == 2)//choice two calls the printReport() member function of the report object to print the report to the screen
    {
        repList.printReport();
    }
    else if (num == 3)//choice three saves the report to a text file
    {
        repList.saveReport();
    }
    else if (num == 4) {
        repList.clearList(materialList);//choice four clears the list so the user can start again
        count = 0;
    }
    else if (num == 5)
    {
        exampleFile();
    }
    else
    {
        cout << "Error in menu selection" << endl;//In case there was an error during programming...
    }
    main();//calls the main function again to start the program from the top again to allow for menu access
}
//function that takes in information for the user and initilizes conObj objects and stores them in materialList[]
void enterInfo() {
    string name;//material name
    int quan;//material quantity
    double price;//material price
    
    //The following while loop is to cycle and add materials to materialList until the user types anything other than y
    char choice = 'y';
    while (choice == 'y') {
        cout << "Please enter in the name of the construction material(item cannot contain spaces and must start with a letter): ";
        cin >> name;
        cout << "Please enter in the quantity needed: #";
        cin >> quan;
        cout << "Please enter in the price per unit of material: $";
        cin >> price;
        materialList[count].setConObj(name, quan, price);//This constructs the object at index i
        cout << materialList[count].getDisplay();//prints to the screen the information the user just entered
        count++;//increments the count of materials added to the object array materialList[]
        cout << "\nEnter another item? (current " << count << "/500) y/n: ";//allows the user to enter in more items or go back to the menu
        cin >> choice;//user enters their choice
    }
    main();//takes the user back the main menu
}

void exampleFile() {
//read from file and output to the screen a list of common materials and their associated price per unit 
    string line;//cin variables
    ifstream inData;// open input data stream
    inData.open("common_materials.txt");//open text file
    if (inData.is_open()) {//checks to make sure that the input scream is open
        while (inData.peek() != EOF) {//make sure to continue printing until reaching the end of the file
            getline(inData, line);//gets the line from inData
            cout << line << endl;//prints line to console. 
        }
    }
    inData.close();
}
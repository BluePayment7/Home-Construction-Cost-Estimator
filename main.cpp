/*
Unionize the Devs! Final Project
Members: Jacob Weldon, Amanda Cordray, Kyle Nguyen, Brayden Steffen
Title: Home Construction Cost Estimator
 */
/* Solution Requirements
3. Use at least two files in your application
6. Validation testing
    -Develop an appropriate set of test data to fully validate the program against
    -The data sets you tested against
    -A brief written explanation of the results of your tests and what you had to fix
    -Screen shots of your good test data working
7. User manual
    -You will write and submit a User's Manual for your final project and submit it according to the instructions in the attached file.
8. Documentation of the source code
    -You will fully document (comment) the C++ source code with appropriate comments including:
        -A brief explanation of the purpose of each moduel (Sub) at the beginning of each Sub. (A header's comment)
        -Explanation of the purpose of each variable where it is declared. (An end line comment)
        -Line by line, or at least section by section comments within the code, explaining wha the line/section does.
https://github.com/BluePayment7/Home-Construction-Cost-Estimator

Main Menu (Enter Material Info, Print Report to Terminal, Save to Text File, Exit Program)
Enter Material Info (string materialName, int quantity, double unitPrice)
	Runs setMaterial(str…,int…,double…)
	Print Report to Terminal(class Materials[])
		Outputs all materials entered, their total cost, and total estimate
	Save to Text File(class Materials[])
		Saves all information and estimates to a text file
	Exit Program(0)


The program will ask for inputs:
the material name
the quantity of the material
the unit price
The program will output:
 a table displaying all the entered information
save the information to a file
calculate the total estimated cost
display the total estimated cost
Additional features will be added as the project progresses
*/
/* Upload a zip file of your Group Project, please name the Group Project folder 'GPSolution.zip' (65 points)
Validation testing (10 points)
User manual creation (10 points)
Documentation of source code (10 points)
The link to the GitHub repository for Group Project (5 points) */
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
                  "\nEnter 9 to terminate the program."
                  "\n*************************************************************************************************";
    cout << temp << endl;//print menu to screen
    int num;//initializing number variable to store user's menu choice
    cin >> num;//puts user's choice into the variable
    if (num == 9)
    { // if the user selects number 9 terminate the program
        exit(0);
    }
    if (num != 1 && num != 2 && num != 3 && num != 4) {
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
    } else
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
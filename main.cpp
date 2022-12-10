/* Solution Requirements
1. A working application using at least two classes
2. Implementing a modular approach by using functions
3. Use at least two files in your application
4. Include the usage of at least two arrays
5. Implement secure coding best practices
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
9. The link of the GitHub repository for your final project

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
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>


#include "conObjImp.cpp"
#include "reportImp.cpp"

using namespace std;

conObj materialList[500];


int welcome();
void menu(int);
void enterInfo();

int count = 0;//to index array for object storage

int main() {
    
    int sel = welcome();
    menu(sel);
    return 0;
}

int welcome() {
    report repList(materialList);
    cout << "\n\t\t\tCurrent Home Construction Cost Estimation: $" << repList.getEstimation() << endl;
    string temp = "*************************************************************************************************"
                  "\nThis is the Home Construction Estimator Program."
                  "\nSimply select from the Menu below to begin building your Bill of Materials(BOM)."
                  "\nEnter 1 to add in a material name, then a material quantity, then a material price per unit."
                  "\nEnter 2 to print the report to the screen."
                  "\nEnter 3 to save the report to a text file."
                  "\nEnter 4 to reset the program and start again with an empty material list."
                  "\nEnter 9 to terminate the program."
                  "\n*************************************************************************************************";
    cout << temp << endl;
    int num;
    cin >> num;
    if (num == 9) {
        exit(0);
    }
    if (num != 1 && num != 2 && num != 3 && num != 4) {
        welcome();
    }
    return num;
}

void menu(int num) {
    report repList(materialList);
    if (num == 1) {
        enterInfo();
    }
    else if (num == 2)
    {
        repList.printReport();
    }
    else if (num == 3)
    {
        repList.saveReport();
    }
    else if (num == 4) {
        repList.clearList(materialList);
    } else
    {
        cout << "Error in menu selection" << endl;
    }
    main();
}

void enterInfo() {
    string name;//material name
    int quan;//material quantity
    double price;//material price
    
    //The following while loop is to cycle and add materials to materialList until the user types anything other than y
    char choice = 'y';
    while (choice == 'y') {
        cout << "Please enter in the name of the construction material(item cannot contain spaces and must start with a letter): ";
        cin >> name;
        /* for (int l = 0; l < name.length(); l++) {
            if (name[l] == ' ') {
                name[l] = '_';
            }
        } */
        cout << "Please enter in the quantity needed: #";
        cin >> quan;
        cout << "Please enter in the price per unit of material: $";
        cin >> price;
        materialList[count].setConObj(name, quan, price);//This constructs the object
        cout << materialList[count].getDisplay();
        count++;
        cout << "\nEnter another item? (current " << count << "/500) y/n: ";
        cin >> choice;
    }
    main();
}
















/* Upload a zip file of your Group Project, please name the Group Project folder 'GPSolution.zip' (65 points)
Validation testing (10 points)
User manual creation (10 points)
Documentation of source code (10 points)
The link to the GitHub repository for Group Project (5 points) */
/* Project: GPA Calculator for US universities
Developer: Aditya Deshmukh */

#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_map>

using namespace std;

void GPA();
void CGPA();
void mapping();

int main(){
        // system("cls"); // Use for Windows
        system("clear"); // Use for Unix/Linux based systems
        cout << "\n\n";

        int input;
        cout << "Select the task you wish to carry out? (1-4)\n";
        cout << "1. Calculate Term GPA\n";
        cout << "2. Calculate Overall CGPA\n";
        cout << "3. See Grade-Point mapping\n";
        cout << "4. Exit Application\n";

        cin >> input;

        switch (input)
        {
        case 1:
                GPA();
                break;
        
        case 2:
                CGPA();
                break;
        case 3:
                mapping();
                break;
        case 4:
                cout << "\nExiting Application";
                exit(EXIT_SUCCESS);
        default:
                cout << "\nInvalid input. Try again";
                main();
        }
        
        return 0;
}

// Function to calculate term or semester GPA
void GPA(){
        // system("cls"); // Use for Windows
        system("clear"); // Use for Unix/Linux based systems
        cout << "\n\n";

        int count;

        unordered_map<string, float> mapping;
        mapping["A+"] = 4.33;
        mapping["A"] = 4.00;
        mapping["A-"] = 3.67;
        mapping["B+"] = 3.33;
        mapping["B"] = 3.00;
        mapping["B-"] = 2.67;
        mapping["C+"] = 2.33;
        mapping["C"] = 2.00;
        mapping["D"] = 1.00;
        mapping["E"] = 0.00;

        cout << "Enter the number of subjects in this semester: \n";
        cin >> count;
        
        if (count <= 0){
                cout << "\nEnter at least one subject. Try again!";
                GPA();
        }

        float subjectPoint[count];
        int subjectCredit[count]; 

        string subjectGrade;
        for (int i=0; i<count; i++){
                cout << "\nGrade in subject " << i+1 <<":";
                cin >> subjectGrade;
                
                transform(subjectGrade.begin(), subjectGrade.end(), subjectGrade.begin(), ::toupper); 
                
                if (mapping.find(subjectGrade) == mapping.end()){
                        cout << "\nInvalid grade entered. Refer mapping section for list of valid grades and try again!";
                        GPA();
                }

                subjectPoint[i] = mapping[subjectGrade];
                        
                cout << "\nCredit for subject " << i+1 <<":";
                cin >> subjectCredit[i];

                if (subjectCredit[i] < 0){
                        cout << "\nCredit cannot be less than zero. Try again!";
                        GPA();
                }
        }

        float gpa;
        float totalPoints = 0;
        int totalCredits = 0;

        for (int i=0; i<count; i++){
                totalPoints += subjectPoint[i] * subjectCredit[i];
                totalCredits += subjectCredit[i];
        }

        if (totalCredits == 0){
                gpa = 0;
        }
        else{
                gpa = totalPoints/totalCredits;
        }

        cout << "\nYour GPA for this semester is: " << gpa;

        // Menu Options
        int menu;
        cout << "\n\n\n";
        cout << "What do you wish to do? (1-3)\n";
        cout << "1. Return to main menu\n";
        cout << "2. Calculate Term GPA again\n";
        cout << "3. Exit Application\n";

        cin >> menu;

        switch (menu)
        {
        case 1:
                main();
                break;
        
        case 2:
                GPA();
                break;
        case 3:
                cout << "\nExiting Application";
                exit(EXIT_SUCCESS);
        default:
                cout << "\nInvalid input. Try again";
                GPA();
        }
}

// Function to calculate overall GPA (CGPA) 
void CGPA(){
        // system("cls"); // Use for Windows
        system("clear"); // Use for Unix/Linux based systems
        cout << "\n\n";
        
        int sems;
        float semGPA;
        float gpaSum = 0;

        cout << "\nEnter the total number of semester(s): ";
        cin >> sems;

        if (sems <= 0){
                cout << "\nYou need to have minimum one semester to check your CGPA.";
                CGPA();
        }

        for (int i=0; i<sems; i++){
                cout << "\nEnter the GPA for semester " << i+1 <<": ";
                cin >> semGPA;
                if (semGPA < 0){
                        cout << "\nSemester GPA cannot be less than zero. Try again!";
                        CGPA();
                }
                gpaSum += semGPA;
        }

        float cgpa;
        cgpa = gpaSum/sems;

        cout << "\nYour CGPA is: " << cgpa; 

        // Menu Options
        int menu;
        cout << "\n\n\n";
        cout << "What do you wish to do? (1-3)\n";
        cout << "1. Return to main menu\n";
        cout << "2. Calculate Overall CGPA again\n";
        cout << "3. Exit Application\n";

        cin >> menu;

        switch (menu)
        {
        case 1:
                main();
                break;
        
        case 2:
                CGPA();
                break;
        case 3:
                cout << "\nExiting Application";
                exit(EXIT_SUCCESS);
        default:
                cout << "\nInvalid input. Start again";
                CGPA();
        }
}

void mapping(){
        // system("cls"); // Use for Windows
        system("clear"); // Use for Unix/Linux based systems
        cout << "\n\n";

        cout << " Grade | Points \n";
        cout << " -------------- \n";
        cout << "  A+   |  4.33  \n";
        cout << "  A    |  4.00  \n";
        cout << "  A-   |  3.67  \n";
        cout << "  B+   |  3.33  \n";
        cout << "  B    |  3.00  \n";
        cout << "  B-   |  2.67  \n";
        cout << "  C+   |  2.33  \n";
        cout << "  C    |  2.00  \n";
        cout << "  D    |  1.00  \n";
        cout << "  E    |  0.00  \n";

        int menu;
        cout << "\n\n\n";
        cout << "What do you wish to do? (1-2)\n";
        cout << "1. Return to main menu\n";
        cout << "2. Exit Application\n";

        cin >> menu;

        switch (menu)
        {
        case 1:
                main();
                break;
        case 2:
                cout << "\nExiting Application";
                exit(EXIT_SUCCESS);
        default:
                cout << "\nInvalid input. Start again";
                mapping();
        }
}
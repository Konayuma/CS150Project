#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

// Variables
int option;
string Nrc;
double Deduction;

// Prototypes
void Manager();
void Human_Resource();
void Employee();
void New_employee();

struct add_Employee {
    string NRC;
    string Name;
    string Surname;
    int Age;
    double Basic_salary;
    string Department;
    double Tax_Amount;
    double NAPSA;
    double NHIMA;
    double Net_Pay;
    string Employment_Status;
};

void New_employee()
{
    add_Employee Details[100];
    for(int i = 1; i < 2; i++)
    {
        cout << "\t\t\t\tEnter NRC No/Passport No: ";
        cin.ignore();
        getline(cin, Details[i].NRC);
        
        cout << "\t\t\t\tEnter Your Name: ";
        getline(cin, Details[i].Name);
        
        cout << "\t\t\t\tEnter your Surname: ";
        getline(cin, Details[i].Surname);
        
        cout << "\t\t\t\tEnter Age: ";
        cin >> Details[i].Age;
        
        cout << "\t\t\t\tEnter Basic Salary: ";
        cin >> Details[i].Basic_salary;
        cin.ignore(); // Ignore the newline after the last input
        
        cout << "\t\t\t\tEnter Department: ";
        getline(cin, Details[i].Department);
        
        cout << "\t\t\t\tEnter Tax Percentage: ";
        cin >> Details[i].Tax_Amount;
        Details[i].Tax_Amount = (Details[i].Tax_Amount /100) * Details[i].Basic_salary;
        
        cout << "\t\t\t\tEnter NAPSA Percentage: ";
        cin >> Details[i].NAPSA;
        Details[i].NAPSA = (Details[i].NAPSA /100) * Details[i].Basic_salary;
        
        cout << "\t\t\t\tEnter NHIMA Percentage: ";
        cin >> Details[i].NHIMA;
        Details[i].NHIMA = (Details[i].NHIMA /100) * Details[i].Basic_salary;

        Details[i].Net_Pay = Details[i].Basic_salary - (Details[i].Tax_Amount + Details[i].NAPSA + Details[i].NHIMA); //Difference between the basic salary and the deductions, which have been added 

        cin.ignore(); // Ignore the newline after the last input
        cout << "\t\t\t\tEnter Employment Status: ";
        getline(cin, Details[i].Employment_Status);
    }

    fstream details;
    details.open("New Employee.txt", ios::app);
    details << "\t NRC No/ PASSPORT No \t First Name \t Surname \t Age\t Basic Salary\t Department \t Tax Amount(PAYE) \t NAPSA Contribution \t NHIMA \t Net Pay \t Employmnet Status \n";
    for (int i = 1; i < 2; i++)
    {
        details << "\t " << Details[i].NRC;
        details << "\t " << Details[i].Name;
        details << "\t\t " << Details[i].Surname;
        details << "\t\t " << Details[i].Age;
        details << "\t\t " << Details[i].Basic_salary;
        details << "\t\t " << Details[i].Department;
        details << "\t\t " << Details[i].Tax_Amount;
        details << "\t\t " << Details[i].NAPSA;
        details << "\t\t " << Details[i].NHIMA;
        details << "\t\t " << Details[i].Net_Pay;
        details << "\t\t " << Details[i].Employment_Status << endl;
    }
}

void Hi_Header()
{
    system("cls");
    Sleep(100);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t *\t*\t*"<<endl;
    Sleep(100);
    cout << "\t\t\t\t\t *\t*\t*"<<endl;
    Sleep(100);
    cout << "\t\t\t\t\t ********\t*"<<endl;
    Sleep(100);
    cout << "\t\t\t\t\t *\t*\t*"<<endl;
    Sleep(100);
    cout << "\t\t\t\t\t *\t*\t*"<<endl;
    Sleep(100);
    system("cls");
}

void Welcome()
{

    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t\tLoading ";
    Sleep(100);
    cout << ".";
    Sleep(100);
    cout << ".";
    Sleep(100);
    cout << ".";
    Sleep(100);
    cout << ".";
    Sleep(100);
    cout << ".";
    system("cls");
    Sleep(100);
    cout << "\t\t\t\t\t#########################################################\t\t\t"<<endl;
    cout << "\t\t\t\t\t#                                                       #\t\t\t"<<endl;
    cout << "\t\t\t\t\t#                                                       #\t\t\t"<<endl;
    cout << "\t\t\t\t\t#                                                       #\t\t\t"<<endl;
    cout << "\t\t\t\t\t#                                                       #\t\t\t"<<endl;
    cout << "\t\t\t\t\t#                                                       #\t\t\t"<<endl;
    cout << "\t\t\t\t\t#                        WELCOME                        #\t\t\t"<<endl;
    cout << "\t\t\t\t\t#                          TO                           #\t\t\t"<<endl;
    cout << "\t\t\t\t\t#                         Z-HUB                         #\t\t\t"<<endl;
    cout << "\t\t\t\t\t#                       INNOVATION                      #\t\t\t"<<endl;
    cout << "\t\t\t\t\t#                                                       #\t\t\t"<<endl;
    cout << "\t\t\t\t\t#                                                       #\t\t\t"<<endl;
    cout << "\t\t\t\t\t#                                                       #\t\t\t"<<endl;
    cout << "\t\t\t\t\t#                                                       #\t\t\t"<<endl;
    cout << "\t\t\t\t\t#########################################################\t\t\t"<<endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t Please Wait";
    Sleep(100);
    cout << ".";
    Sleep(100);
    cout << ".";
    Sleep(100);
    cout << ".";
    Sleep(100);
    cout << ".";
    Sleep(100);
    cout << ".";
    system("cls");
}


void Login()
{
    cout << "\t\t\t\t----------------------------------------------------"<<endl;
    cout << endl;
    cout << "\t\t\t\t 1. Innovation Hub Manager \n";
    cout << endl;
    cout << "\t\t\t\t 2. Human Resource Officer \n";
    cout << endl;
    cout << "\t\t\t\t 3. Employees \n";
    cout << endl;
    cout << "\t\t\t\tEnter the Option: ";
    cin >> option;
    switch (option)
    {
    case 1:
        system("cls");
        Manager();
        break;
    case 2:
        system("cls");
        Human_Resource();
        break;
    case 3:
        system("cls");
        Employee();
        break;

    }
}

void Manager()
{
    cout << endl;
    cout << "\t\t\t\t 1. Add Employee Record\n";
    cout << "\t\t\t\t 2. Delete Employee Record\n";
    cout << "\t\t\t\t 3. Search for Employee\n";
    cout << "\t\t\t\t 4. Edit Employee Record\n";
    cout << "\t\t\t\t 5. Display Employees by Department\n";
    cout << "\t\t\t\t 6. Exit\n";
    cout << endl;
    cout << "\t\t\t\t Enter Option: ";
    cin >> option;
    switch(option)
    {
    case 1:
        system("cls");
        New_employee();
        break;
    }

}
void Human_Resource()
{
    cout << endl;
    cout << "\t\t\t\t 1. Add Employee Record\n";
    cout << "\t\t\t\t 2. Delete Employee Record\n";
    cout << "\t\t\t\t 3. Search for Employee\n";
    cout << "\t\t\t\t 4. Edit Employee Record\n";
    cout << "\t\t\t\t 5. Display Employees by Department\n";
    cout << "\t\t\t\t 6. Exit\n";
}
void Employee()
{
    cout << endl;
    cout << "\t\t\t\t 1. Add Employee Record\n";
    cout << "\t\t\t\t 2. Delete Employee Record\n";
    cout << "\t\t\t\t 3. Search for Employee\n";
    cout << "\t\t\t\t 4. Edit Employee Record\n";
    cout << "\t\t\t\t 5. Display Employees by Department\n";
    cout << "\t\t\t\t 6. Exit\n";

}



int main()
{

    Hi_Header();
    Welcome();
    Login();
    return 0;
}
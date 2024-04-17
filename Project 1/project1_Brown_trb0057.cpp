//Thomas Brown trb0057 /home/u1/trb0057/comp/project1_Brown_trb0057.cpp
//How to compile- program will ask for Loan, rate, and monthly Rate, then will generate everything
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <cmath>

using namespace std;

double totalInterest;
int totalMonths;
//Genertates the heading and the first line of the table
void heading(double loan, double rate, double monthlyPayment) {
    stringstream header;
    header << "\n\nLoan Ammount: " << loan << "\nInterest Rate(Yearly): " << rate << "\nMonthly Payments: " << monthlyPayment;
    string asterisks = "\n************************************************************\n";
    header << asterisks << "         Amortization Table" << asterisks;
    header << "Month    Balance    Payment    Rate    Interest    Principal\n";
    cout << header.str();
    cout << "0        " << loan << "     N/A        N/A     N/A         N/A" << endl;
}
//Generates the table of values
void generateTable(double loan, double rate, double monthlyPayment) {
    double monthlyRate = rate / 12;
    totalMonths = 1;
    totalInterest = 0;
    while(loan > 0) {
        double interest = loan * monthlyRate / 100;
        if(interest > monthlyPayment) {
            cout << "ERROR: Insufficent Payment" << endl;
            exit(0);
        }
        loan = loan - (monthlyPayment - interest);
        if(loan < 0) {
            monthlyPayment = monthlyPayment + loan;
            loan = 0;
        }
        cout << fixed << setprecision(2);
        cout << left << setw(9) << totalMonths << left << setw(11) << loan << setw(11) << monthlyPayment
        << left << setw(8) << monthlyRate
        <<left << setw(12) << interest << left << monthlyPayment - interest << endl;
        totalInterest += interest;
        if(loan != 0)
            totalMonths++;
    }
}
//Prints the footing
void footing(double loan, double rate, double monthlyPayment) {
    string asterisks = "************************************************************\n";
    cout << asterisks << "It takes " << totalMonths << " months to pay off the loan.\n";
    cout << fixed << setprecision(2);
    cout << "Total interest paid is: $" << totalInterest << endl;
}
//Makes sure that only integer inputs are accepted
void getInput(double &variable, const string &prompt) {
    cout << prompt;
    cin >> variable;

    if (variable < 0 || cin.fail() || floor(variable) != variable) {
        cout << "ERROR Invalid input" << endl;
        exit(0);
    }
}

int main() {
    double loan;
    double rate;
    double monthlyPayment;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    getInput(loan, "\nLoan Amount: ");
    getInput(rate, "Interest Rate (% per year): ");
    getInput(monthlyPayment, "Monthly Payments: ");
    heading(loan, rate, monthlyPayment);
    generateTable(loan, rate, monthlyPayment);
    footing(loan, rate, monthlyPayment);
}
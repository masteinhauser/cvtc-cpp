/* 
 * File: main.cpp
 * Desc: Calculate monthly mortgage payments for two different loan options.
 * Auth: Myles A. K. Steinhauser
 *
 * Created on October 31, 2012, 6:01 PM
 */

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include "payment.h"
#include "loan.h"

using namespace std;

bool validateLoan(Loan& loan) {
    if (loan.principal >= 0 && loan.interestRate >= 0 && loan.months >= 0) {
        return true;
    }

    // Default:
    return false;
}

int getLoanInfo(Loan& loan) {
    string input;

    // Store loan principal
    cout << "Please enter the principal of the loan: $";
    getline(cin, input);
    loan.principal = atof(input.c_str());

    // Store Interest Rate
    cout << "Please enter the yearly interest rate: ";
    getline(cin, input);
    loan.interestRate = atof(input.c_str());

    // Store length of loan
    cout << "Please enter the length of the loan in months: ";
    getline(cin, input);
    loan.months = atof(input.c_str());

    // Confirm the loan actually makes sense
    bool loanValid = false;
    loanValid = validateLoan(loan);

    if (loanValid) {
        // Let the calling function know we successfully completed.
        return 0;
    } else {
        // Loan is not valid.
        return 1;
    }
}

int calculatePayment(Loan& loan, Payment& loanPayment) {
    // Formula: M = P * ( J / (1 - (1 + J) ^ -N)).
    // M: Monthly Payment
    // P: Principal
    // J: Monthly interest
    // N: Loan length in months

    long double payment = 0;
    long double interest = 0;

    // Formula from: http://en.wikipedia.org/wiki/Mortgage_calculator#Monthly_payment_formula
    payment = ((loan.interestRate / 100 / 12) * loan.principal) / (1 - (pow(1 + (loan.interestRate / 100 / 12), -loan.months)));

    // Forumla from: http://www.wisegeek.com/how-do-i-calculate-mortgage-interest.htm
    interest = (payment * loan.months) - loan.principal;

    // Assign our calculated payment value so the calling code can use it.
    loanPayment.amount = payment;
    loanPayment.interest = interest / loan.months;
    loan.interest = interest;

    // Let the calling function know we successfully completed.
    return 0;
}

int showLoanPayment(Loan& loan, Payment& payment) {
    cout.precision(2);
    cout << fixed << "Monthly Payment: $" << payment.amount << endl;
    cout << fixed << "Average Monthly Interest: $" << payment.interest << endl;
    cout << fixed << "Total Payments: $" << (payment.amount * loan.months) << endl;
    cout << fixed << "Total Interest: $" << loan.interest << endl;

    return 0;
}

int showLoanAnalysis(int numLoans, Loan loans[], Payment payments[]) {
    int lowestMonthlyPayment = 0;
    int lowestTotalInterest = 0;

    for (int i = 0; i < numLoans; i++) {
        if(payments[i].amount < payments[lowestMonthlyPayment].amount){
            lowestMonthlyPayment = i;
        }
        if(loans[i].interest < loans[lowestTotalInterest].interest){
            lowestTotalInterest = i;
        }
    }

    cout.precision(2);
    cout << fixed << "Loan #" << (lowestMonthlyPayment + 1) << " had the lowest monthly payment at $" << payments[lowestMonthlyPayment].amount << endl;
    cout << fixed << "Loan #" << (lowestTotalInterest + 1) << " had the lowest total interest at $" << loans[lowestTotalInterest].interest << endl;
}

/*
 * 
 */
int main(int argc, char** argv) {
    string input;
    int numLoans = 0;

    // Find how many loans to compare
    cout << "Please enter how many loans you would like to compare: ";
    getline(cin, input);
    numLoans = atof(input.c_str());

    Loan loan[numLoans];
    Payment payment[numLoans];
    
    for (int i = 0; i < numLoans; i++) {
        // Get input from user
        getLoanInfo(loan[i]);

        // Calculate monthly payment
        calculatePayment(loan[i], payment[i]);
    }

    cout << endl << endl;
    cout << "Loan information:" << endl;
    for (int i = 0; i < numLoans; i++) {
        cout << "Loan #" << (i + 1) << endl;
        // Output monthly payment
        showLoanPayment(loan[i], payment[i]);
        cout << "\t\t---\t\t" << endl;
    }
    
    cout << "Loan analysis:" << endl;
    showLoanAnalysis(numLoans, loan, payment);

    return 0;
}


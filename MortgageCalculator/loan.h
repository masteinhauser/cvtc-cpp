/* 
 * File: loan.h
 * Desc: 
 * Auth: Myles A. K. Steinhauser
 *
 * Created on October 31, 2012, 6:27 PM
 */

#ifndef LOAN_H
#define	LOAN_H

struct Loan {
    // Amount of each payment
    double principal;
    
    // Amount of interest in the loan
    double interest;
    
    // Interest rate for the loan.
    float interestRate;
    
    // Number of months in the loan
    float months;
};

#endif	/* LOAN_H */


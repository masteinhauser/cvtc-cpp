/* 
 * File: payment.h
 * Desc: Base payment and rate information.
 * Auth: Myles A. K. Steinhauser
 *
 * Created on October 31, 2012, 6:16 PM
 */

#ifndef PAYMENT_H
#define	PAYMENT_H

struct Payment {
    // Amount of each payment
    double amount;
    
    // Amount of interest in above the actual base amount
    double interest;
    
    // Number of months in the payment
    float months;
};

#endif	/* PAYMENT_H */


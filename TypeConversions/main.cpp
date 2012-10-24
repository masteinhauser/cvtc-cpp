/* 
 * File: main.cpp
 * Desc: 
 * Auth: Myles A. K. Steinhauser
 *
 * Created on October 23, 2012, 8:25 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    // Implicit type conversion
    // Uses type of most precise number
    cout << (3 / 2) << endl; // implicitly using integer division
    cout << (3.0 / 2) << endl; // implicitly casts to a double

    double d = 5.6;
    int i = (int) d; // explicit type conversion via integer cast

    int age;
    cout << "Please enter an age: ";
    cin >> age;

    if (age < 18) {
        cout << "You are a Minor";
    } else if (age <= 50) {
        cout << "You are an Adult";
    } else {
        cout << "You are an Experienced Adult";
    }

    return 0;
}


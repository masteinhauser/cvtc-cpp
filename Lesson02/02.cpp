/* 
 * File: 02.cpp
 * Desc: Illustrate how to declare data types and ADTs in C++.
 * Auth: Myles A. K. Steinhauser
 *
 * Created on October 23, 2012, 7:46 PM
 */

#include <cstdlib>
#include <iostream>
#include "animal.h"

using namespace std;

/*
 * App entry point on execution
 */
int main(int argc, char** argv) {
    // three primitive declarations
    // Primitives are NOT automatically initialized
    int age = 56;
    float temp = 6.3f; // 'f' for single precision float literal
    double wage = 10.5; // 'number' assumed to double
    
    //cout << "age: " << age << endl;
    
    // Complex ADT declaration
    Animal animal;
    
    cout << "Please enter the species: ";
    getline(cin, animal.species);
    
    cout << "Please enter the age in years: ";
    cin >> animal.age;
    
    // Increment the age of the animal
    // prefix
    animal.age = animal.age + 1;
    // postfix
    animal.age++;
    // postfix by 2
    animal.age + 2;
    
    age = 0;
    
    animal.age = ++age; // prefix increment
    cout << "Animal age after assignment: " << animal.age << endl;
    
    cout << "Animal is a " << animal.species << " and it is " << animal.age << " years old.";
    
    return 0;
}


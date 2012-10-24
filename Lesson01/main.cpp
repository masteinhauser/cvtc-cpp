/* 
 * File: main.cpp
 * Desc: Reads a name from input and produces a greeting that includes the name. 
 * Auth: Myles A. K. Steinhauser
 *
 * Created on October 22, 2012, 8:30 PM
 */

#include <cstdlib>
#include <iostream> // include IO library
#include <algorithm>
#include <cctype>

using namespace std;

string strToUpper(string s) {
    transform(s.begin(), s.end(), s.begin(), (int(*)(int))toupper);
    return s;
}

/*
 * 
 */
int main(int argc, char** argv) {
    // String of characters input from the console.
    string name; // string is a C++ class
    
    cout << " Please enter a name: "; // the return will give us a new line.
    //cin >> name; // points input arrows toward variable which takes data.
    getline(cin, name); // will get entire line, including whitespace
    
    cout << "Hello " << name << ", welcome to C++\n"; // NOTE: Breaks on whitespace in input    
    cout << "Your name Uppercased is " << strToUpper(name) << ".";
    
    return 0;
}


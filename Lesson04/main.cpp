/* 
 * File: main.cpp
 * Desc: Dice Roll guessing game to demonstrate loop knowlege.
 * Auth: Myles A. K. Steinhauser
 *
 * Created on October 30, 2012, 7:02 PM
 */

#include <cstdlib>

using namespace std;

bool isNum(){
    for(int i=0; i<){
        if(!is){
            
        }
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    // Define non-magic numbers
    const int MAX_RANGE = 1000;
    const int MIN_RANGE = 0;
    
    // variable to store random number
    int randInt = 0;
    // variable to store user guess
    int userInt = 1;
    
    // Generate a random number
    srand(time(NULL));
    randInt = rand() % MAX_RANGE + MIN_RANGE;
    
    // Start loop
    // If input = randInt then correct AND exit
    while(userInt != randInt){
        // Ask user to guess number
        cout << "Please guess a numebr between " << MIN_RANGE << " and " << MAX_RANGE << ": ";
        
        // Store user's guess
        cin >> userInt;
        
        // validate user input
        if(!isNum()){
            cout << "You entered an invalid number!!!";
            cout << "Press enter to try again.";
            cin >> userInt; // Store a random value just to pause the output.
            continue;
        }
        
        // Compare user's answer to random number
        // if input < randInt then "higher"
        if(userInt < randInt){
            cout << "higher...";
        // if input > randInt then "lower"
        }else if (userInt > randInt){
            cout << "lower...";
        }
    }
    cout << "You guessed it!";
    
    return 0;
}


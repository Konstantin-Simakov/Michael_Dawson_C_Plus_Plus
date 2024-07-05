// exercise7.cpp
// Binary search
#include <iostream>
using namespace std;

int main(void) 
{
    const int LOW = 1;      // Global lower side
    const int HIGH = 100;   // Global higher side
    int min = LOW;      
    int max = HIGH;      
    int guess;              // Computer guess
    char answer;            // User answer
    int tries = 0;   

    // Player invitation
    cout << "\t\tWelcome to Guess My Number!\n";
    cout << "Computer guesses an integer which user guessed in the range from " 
         << LOW << " to " << HIGH << ".\n\n";

    // Main loop
    do
    {
        tries++;
        guess = (min + max) / 2;    // Divide the range in half
        cout << "Is your guess " << guess << "? (y - yes, h - higher, l - lower)\n";
        
        cin >> answer;
        if (answer == 'y')
            break;
        else if (answer == 'h') 
            min = guess + 1;        // Number is higher, narrow the range
        else if (answer == 'l') 
            max = guess - 1;        // Number is lower, narrow the range
        else 
        {
            cout << "Invalid input.\n";
            tries--; 
        }
    } while (min <= max);
    
    if (min > max)
        cout << "Error: you guessed an incorrect number.\n";
    else
    {
        cout << "\nI (computer) guessed it in " << tries << " tries!\n";
        cout << "Bye!\n";
    }

    return 0;
}

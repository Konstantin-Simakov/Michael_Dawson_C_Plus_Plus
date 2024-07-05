// exercise7.cpp
// Sequential search
#include <iostream>
using namespace std;

int main(void)
{
    const int LOW = 1;      // Global lower side
    const int HIGH = 100;   // Global higher side
    int guess = LOW;        // Computer guess
    char answer;            // User answer
    int tries = 0;

    // Player invitation
    cout << "\t\tWelcome to Guess My Number!\n";
    cout << "Computer guesses an integer which user guessed in the range from " 
         << LOW << " to " << HIGH << ".\n\n";

    // Main loop
    do
    {
        cout << "Is " << guess << " your guess? (y - yes, n - no)\n";
        cin >> answer;
        ++tries;            
        if ('y' == answer)
            break;
        else if ('n' == answer)
            ++guess;
        else
        {
            cout << "Invalid input.\n";
            --tries;
        }
    } while (guess < HIGH);
    
    // Output of results and player farewell
    if (HIGH == guess)
        cout << "Your guess is " << guess << endl;
    
    cout << "\nI (computer) guessed it in " << tries << " tries!\n";
    cout << "Bye!\n";

    return 0;
}

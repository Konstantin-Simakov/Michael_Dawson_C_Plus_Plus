// mad_lib.cpp
// Tells brief story based on user input

#include <iostream>
#include <string>			// For std::string
using namespace std;

string ask_text(string prompt);
int ask_number(string prompt);
void tell_story(string name, string noun, int number, 
				string body_part, string verb);

int main(void)
{
	cout << "Welcome to \'Mad Lib\'.\n\n";
	cout << "Answer the following questions to help create a new story.\n";

	string name = ask_text("Please enter a name: ");
	string noun = ask_text("Please enter a plural noun: ");
	int number = ask_number("Please enter a number: ");
	string body_part = ask_text("Please enter a body part: ");
	string verb = ask_text("Please enter a verb: ");

	tell_story(name, noun, number, body_part, verb);

	return 0;
}

string ask_text(string prompt)
{
	string text;

	cout << prompt;
	getline(cin, text);

	return text;
}

int ask_number(string prompt)
{
	int num;

	cout << prompt;
	(cin >> num).get();

	return num;
}

void tell_story(string name, string noun, int number, 
				string body_part, string verb)
{
	cout << "\nHere\'s your story:\n";

	// name
	cout << "The famous explorer "
		 << name
		 << " had nearly given up a life-long quest to find.\n";

	// noun
	cout << "The Lost City of "
		 << noun 
		 << " when one day, the "
		 << noun 
		 << " found the explorer.\n";

	// number, body_part
	cout << "Surrounded by "
		 << number
		 << " "
		 << noun
		 << ", a tear came to "
		 << name << "\'s "
		 << body_part << ".\n";

	// verb
	cout << "After all this time, the quest was finally over. "
		 << "And then, the "
		 << noun << endl
		 << "promptly devoured "
		 << name << ". "
		 << "The moral of the story? Be careful what you "
		 << verb << " for.\n";
}

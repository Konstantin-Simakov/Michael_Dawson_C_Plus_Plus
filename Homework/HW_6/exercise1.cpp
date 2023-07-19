// exercise1.cpp
// Improvement of the mad_lib.cpp program.
// Tells brief story based on user input.

#include <iostream>
#include <string>			// For std::string
using namespace std;

string & ask_text(const string & prompt, string & text);
int ask_number(const string & prompt);
void tell_story(const string & name, const string & noun, int number, 
				const string & body_part, const string & verb);

int main(void)
{
	cout << "Welcome to \'Mad Lib\'.\n\n";
	cout << "Answer the following questions to help create a new story.\n";

	// text is an auxiliary variable.
	string text;
	string name = ask_text("Please enter a name: ", text);
	string noun = ask_text("Please enter a plural noun: ", text);
	int number = ask_number("Please enter a number: ");
	string body_part = ask_text("Please enter a body part: ", text);
	string verb = ask_text("Please enter a verb: ", text);

	tell_story(name, noun, number, body_part, verb);

	return 0;
}

string & ask_text(const string & prompt, string & text)
{
	cout << prompt;
	getline(cin, text);

	return text;
}

int ask_number(const string & prompt)
{
	int num;

	cout << prompt;
	(cin >> num).get();

	return num;
}

void tell_story(const string & name, const string & noun, int number, 
				const string & body_part, const string & verb)
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

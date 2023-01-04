#include <iostream>
#include <string>
using namespace std;


void printMsg(string str) {
	cout << str;
}

int main() {
	auto msg = "Hello Matt!\nWhat's up";
	printMsg(msg); // call the function
	return 0;
}



// Input full name 

#include <iostream>
#include <string>
using namespace std;


void printMsg(string str) {
	cout << str;
}

int main() {
	cout << "What is your name? ";
	string firstLastName = "";
	getline (cin, firstLastName);

	string composedMsg = "Hello " + firstLastName + "! What's up \n";
	// printMsg(msg); // call the function
	cout << composedMsg;
	return 0;
}

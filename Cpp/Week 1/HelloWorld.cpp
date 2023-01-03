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

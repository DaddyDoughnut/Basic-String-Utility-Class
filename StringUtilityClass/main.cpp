#include "String.h"
#include <iostream>
int main() {

	String myString("B");
	String other("A");
	
	myString += myString;

	myString.WriteToConsole();

	return 0;
}
#include "String.h"
#include <iostream>
int main() {

	String myString("Hello ");
	String other("World!");

	myString += other;

	myString.WriteToConsole();

	return 0;
}
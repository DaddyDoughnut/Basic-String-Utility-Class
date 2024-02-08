#include "String.h"
#include <iostream>
int main() {

	String myString("HOTdog");
	String other("hotdo");
	int len = myString.Length();
	char d = myString.CharacterAt(4);
	
	

	

	myString.Find("H");

	//std::cout << myString.CStr() << std::endl;
	return 0;
}
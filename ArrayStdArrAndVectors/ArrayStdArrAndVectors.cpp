#include <iostream>
#include <array>
#include <vector>

void stlArrDoubler(std::array <int, 5> &incoming) { // Normally std::arrays are passed by value 
	std::cout << "\nInside the stlArrDoubler() stack frame" << std::endl; 
	for (int i = 0; i < 5; i++)
		incoming.at(i) *= 2; 
}

void norArrDoubler(int* incoming, int theSize) {  // Normally Arrays are passed by reference 
	std::cout << "\nInside the norArrDoubler() stack frame" << std::endl; 
	for (int i = 0; i < theSize; i++)
		incoming[i] *= 2; 
}

void vecDoubler(std::vector <int> incoming) {     // Normally vectors are passed by value 
	std::cout << "\nInside the vecDoubler() stack frame" << std::endl; 
	for (int i = 0; i < incoming.size(); i++)
		incoming.at(i) *= 2; 
}

int main() {

	// Normal Array 
	int myNormArray[] = {10, 20, 30, 40, 50}; 
	int zSize = sizeof (myNormArray) / sizeof(int);

	norArrDoubler(myNormArray, zSize);
	for (int i = 0; i < zSize; i++)
		std::cout << myNormArray[i] << std::endl; 
     
	// std::array 
	std::array<int, 5> myArray = { 1, 2, 3, 4, 5 }; 
	std::cout << "Inside the main() stack frame" << std::endl;
	for (int i = 0; i < myArray.size(); i++)
		std::cout << myArray.at(i) << std::endl;

	stlArrDoubler(myArray);
	std::cout << "Inside the main() frame again" << std::endl; 
	for (int i = 0; i < myArray.size(); i++)
		std::cout << myArray.at(i) << std::endl; 
	
	// std::vector 
	std::vector <int> myVec;
	for (int i = 0; i < 5; i++)
		myVec.push_back(5 + i);

	vecDoubler(myVec);
	for (int i = 0; i < myVec.size(); i++)
		std::cout << myVec.at(i) << std::endl;

	return 0; 
}
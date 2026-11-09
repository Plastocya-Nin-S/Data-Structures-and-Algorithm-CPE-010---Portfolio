#include <iostream>

//Created by Niña Denise Santiago

//Function that takes 2 numbers and displays the sum.
void displaySum(int xNum, int yNum);

//Function that returns whether variable A is greater than variable B in value.
bool greaterThan(int xNum, int yNum);

/*Function that takes (2) boolean values, displays all logical operations 
and returns "True" if all operations are successful.*/
bool operations(bool a, bool b);


int main(){
	// Allows display of words true and false instead of 1 or 0
	std::cout << std::boolalpha;
	
	// Asks for User Input of values
	int num1, num2;
	std::cout << "Enter first number: ";
	std::cin >> num1;
	std::cout << "Enter second number: ";
	std::cin >> num2; 
	
	// Calls Function 1 that display sum
	displaySum(num1, num2);
	std::cout << "---------------------------------------------" << std::endl; // for organization	 
	
	// Calls Function 2 that reviews if the value is greater than
	std::cout << "Is " << num1 << " greater than " << num2 << "? " << greaterThan(num1, num2) << std::endl; 
	std::cout << "---------------------------------------------" << std::endl; // for organization	 
	
	// Asks for Boolean Input 
	bool boolA, boolB;
	std::cout << "Enter first boolean[A] (0 for false | 1 for true): ";
	std::cin >> boolA;
	std::cout << "Enter second boolean[B] (0 for false | 1 for true): ";
	std::cin >> boolB;
	std::cout << "---------------------------------------------" << std::endl; // for organization 
	
	// Calls Function 3 that displays logical operations
	bool success = operations(boolA, boolB);
	std::cout << "Logical Operations Execution Success: " << success << std::endl;
	
	return 0;
}


//void displaySum Definition
void displaySum(int xNum, int yNum) {
	int sum = xNum + yNum;
}

//bool greaterThan Definition
bool greaterThan(int xNum, int yNum){
	return xNum > yNum;
}

//bool operations Definition
bool operations(bool a, bool b){
		
	//AND Operation
	std::cout << "Operation AND: " << (a && b) << std::endl;
	//OR Operation
	std::cout << "Operation OR: " << (a || b) << std::endl;
	//NOT Operation
	std::cout << "Operation NOT(A): " << (!a) << std::endl;
	std::cout << "Operation NOT(B): " << (!b) << std::endl;
	//XOR Operation 
	std::cout << "Operation XOR: " << static_cast<bool>(a ^ b) << std::endl;
	return true;

}



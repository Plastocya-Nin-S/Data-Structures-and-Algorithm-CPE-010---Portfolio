#include <iostream>
#include <string.h>
class Student{
	private:
		std::string studentName;
		int studentAge;
	public:
		//constructor
		Student(std::string newName = "Niña", int newAge = 19){
			studentName = std::move(newName);
			studentAge = newAge;
			std::cout << "Constructor Called." << std::endl;
		}
		
		//destructor
		~Student(){
			std::cout << "Destructor Called." << std::endl;
		}
	
		//copy constructor
		Student(const Student &copyStudent){
			std::cout << "Copy Constructor Called." << std::endl;
			studentName = copyStudent.studentName;
			studentAge = copyStudent.studentAge;
		}
		
		//display attributes
		void printDetails(){
			std::cout << this ->studentName << " " << this->studentAge << std::endl;
		}

};

int main(){
	const size_t j = 5;
	
	Student studentList[j] = {};
	std::string nameList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"};
	int ageList[j] = {15, 16, 18, 19, 16};
	
	
	return 0;
}


/*
  RMIT University Vietnam
  Course: EEET2482 Software Engineering Design
  Semester: 2022A
  Lab Assessment: 1
  Author: Doan Tran Thien Phuc
  ID: 3926377
  Compiler used: gcc 8.1.0
  Created  date: 8/4/2022
  Acknowledgement: Lecture slides, StackOverflow 
*/

#include <iostream>
#include <sstream>
#include <fstream>

int main(int argc, char *argv[]){
	//Report invalid arguments error
	if (argc != 5 && argc != 4 && argc != 2){
		std::cerr << "Incorrect number of arguments.";
		return -1;
	}

	//Check if -w is a command for question b
	int check = 0;
	if (argc == 5){
		check++;
	}

	//a Print out sum
	if (argc == 4){
		int num[3], sum;
		for (int i = 0 + check; i < 3 + check; i++){
			std::stringstream sstr;
			sstr << std::hex << argv[i+1];
			sstr >> num[i - check];
			sum += num[i - check];
		}
		std::stringstream sstr;
		sstr << std::hex << sum;
		std::cout << "Sum is: " << "0x" << sstr.str();
	}

	//b Write data to data.txt
	std::fstream myfile;
	if(argc == 5){
		myfile.open ("data.txt", std::ios::out);
		//Report error
		if(!myfile){
			std::cerr << "Failed to write to file";
			return -3;
		}
		for (int i = 2; i < 5; i++){
			myfile << argv[i] << std::endl;
		}
		myfile.close();
	}

	//c Read data from data.txt
	if (argc == 2){
		myfile.open ("data.txt", std::ios::in);
		//Report error
		if(!myfile){
			std::cerr << "Failed to read from file";
			return -4;
		}
		//Store data to a string array
		std::string str[3], max_str;
		for (int i = 0; i < 3; i++){
			myfile >> str[i];
		}

		//Find longest line
		max_str = str[0];
		for (int i = 0; i < 3; i++){
			if (max_str.length() < str[i].length()){
				max_str = str[i];
			}
		}
		std::cout << max_str;
	}
	return 0;
}
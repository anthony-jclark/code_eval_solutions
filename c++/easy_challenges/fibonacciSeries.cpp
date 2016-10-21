/*
Program: fibonacciSeries.cpp
Author: Seth Tucker
Date: 9/5/2016
Last Modified: 10/19/2016

Program takes input from a text file and computes the nth Fibonacci 
number where n is pulled from the text file. Ex: n = 5, nth Fibonacci
number = 5; n = 12, nth Fibonacci number = 144.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

//Compute nth Fibonacci number
void computeFib(vector<long> &numbers){
	for (auto i = 0; i < numbers.size(); i++) {
		//If n = 0
		if (numbers[i] == 0) cout << "\n0";
		//If n = 1 or n = 2
		else if (numbers[i] > 0 && numbers[i] < 3) cout << "\n1";
		//Everything > 2
		else {
			long fibNum = 0;
			long digitOne = 1;
			long digitTwo = 1;
			for (auto j = 2; j < numbers[i]; j++) {
				fibNum = digitOne + digitTwo;
				digitOne = digitTwo;
				digitTwo = fibNum;
			}
			cout << "\n" << fibNum << "\n";
		}
	}
	
}  //End computeFib()

int main(int argc, char *argv[]) {
	string fileName(argv[1]);
	ifstream source;
	source.open(fileName);
	
	//Get numbers from text file and store in a vector
	vector<long> numbers;
	if (source) {
		long value;
		while (source >> value) {
			numbers.push_back(value);
		}
	}
	source.close();

	//Compute nth Fibonacci number
	computeFib(numbers);

	return 0;

}  //End main()
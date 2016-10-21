/*
Program: FizzBuzz.cpp
Author: Seth Tucker
Date: 9/27/2016
Last Modified: 10/19/2016

Program takes input from a text file in the format: 3 5 10. Each line
is pulled out and processed where the first number = first divisor, second
number = second divisor, and third number = upper bound. These numbers are
then passed to a function that computes fizzbuzz for every number from 1 to
n where n is the upper bound. If a number is divisible by both first and
second divisor, output = FB for fizzbuzz; if a number is only divisible by
the first divisor, output = F for fizz; if a number is only divisible by the
second number, output = b for buzz; if a number is not divisible by either
divisor, output = that number.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;
using std::istringstream;

//Compute fizzbuzz for n numbers
void fizzBuzz(vector<long> &numbers) {
	long firstDivisor = numbers.at(0);
	long secondDivisor = numbers.at(1);
	//How many numbers to compute for
	long count = numbers.at(2);

	//Check every number from 1 to n
	for (auto i = 1; i < count + 1; i++) {
		//If i is divisible by both input numbers
		if (i % firstDivisor == 0 && i % secondDivisor == 0) cout << "FB ";
		//If i is only divisible by the first input number
		else if (i % firstDivisor == 0) cout << "F ";
		//If i is only divisible by the second input number
		else if (i % secondDivisor == 0) cout << "B ";
		//If i is not divisible by either input number
		else cout << i << " ";
	}
	cout << "\n";
	
}  //End fizzBuzz()

int main(int argc, char *argv[]) {
	string fileName(argv[1]);
	ifstream source(fileName);

	//Pull data from text file line by line
	if (source) {
		string line;
		while (getline(source, line)) {
			//Gotta love that istringstream magic
			istringstream iss(line);
			long value;
			vector<long> numbers;
			while (iss >> value) {
				numbers.push_back(value);
			}
			fizzBuzz(numbers);
		}
	}

	return 0;

}  //End main()
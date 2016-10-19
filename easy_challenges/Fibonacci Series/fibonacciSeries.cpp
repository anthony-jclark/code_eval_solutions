/*
Program: fibonacciSeries.cpp
Date: 9/5/2016
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

int main(int argc, char *argv[]) {
	string fileName(argv[1]);
	ifstream source;
	source.open(fileName);
	vector<long> numbers;
	if (source) {
		long value;
		while (source >> value) {
			numbers.push_back(value);
		}
	}
	source.close();

	int size = numbers.size();

	for (int i = 0; i != size; i++) {
		if (numbers[i] == 0) cout << "\n0";
		else if (numbers[i] > 0 && numbers[i] < 3) cout << "\n1";
		else {
			int fibNum = 0;
			int digitOne = 1;
			int digitTwo = 1;
			for (int j = 2; j < numbers[i]; j++) {
				fibNum = digitOne + digitTwo;
				digitOne = digitTwo;
				digitTwo = fibNum;
			}
			cout << "\n" << fibNum << "\n";
		}
	}

	return 0;

}  //End main()
/*
Program: FizzBuzz.cpp
Date: 9/27/2016
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

void fizzBuzz(vector<long> numbers) {
	int firstDivider = numbers.at(0);
	int secondDivider = numbers.at(1);
	int count = numbers.at(2);

	for (int i = 1; i < count + 1; i++) {
		if (i % firstDivider == 0 && i % secondDivider == 0) cout << "FB ";
		else if (i % firstDivider == 0) cout << "F ";
		else if (i % secondDivider == 0) cout << "B ";
		else cout << i << " ";
	}
	cout << "\n";
}

int main(int argc, char *argv[]) {
	string fileName(argv[1]);
	ifstream source;
	//source.open("C:\\Users\\OWNER\\Desktop\\Computer Science\\Code Eval Proj\\Fizz Buzz\\FizzBuzzNums.txt");
	source.open(fileName);

	if (source) {
		string line;
		while (getline(source, line)) {
			istringstream iss(line);
			long value;
			vector<long> numbers;
			while (iss >> value) {
				numbers.push_back(value);
			}
			fizzBuzz(numbers);
		}
	}

	//system("pause");
	return 0;

}  //End main()
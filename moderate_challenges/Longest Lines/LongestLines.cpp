/*
Program: LongestLines.cpp
Date: 9/27/2016
Last Modified: 10/19/2016
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;
using std::istringstream;
using std::sort;

int getNumLines(string fileName) {
	ifstream source;
	source.open(fileName);
	int numLines;
	string line;
	getline(source, line);
	istringstream iss(line);
	iss >> numLines;
	return numLines;
}

vector<string> getLines(string fileName) {
	ifstream source; 
	source.open(fileName);

	vector<string> inputs;

	if (source) {
		string line;
		getline(source, line);
		while (getline(source, line)) {
			inputs.push_back(line);
		}
	}
	return inputs;

}  //End getLines()

void sortLines(vector<string> &inputs) {
	auto range = inputs.size();
	for (auto i = 0; i < range; i++) {
		for (auto j = 0; j < range; j++) {
			if (inputs.at(j).length() < inputs.at(i).length()) {
				string temp = inputs.at(i);
				inputs.at(i) = inputs.at(j);
				inputs.at(j) = temp;
			}
		}
	}

}  //End sortLines()

void trimLines(vector<string> &inputs) {
	string whitespace = " \t";
	for (auto i = 0; i < inputs.size(); i++) {
		string line = inputs.at(i);
		auto strBegin = line.find_first_not_of(whitespace);
		auto strEnd = line.find_last_not_of(whitespace);
		auto strRange = strEnd - strBegin + 1;
		
		inputs.at(i) = line.substr(strBegin, strRange);
	}

}  //End trimLines()

void displayLines(vector<string> inputs, int numLines) {
	for (auto i = 0; i < numLines; i++) cout << inputs.at(i) << endl;

}  //End displayLines()

int main(int argc, char *argv[]) {
	//string fileName(argv[1]);
	string fileName("C:\\Users\\OWNER\\Desktop\\Computer Science\\Code Eval Proj\\code_eval_solutions\\moderate_challenges\\Longest Lines\\LongestLines.txt");

	int numLines = getNumLines(fileName);

	//Store lines from input file in a vector
	vector<string> inputs = getLines(fileName);

	//Trim trailing whitespace from strings
	trimLines(inputs);

	//Sort vector longest to shortest
	sortLines(inputs);

	//Print n longest lines where n = numLines
	displayLines(inputs, numLines);

	system("pause");
	return 0;

}  //End main()
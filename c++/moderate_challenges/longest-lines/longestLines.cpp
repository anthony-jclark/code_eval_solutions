/*
Program: LongestLines.cpp
Date: 9/27/2016
Last Modified: 10/19/2016

Program receives lines of text from a file and finds the
longest ones. The first line of the file contains a number
which determines how many of the longest lines to display
starting with the longest. Trailing white space is also
removed so:
	"A short line        " is not longer than
	"A longer line"
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
using std::istream;
using std::ostream;

//Pulls each line from the text file and stores in abort
//vectore of strings
vector<string> getLines(istream &source, long &numLines) {

	vector<string> inputs;

	if (source) {
		string line;
		getline(source, line);

		//Pulls the first line which is a number used to
		//determine how many longets lines to display
		istringstream iss(line);
		iss >> numLines;

		//Puts remaining lines into a vector of strings
		while (getline(source, line)) {
			inputs.push_back(line);
		}
	}
	return inputs;

}  //End getLines()

//Sorts lines based on length starting with the longest
void sortLines(vector<string> &inputs) {
	long range = inputs.size();

	//Go through every line...
	for (auto i = 0; i < range; i++) {
		//and compare it to every other line
		for (auto j = 0; j < range; j++) {
			//If we find a line thats longer than our currently selected one...
			//swap them
			if (inputs.at(j).length() < inputs.at(i).length()) {
				string temp = inputs.at(i);  //Store current line
				inputs.at(i) = inputs.at(j);  //Store longer line at current's index
				inputs.at(j) = temp;  //Store current at longer lines index
			}
		}
	}

}  //End sortLines()

//Removes trailing whitespace from given line of text
void trimLines(vector<string> &inputs) {
	string whitespace = "  ";
	for (auto i = 0; i < inputs.size(); i++) {
		//Select line to process
		string line = inputs.at(i);
		//Find begining of line, i.e. first non-whitespace character
		auto strBegin = line.find_first_not_of(whitespace);
		//Find end of line, where there is more than one whitespace
		auto strEnd = line.find_last_not_of(whitespace);
		//Calculate how many characters are between begining and end
		auto strRange = strEnd - strBegin + 1;

		//Overwrite the line at the index with a substring with trailing
		//whitespace removed
		inputs.at(i) = line.substr(strBegin, strRange);
	}

}  //End trimLines()

//Displays n longest lines
void displayLines(vector<string> &inputs, long &numLines, ostream &out) {
	for (auto i = 0; i < numLines; i++)
		out << inputs.at(i) << endl;

}  //End displayLines()

// Run the entire process
void longestLines(istream &inStream, ostream &outStream) {
	//Get number of longest lines to display
	long numLines;

	//Store lines from input file in a vector
	vector<string> inputs = getLines(inStream, numLines);

	//Trim trailing whitespace from strings
	trimLines(inputs);

	//Sort vector longest to shortest
	sortLines(inputs);

	//Print n longest lines where n = numLines
	displayLines(inputs, numLines, outStream);
}

//
// Adding this definition for easy unit testing purposes
// This will not affect the normal compiling flow
//
#ifndef UNIT_TESTING


int main(int argc, char *argv[]) {
	string fileName(argv[1]);
	ifstream inputFile(fileName);
	longestLines(inputFile, cout);
	return 0;
}  //End main()


#endif

/*
Program: sumPrimes.cpp
Author: Seth Tucker
Date: 8/31/2016
Last Modified: 10/19/2016

Program sums up the first 1000 primes.
*/

#include <iostream>

using std::cout;
using std::endl;

//Checks a given number to see if its prime or not
bool primeCheck(long &current) {
	/*
	Takes the current number and tries to evenly
	divide it by every number less than it and greater
	than 1. If nothing between 1 and current - 1 evenly
	divides it than current is prime.
	*/
	for (auto i = 1; i < current; i++) {
		if (current % i == 0 && i != 1) { return false; }
	}

}  //End primeCheck()

//Function to sum primes
void sum(long &numPrimes){
	long sum = 0;  //Stores sum of primes
	long count = 0;  //How many primes have been found
	long current = 2;  //Start at first prime number
	
	//Loops until the number of found primes = the upper bound
	while (count < numPrimes) {
		if (primeCheck(current) != false){
			sum += current;
			count++;
		}
		current++;
	}
	
	//Display the sum after upper bound is reached
	cout << sum << endl;
	
}  //End sum()

int main() {
	//How many primes to sum up, i.e. the upper bound
	long numPrimes = 1000;
	
	//Function call
	sum(numPrimes);

	return 0;

}  //End main()
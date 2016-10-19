/*
Program: sumPrimes.cpp
Date: 8/31/2016
*/

#include <iostream>

using std::cout;
using std::endl;

bool primeCheck(int current) {
	for (int i = 1; i < current; i++) {
		if (current % i == 0 && i != 1) { return false; }
	}
}

int main() {
	int sum = 0;
	int numPrimes = 1000;
	int count = 0;  //Count of checked primes
	int current = 2;  //Current prime being checked

	while (count < numPrimes) {
		if (primeCheck(current) != false) {
			sum += current;
			count++;
		}
		current++;

	}

	cout << sum << endl;

	//system("pause");
	return 0;

}
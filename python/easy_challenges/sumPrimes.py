#Program: sumPrimes.py
#Author: Seth Tucker
#Date: 10/20/2016
#Last Modified: 10/20/2016
#Program sums up the first 1000 primes.

#Used by sumPrimes() to check for valid primes
def primeCheck(current):
	'''
	Takes the current number and tries to evenly divide it
	by every number less than it and greater than 1. If nothing
	divides it than current is a prime number
	'''
    for i in range(1, current):
        if current % i == 0 and i != 1:
            return False

#Function that finds and sums up primes
def sumPrimes(numPrimes):
    #Stores sum of primes
	sum1 = 0;
	#How many primes have been found
    count = 0;
	#Start at first prime number
    current = 2;

	#Loops until number of found primes = the upper bound
    while count < numPrimes:
        if primeCheck(current) != False:
            sum1 += current;
            count += 1
        current += 1

    print(sum1)
        
def main():
	#How many primes to cycle through, i.e. the upper bound
    numPrimes = 1000
    sumPrimes(numPrimes)

main()
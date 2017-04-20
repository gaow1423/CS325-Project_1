/*****************
 * Problem_1_alg_1.cpp
 * Tyler Inberg
 * 4/19/2017
 * Program used to find max subarray in an array 
 * Input: None
 * Output: Max Array
 * ****************/

#include <iostream>
#include <string> //c++ strings
#include <cstdlib>

using namespace std;

int main () {	

	int n = 10;
	int array [10] = {31,-41,59,26,-53,58,97,-93,-23,84};
	int sum;
	int max = 0;


	for(int i = 0; i<n; i++){
		for (int j = 1; j<n; j++){
	   		sum = 0;
		    for (int k = i; k<j; k++){
				sum = sum + array [k];
			}
	    	if (sum > max)
	    		max = sum;
	    }
	}
   
   cout << "The max array is " << max << "!\n";
   
   return 0;
}

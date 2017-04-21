/*****************
 * Problem_1_alg_2.cpp
 * Tyler Inberg
 * 4/20/2017
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
	int sum, l;
	int max = 0;


	for(int i = 0; i<n; i++){
	    sum = 0;
		l = i;
		for (int j = i + 1; j<n; j++){
		    for (int k = l; k<j; k++){
				sum = sum + array [k];
			}
	    	if (sum > max)
	    		max = sum;
			l++;
	    }
	}
   
   cout << "The max array is " << max << "!\n";
   
   return 0; 
}

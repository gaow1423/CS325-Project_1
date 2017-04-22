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
	int max = 0;
	int beginning_index, end_index, sum;


	for(int i = 0; i<n; i++){
		for (int j = i+1; j<n; j++){
	   		sum = 0;
		    for (int k = i; k<j; k++){
				sum = sum + array [k];
			}
			cout << sum << "\n";
	    	if (sum > max){
	    		max = sum;
				beginning_index = i;
				end_index = j;
			}
	    }
	}
   
   cout << "The value of the max array is " << max << "!\n";
   cout << "The max array is { ";
   for(int a = beginning_index;a<=end_index; a++){
	  cout << array[a];
   	  cout << " ";
	}
   cout << "}\n";

   return 0;
}

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
	int sum, l, beginning_index, end_index;
	int max = 0;


	for(int i = 0; i<n; i++){
	    sum = 0;
		l = i;
		for (int j = i + 1; j<n; j++){
		    for (int k = l; k<j; k++){
				sum = sum + array [k];
			}
	    	if (sum > max){
	    		max = sum;
				beginning_index = i;
				end_index = j;
			}
			l++;
	    }
	}
   
   cout << "The max array value is " << max << "!\n";
   cout << "The max array is { ";
   for(int a = beginning_index;a<=end_index; a++){
	  cout << array[a];
   	  cout << " ";
	}
   cout << "}\n";

   
   return 0;
}

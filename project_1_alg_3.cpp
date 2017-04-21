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

int MaxArray (int array[], int beginning, int end);
int MaxSuffix (int array[], int beginning, int end);
int MaxPrefix (int array[], int beginning, int end);

int main () {	
	int beginning = 0;
	int end = 10;
	int array [10] = {31,-41,59,26,-53,58,97,-93,-23,84};
	int solution;

	solution = MaxArray(array,beginning,end);
	
    cout << "The max array is " << solution << "!\n";
   
    return 0;
}

int MaxArray (int array[], int beginning, int end){
    
   if (beginning == end)
	   return array[beginning];
   
    int middle = (end-beginning)/2;
	
	int left_max_array = MaxArray(array, beginning, middle);
	int right_max_array = MaxArray(array, middle+1,end);
	int middle_max_array = MaxSuffix(array,beginning, middle) + MaxPrefix(array,middle+1,end);
	
	if (left_max_array < right_max_array)
	   left_max_array = right_max_array;
    else if (left_max_array < middle_max_array)
   	   left_max_array = middle_max_array;
	return left_max_array;	
}

int MaxSuffix (int array[], int beginning, int end){
    int max = 0;
	int sum = 0;

   if (beginning == end)
	   return array[beginning];
	for (int i = end; i>beginning-1; i--){
		sum = sum + array[i];
		if (sum>max)
	    max = sum;
		}

	return max;	
}

int MaxPrefix (int array[], int beginning, int end){
    int max = 0;
	int sum = 0;

   if (beginning == end)
	   return array[beginning];
	for (int i = beginning; i<end+1; i++){
		sum = sum + array[i];
		if (sum>max)
	    max = sum;
		}
	return max; 
}

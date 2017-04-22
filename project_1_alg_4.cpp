/***************
 *problem_1_alg_4.cpp
 *Wei gao
 *4/20/2017
 */
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
int main(){
       	int array [10] = {31,-41,59,26,-53,58,97,-93,-23,84};
	int sum, beginning_index, end_index, b;
	int max = array[0];
//	int high=0, low=0;
//	int ehigh=0, elow=0;
	sum = array[0];

	for(int i=1; i<10; i++){
	//	ehigh = i;
		if(sum > 0){
			sum += array[i];
		}
		else{
		//	elow = i;
			sum = array[i];
		}
		
		if(sum > max){
			max = sum;
			end_index = i;
		//	low = elow;
		//	high = ehigh;
		}
	}
	sum = 0;
	b = end_index;
    while(sum!=max){
   		sum=array[b] + sum;
   		b--;
   }
   beginning_index = b;
   cout << "The max array value is " << max << "!\n";
   cout << "The max array is { ";
   for(int a = beginning_index+1;a<=end_index+1; a++){
	  cout << array[a];
   	  cout << " ";
	}
   cout << "}\n";

}

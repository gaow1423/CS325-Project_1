/*Name:Wei Gao
 *Date:4/22/2017
 *Description:Using four algorithms to test the given txt file with multiple arrays to output the maxsubarray correspondly.Test the running time of four algorithms that find the maxsubarray of array with different size.
 *
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

struct maxi
{

	int low;
	int high;
	int max;
};

struct maxi algorithm_1(int array[], int n)
{
	maxi al_1;
	int sum;
	al_1.max = array[0];

	for(int i = 0; i<n; i++){
		for (int j = i; j<n; j++){
			sum = 0;
			for (int k = i; k<=j; k++){
				sum = sum + array[k];
			}
			if (sum > al_1.max)
			{
				al_1.max = sum;
				al_1.low = i;
				al_1.high = j;
			}
		}
	}
	return al_1;
}

struct maxi algorithm_2(int array[], int n)
{
	maxi al_2;
	int sum;
	al_2.max = array[0];
	for(int i = 0; i<n; i++){
		sum = 0;
		for (int j = i; j<n; j++){
			sum = sum + array[j];
			if (sum > al_2.max)
			{
				al_2.max = sum;
				al_2.low = i;
				al_2.high = j;
			}
		}
	}
	return al_2;
}
struct maxi algorithm_3(int array[], int start, int end)
{
	struct maxi base_case, left, right, overall, suffix, prefix;
	int mid, sum, max, left_max, right_max, overall_max;

	if (start == end)
	{
		base_case.low = base_case.high = start;
		base_case.max = array[start];
		return base_case;
	}
	mid = (start + end)/2;
	left = algorithm_3(array, start, mid);
	right = algorithm_3(array, mid+1, end);
	sum = 0;
	max = -200;
	suffix.high = suffix.low = mid;
	for (int i = mid; i >= start; i--)
	{
		sum = sum + array[i];
		if (sum > max)
		{
			max = suffix.max = sum;
			suffix.low = i;
		}
	}
	sum = 0;
	max = -200;
	prefix.low = prefix.high = mid+1;
	for(int i = mid+1; i <= end; i++)
	{
		sum = sum + array[i];
		if (sum > max)
		{
			max = prefix.max = sum;
			prefix.high = i;
		}
	}
	overall.max = prefix.max + suffix.max;
	overall.low = suffix.low;
	overall.high = prefix.high;
	left_max = left.max;
	right_max = right.max;
	overall_max = overall.max;

	if(left_max >= right_max && left_max >= overall_max)
		return left;
	else if(right_max >= overall_max)
		return right;
	else
		return overall;
}

struct maxi algorithm_4(int array[], int n)
{
	maxi al_4;
	int low = 0;
	int high = 0;
	al_4.low = 0;
	al_4.high = 0;
	int sum;
	al_4.max = array[0];
	sum = array[0];

	for(int i=1; i<n; i++)
	{
		high = i;
		if (sum > 0)
			sum += array[i];
		else
		{
			low = i;
			sum = array[i];
		}
		if (sum > al_4.max)
		{
			al_4.max = sum;
			al_4.low = low;
			al_4.high = high;
		}
	}
	return al_4;
}
int MSS_Problems()
{
	char str[200];
	int j,k;
	int buffer;
	int arra_1[100];
	FILE * pFile;
	pFile = fopen("MSS_Results.txt", "w");
	FILE * file;
	file = fopen ("MSS_Problems.txt", "r");
	while(fgets(str, 200, file))
	{
		int i = 0;
		char *pch;
		pch = strtok (str," ");
		while (pch != NULL)
		{	
			buffer = atoi(pch);
			pch = strtok(NULL, " ");
			if ((pch!=NULL)||((pch == NULL)&&(buffer!=0)))
			{
				arra_1[i] = buffer;
				i++;
			}
		}
		int array[i];
		for (int k = 0; k < i; k++)
		{
			array[k] = arra_1[k];
			printf("%d ", array[k]);
			fprintf(pFile, "%d ", array[k]);
		}
		printf("\n");
		fprintf(pFile, "\n");
		//first algorithm
		printf("The first algorithm:\n");
		fprintf(pFile, "The first algorithm:\n");
		struct maxi a_1 = algorithm_1(array, i);
		for(int q = a_1.low; q < a_1.high+1; q++)
		{
			printf("%d ", array[q]);
			fprintf(pFile, "%d ", array[q]);
		}
		printf("\n");
		fprintf(pFile, "\n");
		printf("%d\n", a_1.max);
		fprintf(pFile, "%d\n", a_1.max);
		//second algorithm
		printf("The second algorithm:\n");
		fprintf(pFile, "The second algorithm:\n");
		struct maxi a_2 = algorithm_2(array, i);
		for(int q = a_2.low; q < a_2.high+1; q++)
		{
			printf("%d ", array[q]);
			fprintf(pFile, "%d ", array[q]);
		}
		printf("\n");
		fprintf(pFile, "\n");
		printf("%d\n", a_2.max);
		fprintf(pFile, "%d\n", a_2.max);
		//third algorithm
		printf("The third algorithm:\n");
		fprintf(pFile, "The third algorithm:\n");
		struct maxi a_3 = algorithm_3(array, 0, i-1);
		for(int q = a_3.low; q < a_3.high+1; q++)
		{
			printf("%d ", array[q]);
			fprintf(pFile, "%d ", array[q]);
		}
		printf("\n");
		fprintf(pFile, "\n");
		printf("%d\n", a_3.max);
		fprintf(pFile, "%d\n", a_3.max);
		//forth algorithm
		printf("The forth algorithm:\n");
		fprintf(pFile, "The forth algorithm:\n");
		struct maxi a_4 = algorithm_4(array, i);
		for(int q = a_4.low; q < a_4.high+1; q++)
		{
			printf("%d ", array[q]);
			fprintf(pFile, "%d ", array[q]);
		}
		printf("\n");
		fprintf(pFile, "\n");
		printf("%d\n", a_4.max);
		fprintf(pFile, "%d\n", a_4.max);	
	}
	fclose(pFile);
	fclose(file);
	return 0;
}
int main(){
	MSS_Problems();
	int A[10] = {1,1,1,1,1,1,1,1,1,1};
	int b = 1;
	int A_1[10] = {50, 100, 200, 500, 1000, 1500, 2000, 2500, 3000, 3500};
     	int A_2[10] = {100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000};
	int A_3[10] = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
	int A_4[10] = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
	while(b==1)
	{
		const int N = 1000000;
		int B[N];
		int A[10];
		FILE *jfile;
		int choice;
		cout << "Which algorithm do you want to test?" << endl;
		cout << "1.Algorithm_1   2.Algorithm_2   3.Algorithm_3   4.Algorithm_4 (please enter 1,2,3,4 to indicate which one do you want)"<< endl;
		cin >> choice;
		if (choice == 1)
		{
			for(int i=0; i<10; i++)
			{
				A[i] = A_1[i];
			}
			jfile = fopen("AverageRunningtime_algorithm_1.txt", "w");
		}
		else if (choice == 2)
		{
			for(int i=0; i<10; i++)
                         {
                                 A[i] = A_2[i];
                         }
			jfile = fopen("AverageRunningtime_algorithm_2.txt", "w");
		}
		else if (choice == 3)
		{
			for(int i=0; i<10; i++)
                         {
                                 A[i] = A_3[i];
                         }
			jfile = fopen("AverageRunningtime_algorithm_3.txt", "w");
		}
		else
		{
			for(int i=0; i<10; i++)
                         {
                                 A[i] = A_4[i];
                         }
			jfile = fopen("AverageRunningtime_algorithm_4.txt", "w");
		}
		//	jfile = fopen("AverageRunningtime_algorithm_3.txt", "w");
		float total, average;

		for(int j=0; j<10; j++)
		{
			fprintf(jfile, "%d ", A[j]);//write to file
			printf("%d ", A[j]);
			total = 0;
			average = 0;
			if (choice == 1)
			{
				for (int k = 1; k <= 10; k++)
				{
					srand (time (NULL));
					for (int i=0; i < A[j]; i++)
					{
						B[i] = rand () % 1999 - 999;//generate number from -999 to 999.
					}
					clock_t t1, t2;
					t1 = clock ();
					algorithm_1(B,A[j]);
					t2 = clock ();
					float diff ((float) t2 - (float) t1);  //total time 
					float seconds = diff / CLOCKS_PER_SEC;
					total = total + seconds; //running total
				}
				average = total /10;
				printf(" %f ", average);//print average to terminal
				fprintf(jfile, " %f ", average);//write to file
			}
			else if (choice == 2)
			{
				for (int k = 1; k <= 10; k++)
				{
					srand (time (NULL));
					for (int i=0; i < A[j]; i++)
					{
						B[i] = rand () % 1999 - 999;//generate number from -999 to 999.
					}
					clock_t t1, t2;
					t1 = clock ();
					algorithm_2(B,A[j]);
					t2 = clock ();
					float diff ((float) t2 - (float) t1);  //total time 
					float seconds = diff / CLOCKS_PER_SEC;
					total = total + seconds; //running total
				}
				average = total /10;
				printf(" %f ", average);//print average to terminal
				fprintf(jfile, " %f ", average);//write to file
			}
			else if (choice == 3)
			{
				for (int k = 1; k <= 10; k++)
				{
					srand (time (NULL));
					for (int i=0; i < A[j]; i++)
					{
						B[i] = rand () % 199 - 99;//generate number from -999 to 999.
					}
					clock_t t1, t2;
					t1 = clock ();
					algorithm_3(B, 0, A[j]-1);
					t2 = clock ();
					float diff ((float) t2 - (float) t1);  //total time 
					float seconds = diff / CLOCKS_PER_SEC;
					total = total + seconds; //running total
				}
				average = total /10;
				printf(" %f ", average);//print average to terminal
				fprintf(jfile, " %f ", average);//write to file
			}
			else
			{
				for (int k = 1; k <= 10; k++)
				{
					srand (time (NULL));
					for (int i=0; i < A[j]; i++)
					{
						B[i] = rand () % 199 - 99;//generate number from -999 to 999.
					}
					clock_t t1, t2;
					t1 = clock ();
					algorithm_4(B, A[j]);
					t2 = clock ();
					float diff ((float) t2 - (float) t1);  //total time 
					float seconds = diff / CLOCKS_PER_SEC;
					total = total + seconds; //running total
				}
				average = total /10;
				printf(" %f ", average);//print average to terminal
				fprintf(jfile, " %f ", average);//write to file
			}
			printf("\n");
			fprintf(jfile, "\n");
		}

		fclose(jfile);
		int t;
		cout << "Do you want to continue?" << endl;
		cout << "1.Yes, 2.NO (enter 1 or 2)" << endl;
		cin >> t;
		if (t == 2)
			b = 2;
	}
	return 0;
}

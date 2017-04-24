/*
*Program: Project1 MAX SUM SUBARRAY benchmarking
*Description: Program that uses 4 seperate implementations to compare runtime
*Group: Wei Gao, Tyler Inberg, Benjamin Fields
*Date: 4/23/2017
*/

#include <iostream>
#include <fstream>
#include <time.h>

std::ifstream inputFile;
std::ofstream outputFile;

typedef struct 
{
	int begIndex;
	int endIndex;
	int sum;
	float time;
}MSA;

 MSA iterAlg2(int* arr, int n)
{
	 clock_t t1, t2;
	 MSA ans;
	 t1 = clock();
	 int startIndex = 0;
	 int endIndex = 0;
	 int max = -10000000;
	
	
	 
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += arr[j];
			if (sum > max)
			{
				startIndex = i;
				endIndex = j;
				max = sum;
			}

		}
	}
	 
	 t2 = clock();
	 float diff((float)t2 - (float)t1);
	 float seconds = diff / CLOCKS_PER_SEC;
	 ans.begIndex = startIndex;
	 ans.endIndex = endIndex;
	 ans.sum = max;
	 ans.time = seconds;
	 return ans;
}

 MSA iterAlg1(int* arr, int n)
 {
	 clock_t t1, t2;
	 MSA ans;
	 t1 = clock();
	 int startIndex = 0;
	 int endIndex = 0;
	 int max = -10000000;
	 int sum;
	 for (int i = 0; i <= n; i++)
	 {
		 for (int j = 0; j <= n; j++)
		 {
			 sum = 0;
			 for (int k = i; k < j; k++)
			 {
				 sum += arr[k];
			 }
			 if (sum > max)
			 {
				 startIndex = i;
				 endIndex = j;
				 max = sum;
			 }
		 }
	 }
	 
	 t2 = clock();
	 float diff((float)t2 - (float)t1);
	 float seconds = diff / CLOCKS_PER_SEC;
	 ans.begIndex = startIndex;
	 ans.endIndex = endIndex;
	 ans.sum = max;
	 ans.time = seconds;
	 return ans;
 }

 MSA maxCrossSum(int* arr, int start, int m, int endIndex)
 {
	 MSA ans;
	 int sum = 0;
	 int leftSum = -100000;
	 for (int i = m; i >= start; i--)
	 {
		 sum = sum + arr[i];
		 if (sum>leftSum)
		 {
			 leftSum = sum;
			 ans.begIndex = i;
			 
		 }
	 }
	 sum = 0;
	 int rightSum = -100000;
	 for (int i = m+1; i <= endIndex; i++)
	 {
		 sum = sum + arr[i];
		 if (sum>rightSum)
		 {
			 rightSum = sum;
			 ans.endIndex = i;
		 }
	 }
	 ans.sum = leftSum + rightSum;
	 return ans;
 }

 MSA RecursiveFunctionCall(int* arr, int start, int endIndex)
 {
	 MSA ans;
	 if (start == endIndex)
	 {
		 ans.begIndex = start;
		 ans.endIndex = endIndex;
		 ans.sum = arr[start];
		 return ans;
	 }

	 int m = (start + endIndex) / 2;
	 MSA firstHalf = RecursiveFunctionCall(arr, start, m);
	 MSA SecondHalf = RecursiveFunctionCall(arr, m + 1, endIndex);
	 MSA crossSum = maxCrossSum(arr, start, m, endIndex);

	 if (firstHalf.sum > SecondHalf.sum)
	 {
		 ans = firstHalf;
	 }
	 else
	 {
		 ans = SecondHalf;
	 }

	 if (ans.sum > crossSum.sum)
	 {
		 return ans;
	 }
	 else
	 {
		 return crossSum;
	 }
	 
 }

 MSA RecAlg3(int* arr, int n)
 {
	 clock_t t1, t2;
	 MSA ans;
	 t1 = clock();
	 
	 ans = RecursiveFunctionCall(arr, 0, n);
	 t2 = clock();
	 float diff((float)t2 - (float)t1);
	 float seconds = diff / CLOCKS_PER_SEC;
	 ans.time = seconds;
	 return ans;
 }

 MSA Alg4(int* arr, int n)
 {
	 clock_t t1, t2;
	 t1 = clock();
	 MSA ans;
	 int max = -1000000, maxHere = 0, start = 0, end = 0, s = 0;
	 for (int i = 0; i < n; i++)
	 {
		 maxHere += arr[i];
		 if (max < maxHere)
		 {
			 max = maxHere;
			 start = s;
			 end = i;
		 }

		 if (maxHere < 0)
		 {
			 maxHere = 0;
			 s = i + 1;
		 }
	 }
	 t2 = clock();
	 float diff((float)t2 - (float)t1);
	 float seconds = diff / CLOCKS_PER_SEC;
	 ans.time = seconds;
	 ans.sum = max;
	 ans.begIndex = start;
	 ans.endIndex = end;
	 return ans;
 }

 void printResult(MSA ans)
 {
	 std::cout << "\nResult:\n";
	 std::cout << "   Beginning Index: " << ans.begIndex << "\n";
	 std::cout << "   Ending Index: " << ans.endIndex << "\n";
	 std::cout << "   Sum: " << ans.sum << "\n";
	 std::cout << "   RunTime: " << ans.time << " seconds\n";
 }


void readInTestData(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		inputFile >> arr[i];
	}
}

void printArr(int *arr, int n)
{
	std::cout << "Array elements [";
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "]\n";
}

bool checkAnswers(MSA *ans, int *res)
{
	bool correct = 1;
	for (int i = 0; i < 7; i++)
	{
		std::cout << "Test Array " << i + 1 << ": ";
		if (ans[i].sum != res[i])
		{
			correct = 0;
			std::cout << "FAILED\n";
			break;
		}
		std::cout << "PASSED\n";
	}
	return correct;
}

int main(int argc, char **argv)
{
	int *testArr1, *testArr2, *testArr3, *testArr4, *testArr5, *testArr6, *testArr7;
	testArr1 = new int[16];
	testArr2 = new int[15];
	testArr3 = new int[12];
	testArr4 = new int[10];
	testArr5 = new int[9];
	testArr6 = new int[10];
	testArr7 = new int[9];
	inputFile.open("MSS_testProblems.txt", std::ios::in);
	if (!inputFile.is_open())
	{
		std::cout << "ERROR:Could not open input file\n";
		return 1;
	}
	outputFile.open("resultsLog.txt", std::ios::out);
	if (!outputFile.is_open())
	{
		std::cout << "ERROR:Could not open output file\n";
		return 1;
	}

	readInTestData(testArr1, 16);
	printArr(testArr1, 16);
	readInTestData(testArr2, 15);
	printArr(testArr2, 15);
	readInTestData(testArr3, 12);
	printArr(testArr3, 12);
	readInTestData(testArr4, 10);
	printArr(testArr4, 10);
	readInTestData(testArr5, 9);
	printArr(testArr5, 9);
	readInTestData(testArr6, 10);
	printArr(testArr6, 10);
	readInTestData(testArr7, 9);
	printArr(testArr7, 9);

	MSA answers[7];
	answers[0] = iterAlg1(testArr1, 16);
	answers[1] = iterAlg1(testArr2, 15);
	answers[2] = iterAlg1(testArr3, 12);
	answers[3] = iterAlg1(testArr4, 10);
	answers[4] = iterAlg1(testArr5, 9);
	answers[5] = iterAlg1(testArr6, 10);
	answers[6] = iterAlg1(testArr7, 9);

	MSA answers2[7];
	answers2[0] = iterAlg2(testArr1, 16);
	answers2[1] = iterAlg2(testArr2, 15);
	answers2[2] = iterAlg2(testArr3, 12);
	answers2[3] = iterAlg2(testArr4, 10);
	answers2[4] = iterAlg2(testArr5, 9);
	answers2[5] = iterAlg2(testArr6, 10);
	answers2[6] = iterAlg2(testArr7, 9);

	MSA answers3[7];
	answers3[0] = RecAlg3(testArr1, 16);
	answers3[1] = RecAlg3(testArr2, 15);
	answers3[2] = RecAlg3(testArr3, 12);
	answers3[3] = RecAlg3(testArr4, 10);
	answers3[4] = RecAlg3(testArr5, 9);
	answers3[5] = RecAlg3(testArr6, 10);
	answers3[6] = RecAlg3(testArr7, 9);

	MSA answer4[7];
	answer4[0] = Alg4(testArr1, 16);
	answer4[1] = Alg4(testArr2, 15);
	answer4[2] = Alg4(testArr3, 12);
	answer4[3] = Alg4(testArr4, 10);
	answer4[4] = Alg4(testArr5, 9);
	answer4[5] = Alg4(testArr6, 10);
	answer4[6] = Alg4(testArr7, 9);
	std::cout << "\n*****ALGORITHM 1 OUTPUT*****\n";
	for (int i = 0; i < 7; i++)
	{
		printResult(answers[i]);
	}
	std::cout << "\n*****ALGORITHM 2 OUTPUT*****\n";
	for (int i = 0; i < 7; i++)
	{
		printResult(answers2[i]);
	}

	std::cout << "\n*****ALGORITHM 3 OUTPUT*****\n";
	for (int i = 0; i < 7; i++)
	{
		printResult(answers3[i]);
	}
	std::cout << "\n*****ALGORITHM 4 OUTPUT*****\n";
	for (int i = 0; i < 7; i++)
	{
		printResult(answer4[i]);
	}

	std::cout << "\n\nUNIT TESTS: ALGORITHM 1\n";
	int checkAnswersNum[] = { 34,30,50,187,7,210,6};
	bool correct = checkAnswers(answers2, checkAnswersNum);
	if (correct == true)
	{
		std::cout << "Unit test Algorithm 1: PASSED\n";
	}
	else
	{
		std::cout << "Unit test Algorithm 1: Failed\n";
	}

	std::cout << "\n\nUNIT TESTS: ALGORITHM 2\n";
	correct = checkAnswers(answers, checkAnswersNum);
	if (correct == true)
	{
		std::cout << "Unit test Algorithm 2: PASSED\n";
	}
	else
	{
		std::cout << "Unit test Algorithm 2: Failed\n";
	}

	std::cout << "\n\nUNIT TESTS: ALGORITHM 3\n";
	correct = checkAnswers(answers3, checkAnswersNum);
	if (correct == true)
	{
		std::cout << "Unit test Algorithm 3: PASSED\n";
	}
	else
	{
		std::cout << "Unit test Algorithm 3: Failed\n";
	}

	std::cout << "\n\nUNIT TESTS: ALGORITHM 4\n";
	correct = checkAnswers(answer4, checkAnswersNum);
	if (correct == true)
	{
		std::cout << "Unit test Algorithm 4: PASSED\n";
	}
	else
	{
		std::cout << "Unit test Algorithm 4: Failed\n";
	}

	inputFile.close();
	std::cout << "********************Press ENTER to exit program********************";
	std::cin.get();
	return 0;
}
/*
Given an array arr[] and a number of queries, where in each query we have to check whether a subset whose sum is equal to given number exists in the array or not.

Examples:

Input : arr[]   = {1, 2, 3};
        query[] = {5, 3, 8}  
Output : Yes, Yes, No
There is a subset with sum 5, subset is {2, 3}
There is a subset with sum 3, subset is {1, 2}
There is no subset with sum 8.

Input : arr[] = {4, 1, 5};
        query[] = {7, 9}
Output : No, Yes
There is no subset with sum 7.
There is a subset with sum 9, subset is {4, 5}
Ans:

Let us consider arr[] = {3, 1, 5}, we need 
to whether a subset sum of x exists or not, 
where 0 ≤ x ≤ Σarri.

We create a bitset bit[10] and reset all the  
bits to 0, i.e., we make it 0000000000.

Set the 0th bit, because a subset sum of 0 
exists in every array.
Now, the bit array is 0000000001

Apply the above technique for all the elements
of the array :
Current bitset = 0000000001

After doing "bit = bit | (bit << 3)", 
bitset becomes	0000001001


After doing "bit | (bit << 1)", 
bitset becomes	0000011011


After doing "bit | (bit << 5)", 
bitset becomes	1101111011	


*/
#include <bits/stdc++.h>
using namespace std;

// Maximum allowed query value
# define MAXSUM 11

// function to check whether a subset sum equal to n
// exists in the array or not.
void processQueries(int query[], int nq, bitset<MAXSUM> bit)
{
	// One by one process subset sum queries
	for (int i=0; i<nq; i++) {
		int x = query[i];

		// If x is beyond size of bit[]
		if (x >= MAXSUM) {
			cout << "NA, ";
			continue;
		}

		// Else if x is a subset sum, then x'th bit
		// must be set
		bit[x]? cout << "Yes, " : cout << "No, ";
	}
}
void printArr( bitset<MAXSUM> &bit, int n )
{
    for (int i = n-1; i >=0; --i) {
        std::cout<<bit[i];
    }
    std::cout<<std::endl;
}

// function to store all the subset sums in bit vector
void preprocess(bitset<MAXSUM> &bit, int arr[], int n)
{
	// set all the bits to 0
	bit.reset();

	// set the 0th bit because subset sum of 0 exists
	bit[0] = 1;

	// Process all array elements one by one
	for (int i = 0; i < n; ++i) {
		// Do OR of following two
		// 1) All previous sums. We keep previous value
		// of bit.
		// 2) arr[i] added to every previous sum. We
		// move all previous indexes arr[i] ahead.
		std::cout<<"before: "<<arr[i]<<"  "<<bit<<std::endl;
		bit |= (bit << arr[i]);
		std::cout<<"after: "<<arr[i]<<"  "<<bit<<std::endl;
        	//printArr(bit, n);
    	}
}

// Driver program
int main()
{
	int arr[] = {3, 1, 5};
	int query[] = {8, 7};

	int n = sizeof(arr) / sizeof(arr[0]);
	int nq = sizeof(query) / sizeof(query[0]);

	// a vector of MAXSUM number of bits
	bitset<MAXSUM> bit;

	preprocess(bit, arr, n);
	//printArr(bit, n);
	processQueries(query, nq, bit);

	return 0;
}


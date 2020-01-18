// C++ program to print the number of elements 
// greater than k in a subarray of range L-R. 
#include <bits/stdc++.h> 
using namespace std; 

// Structure which will store both 
// array elements and queries. 
struct node { 
	int pos; 
	int l; 
	int r; 
	int val; 
}; 

// Boolean comparator that will be used 
// for sorting the structural array. 
bool comp(node a, node b) 
{ 
	// If 2 values are equal the query will 
	// occur first then array element 
	if (a.val == b.val) 
		return a.l > b.l; 

	// Otherwise sorted in descending order. 
	return a.val > b.val; 
} 

// Updates the node of BIT array by adding 
// 1 to it and its ancestors. 
void update(int* BIT, int n, int idx) 
{ 
	while (idx <= n) { 
		BIT[idx]++; 
		idx += idx & (-idx); 
	} 
} 
// Returns the count of numbers of elements 
// present from starting till idx. 
int query(int* BIT, int idx) 
{ 
	int ans = 0; 
	while (idx) { 
		ans += BIT[idx]; 

		idx -= idx & (-idx); 
	} 
	return ans; 
} 

// Function to solve the queries offline 
void solveQuery(int arr[], int n, int QueryL[], 
				int QueryR[], int QueryK[], int q) 
{ 
	// create node to store the elements 
	// and the queries 
	node a[n + q + 1]; 
	// 1-based indexing. 

	// traverse for all array numbers 
	for (int i = 1; i <= n; ++i) { 
		a[i].val = arr[i - 1]; 
		a[i].pos = 0; 
		a[i].l = 0; 
		a[i].r = i; 
	} 

	// iterate for all queries 
	for (int i = n + 1; i <= n + q; ++i) { 
		a[i].pos = i - n; 
		a[i].val = QueryK[i - n - 1]; 
		a[i].l = QueryL[i - n - 1]; 
		a[i].r = QueryR[i - n - 1]; 
	} 

	// In-built sort function used to 
	// sort node array using comp function. 
	sort(a + 1, a + n + q + 1, comp); 

	// Binary Indexed tree with 
	// initially 0 at all places. 
	int BIT[n + 1]; 

	// initially 0 
	memset(BIT, 0, sizeof(BIT)); 

	// For storing answers for each query( 1-based indexing ). 
	int ans[q + 1]; 

	// traverse for numbers and query 
	for (int i = 1; i <= n + q; ++i) { 
		if (a[i].pos != 0) { 

			// call function to returns answer for each query 
			int cnt = query(BIT, a[i].r) - query(BIT, a[i].l - 1); 

			// This will ensure that answer of each query 
			// are stored in order it was initially asked. 
			ans[a[i].pos] = cnt; 
		} 
		else { 
			// a[i].r contains the position of the 
			// element in the original array. 
			update(BIT, n, a[i].r); 
		} 
	} 
	// Output the answer array 
	for (int i = 1; i <= q; ++i) { 
		cout << ans[i] << endl; 
	} 
} 

// Driver Code 
int main() 
{ 
	int arr[] = { 7, 3, 9, 13, 5, 4 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	// 1-based indexing 
	int QueryL[] = { 1, 2 }; 
	int QueryR[] = { 4, 6 }; 

	// k for each query 
	int QueryK[] = { 6, 8 }; 

	// number of queries 
	int q = sizeof(QueryL) / sizeof(QueryL[0]); 

	// Function call to get 
	solveQuery(arr, n, QueryL, QueryR, QueryK, q); 

	return 0; 
} 

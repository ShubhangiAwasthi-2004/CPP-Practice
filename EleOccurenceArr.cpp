//code for occurence of element in array without hashing.

#include<bits/stdc++.h>
using namespace std;
 
void countDistinct(int arr[], int n)
{

    sort(arr, arr + n);
 
    // Traverse the sorted array
    for (int i = 0; i < n; i++){
        int count = 1;

        // Move the index ahead whenever
        // you encounter duplicates.
        while (i < n - 1 && arr[i] == arr[i + 1]){
            i++;
            count++;
        }
        
        cout << arr[i] << ": " << count << endl;
    }
 
}
 
// Driver program to test above function
int main()
{
    int arr[] = {5, 8, 5, 7, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    countDistinct(arr, n);
    return 0;
}

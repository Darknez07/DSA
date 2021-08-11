#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
int calls = 0;
// Logic of merge Left and Right sub array
// To final array
void Merge(vector<int> L, vector<int> R, vector<int>& A){
    // length of Left subarray
    int nl = L.size();
    // Length of Right subarray
    int rl = R.size();
    // k for counting the position at Array A
    // i, j for left and right subarrays respectivelys
    int k = 0,i = 0,j = 0;
    while(i < nl &&  j < rl){
        // Comparey the ith of left
        // And jth of right subarray
        // TO find the element in the location of
        // A
        if(L[i] <= R[j]){
            // Add left one to A
            // Increase or advance in L
            A[k]  = L[i];
            i++;
        }else{
            // Add right one to A
            // Advance in R
            A[k] = R[j];
            j++;
        }
        // Advance in A
        k++;
    }
    //Finally we don't have to worry about k
    // exceeding the limit
    // Because left and right subarrays are part of A
    // and with k we are keeping track of A

    // Only one of the two while loops will run
    while(i < nl){
        // If there are still values left
        // We need to fill those
        A[k] = L[i];
        i++;
        k++;
    }
    // Then we need to fill if Right subarrays are
    // left
    while(j < rl){
        A[k] = R[j];
        j++;
        k++;
    }
    calls++;
}
void Merge_sort(vector<int>&  A){
    calls++;
    int n = A.size();
    if(n < 2) return; // Base case when array length is 1
    int mid = n/2; // Finding the mid of array.
    // Left subarray
    vector<int> L(A.begin(), A.begin() + mid); // Filling till mid
    // Right subarray
    vector<int> R(A.begin() + mid, A.end()); // Filling from mid until end
    // Merge sort on Left subarray
    Merge_sort(L);
    // Merge sort on Right subarray
    Merge_sort(R);
    // Finally merging those two sorted lists
    // Basically sort them out
    Merge(L,R,A);
}
int main(){
    int n = 25;
    vector<int> v(n);
    srand(time(NULL));
    for(int i=0;i<n;i++){
        v[i] = rand() % (n + 100);
    }
    cout<<"Before sorting: "<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    Merge_sort(v);
    cout<<endl<<"After sorting: "<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<"Number of function calls: "<<calls<<endl;
}
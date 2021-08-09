#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
// Show function for debugging
// And reducing the code reuse
void Show(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return;
}
// Outputs the function of the place where
// Partition is sorted till "p" index
int Partition(vector<int> & A, int start, int end){
    // Pivot is chosen at the end element
    int pivot = A[end];
    // Start index is the "p"
    int p = start;
    // Temp for swap;
    int temp;
    // Go from start index to end index within array
    for(int i=start;i<end;i++){
        // Swap all the elements in the
        // array range which are lesser than or equal to pivot.
        // Basically shifting to left
        // of the considered array
        if(A[i] <= pivot){
            temp = A[i];
            A[i] = A[p];
            A[p] = temp;
            // Increasing the partition index.
            p++;
        }
    }
    // swapping the pivot to partition index.
    // Not necessarily the last element in the array
    A[end] = A[p];
    A[p] = pivot;
    return p;
}
void QuickSort(vector<int>& A, int start, int end){
    // End if the last is reached
    // Because start and end collied
    // Or start is already ahead.
    if(start >= end) return;
    int p = Partition(A, start, end);
    // Start to partition "p - 1" is found
    QuickSort(A, start, p - 1);
    // "p + 1" to end.
    QuickSort(A, p + 1, end);
    // Hence p is the pivot index
}
int main(){
    int n = 10;
    vector<int> v(n);
    srand(time(NULL));
    for(int i=0; i<n; i++){
        v[i] = rand() % (n + 100);
    }
    cout<<"Before sort: "<<endl;
    Show(v);
    QuickSort(v, 0, v.size() - 1);
    cout<<endl<<"After sort: "<<endl;
    Show(v);
    return 0;
}
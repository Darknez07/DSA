#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
// Count of swaps
int swaps = 0;
void Insertion_sort(vector<int> &v){
    // Size of the vector
    int n = v.size();
    // This is for storing.
    int val;
    for(int i=1;i<n;i++){
        // Store the present val
        val = v[i];
        // Declare j
        int j;
        // Intialize j with current index
        //check if previous element is greater than val
        // And shift to right
        //Until the it becomes equal or lesser
        // Greater than zero because "j - 1" will
        // cover "0";
        for(j=i;j>0 && v[j - 1] > val;j--){
            v[j] = v[j - 1];
            swaps++;
        }
        // Finally the optimal position has been found for
        // the val.
        v[j] = val;
    }
}
int main(){
    int n = 20;
    srand(time(NULL));
    vector<int> v(n);
    for(int i=0;i<n;i++)
        v[i] = i;
    cout<<"Before Sorting"<<endl;
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
    Insertion_sort(v);
    cout<<"After Sorting"<<endl;
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl<<"Number of swaps: "<<swaps<<endl;
}
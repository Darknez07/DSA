#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
int swaps = 0;
// Bubble sort is like bubbling up the max
// to right most side.
void Bubble_sort(vector<int> & v){
    // Size of array
    int n = v.size();
    // To keep track of swap in one pass
    int flag = 0;
    // Swapper
    int temp;
    // Because the left most will already be sorted
    for(int i=0;i<n-1;i++){
        // No swaps intially
        flag = 0;
        // The for loop is like till the wall
        // and the last i elements comprise of right side
        // of the wall
        for(int j=0;j<n - 1 - i ; j++){
            // Ascending order
            if(v[j] > v[j + 1]){
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                swaps++;
                flag = 1;
                // So swap occurs
            }
        }
        // No swap
        // That means sorted
        if(flag == 0)
            break;
    }
}
int main(){
    int n = 20;
    vector<int> v(n);
    srand(time(NULL));
    for(int i=0; i<n; i++)
        v[i] = rand() % (n + 100);
    cout<<"Before Sorting: "<<endl;
    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";
    Bubble_sort(v);
    cout<<"\nAfter Sorting: "<<endl;
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
    cout<<"Number of swaps: "<<swaps<<endl;
}
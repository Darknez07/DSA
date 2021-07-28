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
    int n = 200000;
    vector<int> v(n);
    srand(time(NULL));
    for(int i=0; i<n; i++)
        v[i] = rand() % (n + 100);
    cout<<"Before Sorting: "<<endl;
    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";

    // Time calculation of code
    clock_t begin = clock();
    Bubble_sort(v);
    clock_t end = clock();
    double ans = double(end - begin)/CLOCKS_PER_SEC;

    cout<<endl<<ans<<endl;
    cout<<"\nAfter Sorting: "<<endl;
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
    cout<<"Number of swaps: "<<swaps<<endl;
}
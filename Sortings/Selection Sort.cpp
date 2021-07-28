#include <iostream>
#include <vector>
using namespace std;
int comp = 0;
int swaps = 0;
// Selection sort is not stable
// Space complexity is is O(1)
void Selection_sort(vector<int> &v){
    int n = v.size();
    int min_index = -1;
    int temp;
    // Going from 0 to n - 2 cause last
    // one will be automatically sorted
    for(int i=0;i<n-1;i++){
        // i + 1 reduces the search space
        // with each ith iteration.
        min_index = i;
        for(int j = i + 1;j<n;j++){
            // Find the minimum element's index
            if(v[j] < v[min_index]){
                min_index = j;
                comp++;
            }
        }
        // New condition, It is sorted if min_index = i
        // So break;
        if(i == min_index)
            break;
        // Swap the minimum element with the current
        // start of search space.
        temp = v[i];
        v[i] = v[min_index];
        v[min_index] = temp;
        swaps++;
    }
    // As selection sort uses two for loops
    // The time complexity is O(n^2)
}
int main(){
    int n = 50;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        v[i] = rand() % (n + 100);
    cout<<"Before Sorting"<<endl;
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
    Selection_sort(v);
    cout<<"After Sorting"<<endl;
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
    cout<<"Number of comparisons: "<<comp<<endl;
    cout<<"Number of swaps: "<<swaps<<endl;
    return 0;
}
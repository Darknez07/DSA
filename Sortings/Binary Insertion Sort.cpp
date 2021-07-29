#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
// Count the number of swaps
int swaps = 0;
// Search for the lowest element by binary search
// for sorted part
int Binary_search(vector<int> v, int item, int low, int high){
    // If high decreases below high
    if(high <= low)
        // If low index has gr8ter element than item
        // Return low(index)
        // Else low + 1
        return (v[low] > item)? low : low + 1;
    // Mid place
    int mid = (high + low)/2;
    if(v[mid] == item)
    // Found item and return index
        return mid + 1;
    if(item > v[mid])
        // Search in the right subarray
        return Binary_search(v, item, mid + 1, high);
    // Search in left subarray
    return Binary_search(v, item, low, mid - 1);
}
void Insertion_sort(vector<int>& v){
    int n = v.size();
    int j,selected,loc;
    // Three variables j, selected is element
    // loc is the answer where it goes
    for(int i=1;i<n;i++){
        // All the indexes before
        // Are sorted
        // So j is  "i - 1"
        j = i - 1;
        // Selected is the given index element
        selected = v[i];
        // Find the loc of where to place the selected
        // element from the array
        loc = Binary_search(v,selected,0,j);
        while(j >= loc){
            // Until location is reached shift
            // To left
            v[j + 1] = v[j];
            j--;
            // Count the swaps
            swaps++;
        }
        // j+1 because last time loop executes
        // The counter has been decreased to loc - 1;
        // Finally reached location
        v[j + 1] = selected;
    }
}
int main(){
    int n = 20;
    srand(time(NULL));
    vector<int> v(n);
    for(int i=0;i<n;i++)
        v[i] = rand() % (n + 100);
    cout<<"Before Sorting"<<endl;
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
    Insertion_sort(v);
    cout<<"After Sorting"<<endl;
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl<<"Number of sawps: "<<swaps<<endl;
    return 0;
}
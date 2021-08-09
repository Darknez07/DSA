#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
int calls = 0;
void Show(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return;
}
void QuickSortMiddle(vector<int>& v, int left, int right){
    if(left >= right) return;
    calls++;
    int l = left;
    int r = right;
    int temp;
    int pivot = v[left + (right - left)/2];
    while(l <= r){
        while(v[l] < pivot) l++;
        while(v[r] > pivot) r--;
        if(l <= r){
            temp = v[l];
            v[l] = v[r];
            v[r] = temp;
            l++;
            r--;
        }
    }
    if(left < r) QuickSortMiddle(v,left,r);
    if(l < right) QuickSortMiddle(v,l,right);
    return;
}
int main(){
    int n = 1000;
    srand(time(NULL));
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        v[i] = rand() % (n + n + n + n);
    }
    cout<<"Before Sorting: "<<endl;
    Show(v);
    QuickSortMiddle(v,0,v.size() - 1);
    cout<<endl<<"After Sorting: "<<endl;
    Show(v);
    cout<<endl<<"Number of calls: "<<calls<<endl;
}
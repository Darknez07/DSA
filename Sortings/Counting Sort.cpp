#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
void Show(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return;
}
void Counting_sort(vector<int> &v){
    int max = v[0];
    for(int i=0;i<v.size();i++){
        if(v[i] > max){
            max = v[i];
        }
    }
    vector<int> counter(max + 1,0);
    for(int i=0;i<v.size();i++){
        counter[v[i]]++;
    }
    for(int i=1;i<max+1;i++){
        counter[i]+=counter[i - 1];
    }
    vector<int> ans(v.size());
    for(int i=0;i<v.size();i++){
        ans[counter[v[i]] - 1] = v[i];
        counter[v[i]]--;
    }
    v = ans;
}
int main(){
    int n = 10;
    srand(time(NULL));
    vector<int> v(n);
    for(int i=0;i<n;i++){
        v[i] = rand() %(n + n);
    }
    cout<<"Before Sorting:"<<endl;
    Show(v);
    Counting_sort(v);
    cout<<endl<<"After Sorting:"<<endl;
    Show(v);
    return 0;
}
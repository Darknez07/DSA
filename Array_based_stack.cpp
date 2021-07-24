#include <iostream>
using namespace std;
#define max 101
int a[max];
int top = -1;
void Push(int x){
    if(top == max - 1){
        cout<<"Stack filled"<<endl;
        return;
    }
    a[++top] = x;
    return;
}
void Pop(){
    if(top == -1){
        cout<<"Stack empty"<<endl;
        return;
    }
    top--;
}
int Top(){
    if(top == -1 || top == max)
        return -1;
    return a[top];
}
bool IsEmpty(){
    if(top == -1)
        return true;
    return false;
}
void Print(){
    while(!IsEmpty()){
        cout<<Top()<<endl;
        Pop();
    }
}
main(){
    int a[10] = {1,2,4,5,6,3,8,9,10,11};
    for(int i=0;i<10;i++){
        Push(a[i]);
    }
    Pop();
    Print();
    Pop();
    cout<<Top()<<endl;
}

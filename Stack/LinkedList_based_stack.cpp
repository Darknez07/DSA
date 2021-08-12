#include <iostream>
using namespace std;
#define sz 100
struct Node{
    int data;
    Node * link;
    Node(int a,Node *l){data = a;link=l;}
};
Node *top = nullptr;
void Push(int a){
    Node * t = new Node(a,nullptr);
    if(!top){
        top = t;
        return;
    }
    t->link = top;
    top = t;
}
void Pop(){
    if(!top){cout<<"Stack underflowed"<<endl;return;}
    top = top->link;
}
int Top(){
    if(!top){cout<<"Stack is empty"<<endl;return -1;}
    return top->data;
}
bool isEmpty(){
    if(!top)
        return true;
    return false;
}
main(){
    int a[8] = {1,3,2,4,5,6,8,9};
    for(int i=0;i<8;i++){
        Push(a[i]);
    }
    for(int i=0;i<sz;i++)
      Push(rand()%100);
    while(!isEmpty()){
        cout<<Top()<<endl;
        Pop();
    }
}
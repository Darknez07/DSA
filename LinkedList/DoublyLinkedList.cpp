#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next = nullptr,*prev = nullptr;
    Node(int d){data=d;}
    Node(int d,Node* nxt, Node* prv){data=d;next=nxt;prev=prv;}
};
Node *head = nullptr;
Node *tail = nullptr;
void Insert_begin(int a){
    Node *t = new Node(a);
    if(!head){
        head = t;
        tail = t;
        return;
    }else{
        head->prev = t;
        t->next = head;
        head = t;
    }
}
void Insert_end(int a){
    Node *t = new Node(a);
    if(!tail){
        head = t;
        tail = t;
        return;
    }else{
        tail->next = t;
        t->prev = tail;
        tail = t;
    }
}
void Print(){
    cout<<"---FORWARD---"<<endl;
    Node *p = head;
    while(p->next){
        cout<<p->data<<"->";
        p = p->next;
    }
    cout<<p->data;
    cout<<endl;
    cout<<"---BACKWARD--"<<endl;
    Node *t = tail;
    while(t->prev){
        cout<<t->data<<"->";
        t = t->prev;
    }
    cout<<t->data;
    cout<<endl;
}
main(){
    int a[10] = {1,2,3,5,7,8,9,12,11,0};
    for(int i=0;i<10;i++){
        if(i % 2)
            Insert_begin(a[i]);
        else
            Insert_end(a[i]);
    }
    Print();
}
#include <iostream>
using namespace std;
struct Node{
    int data;
    // I mean cpp is awesome
    Node(int d){data=d;}
    Node* next = nullptr;
    //This really helps
    Node(int d, Node* n){data=d;next=n;}
};
Node *head = nullptr ;
void Insert(int a){
    Node* to_insert = new Node(a);
    if(!head){
        head = to_insert;
        return;
    }else{
        Node* t = head;
        while(t->next){
            t = t->next;
        }
        t->next = to_insert;
    }
}
int length(){
    int l = 0;
    Node *n = head;
    while(n){
        n = n->next;
        l++;
    }
    return l;
}
void Begin(int b){
    Node* t = new Node(b,head);
    head = t;
    return;
}
void Mid(int a, int pos){
    int len = length();
    if(pos == 1)
        Begin(a);
    else if(pos > len)
        Insert(a);
    else{
        Node *t = head;
        Node *val = new Node(a);
        while(t && pos--!=2)
            t = t->next;
        Node *f = t;
        Node *e = t->next;
        t->next = val;
        val->next = e;
        return;
    }
}
void Del_at_pos(int pos){
    Node* t = head;
    int len = length();
    if(pos < 1 || pos > len) return;
    if(pos == 1){
        head = t->next;
        free(t);
        return;
    }
    while((pos--)>2)
        t = t->next;
    Node* q = t->next;
    t->next = q->next;
    free(q);
}
void Iterative_rev(){
    Node * curr = head;
    Node * prev = nullptr;
    Node * nxt;
    while(curr){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
}
void Print(){
    Node* l = head;
    cout<<endl;
    while(l->next){
        cout<<l->data<<"->";
        l = l->next;
    }
    cout<<l->data;
    cout<<endl;
}
// Iterative call is better for simple printing
void Print_using_recursion(Node* h){
    if(!h) return;
    cout<<h->data<<"->";
    Print_using_recursion(h->next);
}
// Recursive call is better for reverse printing
void Print_rev_recursion(Node* h){
    if(!h) return;
    Print_rev_recursion(h->next);
    cout<<h->data<<"->";
}
void Revrese_recursion(Node *h){
    if(!h->next){
        head = h;
        return;
    }
    // 1->2->3->4
    // Consider 2->3->4;
    // Now h = 3;
    // p = 4;
    // p->next = 3;
    //h->next = null
    // Next call p = 3;
    // h = 2;
    Revrese_recursion(h->next);
    Node* p = h->next;
    p->next = h;
    h->next = nullptr;
}
main(){
    Del_at_pos(1);
    Del_at_pos(10);
    Print();
    Iterative_rev();
    Print_rev_recursion(head);
    // Print_using_recursion(head);
}
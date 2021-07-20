#include <iostream>
#include <string>
using namespace std;
template<typename T>
struct Node{
    T data;
    Node* link = nullptr;
    Node(T d){data=d;}
};
template<class Tx>
class Stack{
    private:
        Node<Tx> *top = nullptr;
    public:
        void Push(Tx x){
            if(!top){
                top = new Node<Tx>(x);
                return;
            }
            Node<Tx> *n = new Node<Tx>(x);
            n->link = top;
            top = n;
        }
        void Pop(){
            if(!top){cout<<"Stack is empty!"<<endl;return;}
            top = top->link;
        }
        Tx Top(){
            if(!top){cout<<"Stack is empty!"<<endl;return '\0';}
            return top->data;
        }
        bool IsEmpty(){return !top;}
};
#include <iostream>
#include <string>
using namespace std;
template<typename T>
struct Node{
    T data;
    Node * next = nullptr;
    Node(T d){data=d;}
};
template<class T>
class queue{
    private:
        Node<T> * frnt = nullptr;
        Node<T> * rear = nullptr;
    public:
        void enqeue(T x){
            if(!rear){
                rear = new Node<T>(x);
                frnt = rear;
                return;
            }
            Node<T> *t = new Node<T>(x);
            rear->next = t;
            rear = t;
        }
        void dequeue(){
            if(!frnt){cout<<"Queue is empty"<<endl;return;}
            Node<T>* temp = frnt;
            frnt = frnt->next;
            if(frnt == nullptr)
                rear = nullptr;
            free(temp);
        }
        T front(){
            if(!frnt){cout<<"Nothing in the queue!"<<endl;exit(1);}
            return frnt->data;
        }
        bool isEmpty(){
            return !frnt;
        }
};
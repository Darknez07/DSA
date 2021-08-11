#include "stck.hpp"
using namespace std;
string operators = "*/+-";
bool HighPrec(char ch, char ch2){
    if(ch == '*' && ch2 == '/')
        return false;
    if((ch == '+' || ch == '-') || (ch =='*' || ch2 == '/'))
        return false;
    return true;
}
string Infix_to_postfix(string infix){
    Stack<char>* ops = new Stack<char>();
    string posfix="";
    for(int i=0;i<infix.length();i++){
        if(operators.find(infix[i])!=string::npos){
            while(!ops->IsEmpty() && HighPrec(ops->Top(), infix[i])){
                posfix+=(ops->Top());
                ops->Pop();
            }
            ops->Push(infix[i]);
        }else{
            posfix+=infix[i];
        }
    }
    while(!ops->IsEmpty()){
        posfix+=ops->Top();
        ops->Pop();
    }
    return posfix;
}
int solve_postfix(string s){
    int a,b;
    Stack<int> * stck = new Stack<int>();
    for(int i=0;i<s.length();i++){
        if(operators.find(s[i])==string::npos){
            stck->Push(s[i] - '0');
            continue;
        }
        size_t loc = operators.find(s[i]);
        a = stck->Top();
        stck->Pop();
        b = stck->Top();
        stck->Pop();
        if(loc == 0){
            b*=a;
        }else if(loc == 1){
            b/=a;
        }else if(loc == 2){
            b+=a;
        }else{
            b-=a;
        }
        stck->Push(b);
    }
    return stck->Top();
}
main(){
    string s;
    string infix ="4-5+9*4/2-4+6/3-1+9/3-9+7/2*4";
    s = Infix_to_postfix(infix);
    cout<<solve_postfix(s)<<endl;
}
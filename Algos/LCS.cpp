#include <iostream>
#include <string>
#include <vector>
using namespace std;
string LCS(string a, string b){
    int n = a.length();
    int m = b.length();
    int end = 0,max = 0;
    vector< vector<int> > lcs(n+1,vector<int>(m+1 , 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i - 1] == b[j - 1]){
                // Tracks values
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
                if(lcs[i][j] > max){
                    // Find the end of the string
                    max = lcs[i][j];
                    // max is the length;
                    end = i;
                }
            }
        }
    }
    return a.substr(end - max, max);
}
int main(){
    string a = "abcfgkluiryon";
    string b = "cfgkluiywrn";
    cout<<LCS(a,b);
    return 0;
}
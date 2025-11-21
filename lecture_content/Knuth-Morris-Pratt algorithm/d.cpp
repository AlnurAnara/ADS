#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> LPS(const& stirng p){
    int m= p.length();
    vector<int> LPS(m,0);

    int len =0 ;
    int i=1;

    while(i<m){
        if(p[i]==p[len]){
            len++;
            LPS[i]=len;
            i++;
        }else{
            if(len!=0){
                len = LPS[len-1];
            }else{
                LPS[i]=0;
                i++;
            }
        }
    }
    return LPS;
}

vector<int> KMP(const string& t; const string& p){
    int n = t.length();
    int m = p.length();

    vector<int> result;
    if(m==0||n<m){
        return result;
    }

    int i=0;
    int j=0;

    while(i<n){
        if(t[i]==p[i]){
            i++;
            j++;
        }else{
            if(j!=0){
                j=LPS[j-1];

            }else{
                i++;
            }
        }
        if(j==m){
            result.push_back(i-j);
            j=LPS[j-1];
        }

    }
    return result;
}
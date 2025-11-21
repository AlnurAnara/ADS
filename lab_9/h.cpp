#include <iostream>
#include <string>
#include <vector>

using namespace std;  

/*
Given a string s, 
calculate the number of ways to divide sinto 3 non-empty strings a,b,c
such that: a+b+c = s and a + c == b + c.

*/

vector<int> LPS(const string& p) {
    int m = p.length();
    vector<int> lps(m, 0);  
    
    int len = 0;  
    int i = 1;    
    
    while (i < m) {
        if (p[i] == p[len]) {
            
            len++;
            lps[i] = len;
            i++;
        } else {
           
            if (len != 0) {
               
                len = lps[len - 1];
            } else {
                
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> KMP(const string& t, const string& p) {
    vector<int> result;  
    
    int n = t.length();
    int m = p.length();
    
    if (m == 0 || n < m) {
        return result; 
    }
    
    
    vector<int> lps = LPS(p);
    
    int i = 0;  
    int j = 0;  
    
    while (i < n) {
        if (t[i] == p[j]) {
            
            i++;
            j++;
        } else {
            
            if (j != 0) {
                
                j = lps[j - 1];
            } else {
                
                i++;
            }
        }
        
        
        if (j == m) {
            
            result.push_back(i - j);
          
            j = lps[j - 1];
        }
    }
    
    return result;
}
int main() {
    string s;
    cin >> s;

    int n = s.size();
    vector<int> lps = LPS(s);

    long long cnt = 0;

    for (int L = 1; L * 2 < n; ++L) {
        bool ok = true;
        for (int i = 0; i < L; ++i) {
            if (s[i] != s[L + i]) {
                ok = false;
                break;
            }
        }
        if (ok) cnt++;
    }

    cout << cnt;
    return 0;
}
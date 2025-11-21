#include <iostream>
#include <string>
#include <vector>

using namespace std;  

/*The string s was written many times in a row, 
after which a substring was taken from the resulting string and given to you. 
Your task is to determine the minimum possible length of the original string s

Examples
Input
zzz
Output
1
Input
bcabcab
Output
3

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
    
    if (n == 0) {
        cout << 0;
        return 0;
    }

    vector<int> lps = LPS(s);
    int p = lps[lps.size()-1];
    cout << n - p;

    return 0;
}
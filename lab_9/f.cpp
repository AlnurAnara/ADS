#include <iostream>
#include <string>
#include <vector>

using namespace std;  

/*Given two strings s1 and s2 , find whether s1 is a substring of s2  
print indices of occurrences.  IMPORTANT!!!!!!!!!
Input
abacaba
aba
Output
2
1 5 
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
int main(){
    string s1,s2;
    cin >> s2 >> s1;
    // notice: the order of parameters,s2 is text and s1 is pattern
    vector<int> result = KMP(s2, s1);

    cout << result.size() << endl;
    for (int idx : result) {
        cout << idx + 1 << " ";  // Convert to 1-based indexing
    }
    cout << endl;
    

    return 0;
}
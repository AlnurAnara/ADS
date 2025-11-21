#include <iostream>
#include <string>
#include <vector>

using namespace std;  

/*It is known that the password is correct only if it occurs at least k times on a piece of paper that the Bank Director gave to Thomas.
Input
hello 2
helloThomashelloArthurhelloJohnhello
Output
YES
Input
kbtu 4
kbtuIsTheBestPlaceInTheWorld
Output
NO
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
    string s,t;
    int k;
    cin >> s >> k >> t;

    vector<int> result = KMP(t, s);
    if(result.size() >= k) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;  

/*print the minimum possible shift size or -1 if Alikhan is wrong
Examples
Input
zabcd
abcdz
Output
4

Input
abcde
decba
Output
-1
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
    cin >> s >> t;

    if (s.length() != t.length()) {
        cout << -1 << endl;
        return 0;
    }
    
    int n = s.length();
    
    // Create doubled string for cyclic shifts
    string doubled = s + s;
    
    // Use KMP to find all occurrences of t in doubled
    vector<int> matches = KMP(doubled, t);
    
    int min_shift = -1;
    
    for (int pos : matches) {
        // We only consider positions in the first half (cyclic shifts)
        if (pos < n) {
            int k = (n - pos) % n;
            if (min_shift == -1 || k < min_shift) {
                min_shift = k;
            }
        }
    }
    
    cout << min_shift << endl;
    return 0;
}
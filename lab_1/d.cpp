#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
You are given a string containing lowercase Latin letters . Determine if string is balanced.
Here is description of balanced strings:  字符串中所有字符出现次数相同：
1.empty string is balanced
2.if strings s and t are balanced, then string st (concatenation) is also balanced
3.if string s is balanced, then string xsx is balanced for any lowercase Latin letter x
.
对称！！！
For example, string abba is balanced, but string abbb is not.
*/
int main() {
    string s;
    cin >> s;
    stack<char> st;
    
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (!st.empty() && st.top() == c) {
            st.pop();
        } else {
            st.push(c);
        }
    }
    
    if (st.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
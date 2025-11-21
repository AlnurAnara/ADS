#include <iostream>
using namespace std;

int main() {
    string s,t;
    int k;
    cin >> s >> k >> t;

    int count =0;

    string res;
    size_t pos = 0;
    
    // Count occurrences of password in text
    while ((pos = t.find(s, pos)) != string::npos) {
        count++;
        pos++; // Move forward to find overlapping occurrences
    }

    if(count >= k) {
      cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;

    }

    return 0;
}
/*
You’re given two strings s and t;
You need to answer, can we take string t by copy and pasting string s.

*/
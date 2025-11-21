#include <iostream>
#include <algorithm>    
using namespace std;

/*
first, we need to print vowel letters first and then consonants, 
and both vowels and consonants are ordered alphabetically.
Input
5
abcde
Output
aebcd
Input
5
wlree
Output
eelrw
*/
bool isVowel(char c) {
    return (c == 'a' || c == 'o' || c == 'i' || c == 'e' || c == 'u');
}

bool cmp(char a, char b) {
    bool ok1 = isVowel(a);
    bool ok2 = isVowel(b);

    if (ok1 != ok2) return ok1;
    return a < b;
}

int main() {
    int n;
    string s;

    cin >> n >> s;

    sort(s.begin(), s.end(), cmp);

    cout << s;

    return 0;
}

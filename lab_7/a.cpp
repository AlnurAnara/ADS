#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

/*Given a set of strings print the set sorted according to their size. 
If the size of the strings are equal, must maintain the original order of the set

Input
3
ab cd e j asd ljffg df
a a b b c c
xy yx zxy zx xzy xxx
Output
e j ab cd df asd ljffg 
a a b b c c 
xy yx zx zxy xzy xxx 

*/

bool cmp(string a, string b){
    return a.size() < b.size();
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string line;
        getline(cin, line);
        if(line.empty()) getline(cin, line);

        stringstream ss(line);
        vector<string> v;
        string s;

        while (ss >> s) v.push_back(s);
        
        stable_sort(v.begin(), v.end(), cmp);

        for (int i = 0; i < v.size(); ++i)
            cout << v[i] << ' ';
        
        cout << '\n';
    }

    return 0;
}
/*
    Given two strings. Each string contains lower case English letters and the # symbol, which means you typed backspace. 
    Check if two strings are equal.
    Print single ‘Yes’ if they are equal or ‘No’ otherwise.
    #前的letter应该被删除
    e.g.
    a#b#c and a#c are equal.
*/

#include <iostream>
#include <queue>
using namespace std;

int main(){
    string s1, s2, string1, string2;
    cin >> s1 >> s2;
    
  
    for(int i = 0; i < s1.size(); i++){
        if(s1[i] == '#'){
            if (!string1.empty()) {
                 string1.pop_back();
            }
        }
        //the number before # should be deleted 
        else string1 += s1[i];
    }
    
  
    for(int i = 0; i < s2.size(); i++){
        if(s2[i] == '#'){
           if (!string1.empty()) {
                string1.pop_back();
            } 
        }
        else string2 += s2[i]; // if the current parameter isn't #,then add  it into the end of the string
    }
    
    if(string1 == string2) cout << "Yes";
    else cout << "No";
    
    return 0;
}
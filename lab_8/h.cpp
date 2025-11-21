//You have K strings, find the longest common substring of all K strings.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string findLongestCommonSubstring(const vector<string>& strs) {
    if (strs.empty()) return "";
    
    string first = strs[0];
    string result = "";
    
    // 枚举第一个字符串的所有子串
    for (int i = 0; i < first.length(); i++) {
        for (int j = i; j < first.length(); j++) {
            string candidate = first.substr(i, j - i + 1);
            
            // 检查是否在所有字符串中都出现
            bool found_in_all = true;
            for (int k = 1; k < strs.size(); k++) {
                if (strs[k].find(candidate) == string::npos) {
                    found_in_all = false;
                    break;
                }
            }
            
            // 更新最长公共子串
            if (found_in_all && candidate.length() > result.length()) {
                result = candidate;
            }
        }
    }
    
    return result;
}

int main() {
    int K;
    cin >> K;
    vector<string> strs(K);
    
    for (int i = 0; i < K; i++) {
        cin >> strs[i];
    }
    
    string result = findLongestCommonSubstring(strs);
    cout << result << endl;
    
    return 0;
}
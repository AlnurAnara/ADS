#include <iostream>
#include <vector>
using namespace std;

/*
    题目描述：
    有一个大磁带(longest tape)，上面写有小写字母。现在有 n 个小磁带(smaller tapes)，每个小磁带也写有小写字母。
    你需要判断，是否可以通过将这些小磁带在大磁带上进行覆盖（可以不连续），
    使得大磁带上的每个位置都被覆盖到。如果可以，输出 "YES"；否则输出 "NO"。
*/
int main() {
    string s;
    cin >> s;
    int len_s = s.length();
    
    int n;
    cin >> n;
    
    // 记录从每个位置开始能覆盖的最远距离
    vector<int> max_reach(len_s + 1, 0);
    
    // 处理每个小磁带
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        int len_t = t.length();
        
        if (len_t > len_s) continue;
        
        // 计算小磁带的简单哈希值
        long long hash_t = 0;
        for (char c : t) {
            hash_t = hash_t * 131 + c; 
            // 'abc'='a'×131² + 'b'×131 + 'c'
        }
        
        // 计算大磁带的前缀哈希
        vector<long long> prehash(len_s + 1, 0);
        vector<long long> power(len_s + 1, 1);
        
        for (int j = 1; j <= len_s; j++) {
            power[j] = power[j - 1] * 131;
            prehash[j] = prehash[j - 1] * 131 + s[j - 1];
            //prehash[3] = 'a'×131² + 'b'×131 + 'c'
        }
        
        // 在大磁带中寻找匹配
        for (int start = 0; start + len_t <= len_s; start++) {
            // 计算子串哈希值
            long long sub_hash = prehash[start + len_t] - prehash[start] * power[len_t];
            
            if (sub_hash == hash_t) {
                bool match = true;
                for (int k = 0; k < len_t; k++) {
                    if (s[start + k] != t[k]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    max_reach[start] = max(max_reach[start], start + len_t);
                }
            }
        }
    }
    
    // 检查是否能覆盖整个磁带
    int current = 0;  // 当前已覆盖到的最右位置
    int pos = 0;
    
    while (pos < len_s && pos <= current) {
        current = max(current, max_reach[pos]);
        pos++;
    }
    
    if (current >= len_s) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
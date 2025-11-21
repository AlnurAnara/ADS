/*You have string S and q queries. Each query given a pair of integers L and R 
the answer for a query is number of times substring from L to R appears in S as substring.

i.e.
abracadabra    # 字符串 S = "abracadabra"
5              # 5 个查询
1 1            # 查询1：子串 S[1..1] 
1 2            # 查询2：子串 S[1..2]
3 4            # 查询3：子串 S[3..4] 
1 5            # 查询4：子串 S[1..5]
1 4            # 查询5：子串 S[1..4]
输出：
5              # "a" 出现了 5 次    
2              # "ab" 出现了 2 次
1              # "ra" 出现了 1 次   
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    int n = S.length();
    
    int q;
    cin >> q;
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;  // 转换为0-based索引
        
        string pattern = S.substr(l, r - l + 1);
        int pattern_len = pattern.length();
        int count = 0;
        
        // 搜索所有出现（包括重叠）
        for (int i = 0; i <= n - pattern_len; i++) {
            bool match = true;
            for (int j = 0; j < pattern_len; j++) {
                if (S[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                count++;
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}
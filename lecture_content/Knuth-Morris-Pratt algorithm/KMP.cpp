#include <iostream>
#include <string>
#include <vector>

using namespace std;  //o(n+m) time complexity

// 构建 LPS 数组
vector<int> LPS(const string& p) {  // O(n)
    int m = p.length();
    vector<int> lps(m, 0);  // lps[0] 总是 0
    
    int len = 0;  // 当前最长公共前后缀的长度
    int i = 1;    // 从第二个字符开始遍历
    
    while (i < m) {
        if (p[i] == p[len]) {
            // 当前字符匹配
            len++;
            lps[i] = len;
            i++;
        } else {
            // 当前字符不匹配
            if (len != 0) {
                // 如果之前有公共前后缀，回退到前一个lps值
                len = lps[len - 1];
            } else {
                // 没有公共前后缀
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP 搜索算法
vector<int> KMP(const string& t, const string& p) {
    vector<int> result;  // 存储匹配位置
    
    int n = t.length();
    int m = p.length();
    
    if (m == 0 || n < m) {
        return result;  // 模式串为空或比文本串长，直接返回空结果
    }
    
    // 构建 LPS 数组
    vector<int> lps = LPS(p);
    
    int i = 0;  // 文本串指针
    int j = 0;  // 模式串指针
    
    while (i < n) {
        if (t[i] == p[j]) {
            // 字符匹配，两个指针都前进
            i++;
            j++;
        } else {
            // 字符不匹配
            if (j != 0) {
                // 利用 LPS 表跳过不必要的比较
                j = lps[j - 1];
            } else {
                // j == 0，只能移动文本指针
                i++;
            }
        }
        
        // 检查是否找到完整匹配
        if (j == m) {
            // 找到匹配，记录位置
            result.push_back(i - j);
            // 继续寻找下一个可能的匹配
            j = lps[j - 1];
        }
    }
    
    return result;
}



int main() {
    string text, pattern;

    cout << "Enter text: ";
    getline(cin, text);  // 使用 getline 可以读取包含空格的文本

    cout << "Enter pattern: ";
    getline(cin, pattern);
    
    vector<int> result = KMP(text, pattern);
    
    // 显示搜索结果
    if (result.empty()) {
        cout << "Pattern not found in the text." << endl;
    } else {
        cout << "Pattern found at position(s): ";
        for (int pos : result) {
            cout << pos << " ";
        }
        cout << endl;
        cout << "Total matches: " << result.size() << endl;
    }
    
    // 可选：显示LPS数组用于调试
    cout << "\nLPS array for pattern '" << pattern << "': ";
    vector<int> lps = LPS(pattern);
    for (int val : lps) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    cin >> q;
    
    stack<int> mainStack;      // 主栈，存储所有元素
    stack<int> maxStack;       // 存储每个状态下的最大值
    
    while (q--) {
        string command;
        cin >> command;
        
        if (command == "add") {
            int x;
            cin >> x;
            
            // 入栈到主栈
            mainStack.push(x);
            
            // 更新最大值栈
            if (maxStack.empty()) {
                maxStack.push(x);
            } else {
                int currentMax = maxStack.top();
                maxStack.push(max(x, currentMax));
            }
        }
        else if (command == "delete") {
            if (!mainStack.empty()) {
                mainStack.pop();
                maxStack.pop();
            }
            // 如果栈为空，按照题目要求什么都不做
        }
        else if (command == "getcur") {
            if (mainStack.empty()) {
                cout << "error\n";
            } else {
                cout << mainStack.top() << "\n";
            }
        }
        else if (command == "getmax") {
            if (maxStack.empty()) {
                cout << "error\n";
            } else {
                cout << maxStack.top() << "\n";
            }
        }
    }
    
    return 0;
}
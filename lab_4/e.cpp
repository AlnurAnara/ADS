#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm> 
using namespace std;
/*

*/

struct Node {
    int left = 0; 
    int right = 0; 
};

int n;
vector<Node> tree; 
// lvl 数组用于存储每个节点的层级 (Level)

int lvl[10005]; 
int mx = 0; // 最大宽度初始化为 0

int main() {
    
    // 确保 tree 数组大小正确 (1 到 N)
    cin >> n;
    tree.resize(n + 1); 
    
    int a, b, c;
    
    // 1. 构建二叉树
    // 循环 N - 1 次读取边信息 (x: 父节点, y: 子节点, z: 方向)
    for(int i = 1; i < n; i++){
        cin >> a >> b >> c;
        
        // 关键修正：根据 z 正确建立单向的父子关系
        if (c == 0) {
            tree[a].left = b;
        } else { // c == 1
            tree[a].right = b;
        }
        // 修正：不再执行 graph[b].push_back(a)
    }
    
    // 2. BFS 计算所有节点的层级 (Level)
    // 节点编号从 1 开始
    fill(lvl + 1, lvl + n + 1, -1); // 初始化 lvl[1] 到 lvl[n] 为 -1
    lvl[1] = 0; // 根节点层级为 0
    
    queue<int> q;
    q.push(1);
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        // 遍历左子节点
        int left_child = tree[u].left;
        if(left_child != 0 && lvl[left_child] == -1){
            lvl[left_child] = lvl[u] + 1;
            q.push(left_child);
        }
        
        // 遍历右子节点
        int right_child = tree[u].right;
        if(right_child != 0 && lvl[right_child] == -1){
            lvl[right_child] = lvl[u] + 1;
            q.push(right_child);
        }
    }
    
    // 3. 统计每层节点数并找出最大宽度
    map<int, int> mp; // mp: 键为层级，值为该层节点数
    
    for(int i = 1; i <= n; i++){
        // 只有存在有效层级的节点才计数
        if (lvl[i] != -1) {
             mp[lvl[i]]++; // 统计该层级的节点数量
             mx = max(mx, mp[lvl[i]]); // 更新最大宽度
        }
    }
    
   
    cout << mx << endl;
    
    return 0;
}
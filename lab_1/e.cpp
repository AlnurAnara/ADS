#include <iostream>
#include <queue>
using namespace std;

/*
Boris和Nursik玩醉汉纸牌游戏。规则如下：
双方各有5张牌（每张牌的值在0到9之间，且所有牌的值互不相同）。
游戏开始时，双方各亮出自己牌堆的顶部一张牌。比较两张牌的大小：
牌值大的玩家赢得这两张牌，并将它们放入自己牌堆的底部：先放Boris的牌，再放Nursik的牌。
特殊规则：牌值0可以打败牌值9（即0 > 9）。
如果一方没有牌了，则另一方获胜。

输入格式
第一行：5个整数（用空格分隔），表示Boris的牌（从上到下顺序）。
第二行：5个整数（用空格分隔），表示Nursik的牌（从上到下顺序）
如果Boris获胜，输出 "Boris" 和获胜的轮数（用空格分隔）。

如果Nursik获胜，输出 "Nursik" 和获胜的轮数（用空格分隔）。
如果超过10轮未分胜负，输出 "Min ntchya"
*/
int main(){
    
    int a1, a2, a3, a4, a5;
    int b1, b2, b3, b4, b5;
    
    cin >> a1 >> a2 >> a3 >> a4 >> a5;
    cin >> b1 >> b2 >> b3 >> b4 >> b5;
    
    queue<int> q1, q2;
    
    q1.push(a1);
    q1.push(a2);
    q1.push(a3);
    q1.push(a4);    
    q1.push(a5);
    q2.push(b1);
    q2.push(b2);
    q2.push(b3);
    q2.push(b4);
    q2.push(b5);
    
    int cnt = 0;
    
    while(cnt <= 1000000 && !q1.empty() && !q2.empty()){
        cnt++;
        
        int a = q1.front(), b = q2.front();
        q1.pop(); q2.pop(); // delete the removal card 

        if((a == 0 && b == 9) || (a > b && (a != 9 || b != 0))){
            q1.push(a);
            q1.push(b);
        } 
        else {
            q2.push(a);
            q2.push(b);
        }
        
    }
    if(cnt >= 1000000) cout << "blin nichiya";
    else if(q1.empty()) cout << "Nursik" << ' ' << cnt;
    else cout << "Boris" << ' ' << cnt;
    return 0;
}
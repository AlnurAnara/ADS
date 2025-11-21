#include <iostream>
#include <map>
using namespace std;

//important！！！！！
/*Write a program that outputs the coordinates of elements from a array of size n×m

input format:
The ﬁrst line of input contains a single number t - the number of elements which you must ﬁnd.
The next line contains t integers - the values of the elements that you need print their coordinates.
The next line of input contains 2 space-separated integers, n and m, the number of rows and the columns.
The next n lines contain m integers. Snake array n × m

output format:
Print k lines the answer with coordinates for each case. If the given element is not in the snake array,
then print -1

i.e.
5
10 15 13 8 23
3 4
25 23 20 19
13 15 17 18
12 10 9 8

5
10 15 13 8 23
3 4
25 23 20 19
13 15 17 18
12 10 9 8
*/
int main() {
    
    //1. map<int, pair<int, int>> -> first index of number, pair - pos
    //2. Binary search
    
    int n, m, t, x;
    int test[10005];
    map<int, pair<int, int> > mp; //for position
    map<int, bool> ok; //用于快速检查一个数字是否存在于矩阵中。
    
    cin >> t;
    
    for(int i = 1; i <= t; i++) cin >> test[i];

    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> x;
            mp[x] = {i - 1, j - 1};
            ok[x] = true;
        }
    }
    
    for(int i = 1; i <= t; i++){
        if(ok[test[i]] == 1) cout << mp[test[i]].first << ' ' << mp[test[i]].second << endl;
        else cout << -1 << endl;
    }
    
    
    return 0;
}
#include <iostream>
#include <map>
using namespace std;

/*目标: 找出所有被修改过的昵称的最终名称，并输出原始昵称和它对应的最终昵称。

关键点: 昵称的更改是链式的 (Chain of Changes)。

如果 A 改为 B，然后 B 又改为了 C，那么最初的昵称 A 最终对应的昵称是 C。

2
Aslan Nurbot
Nurbot HackMachine
第一次修改: Aslan -> Nurbot
{"Aslan": "Nurbot"}
第二次修改: Nurbot ->HackMachine
{"Aslan": "HackMachine"}
*/
int main() {
    
    int n;
    string s, t;
    map<string, string> mp;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> s >> t;
        bool ok = 0;
        for(auto it : mp){
            if(it.second == s){
                mp[it.first] = t; 
                ok = 1;
            }
        }
        if(!ok) mp[s] = t;
    }
    cout << mp.size() << '\n';
    
    for(auto it : mp) cout << it.first << ' ' << it.second << '\n';
    
    return 0;
}

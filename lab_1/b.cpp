#include <iostream>
using namespace std;

/*You are given N people in the queue, i-th person has age ai. Queue starts at position 1.
Each person wants to know if there is a younger person before him in a queue, in particular, 
the age of the closestperson that is younger before him, otherwise print−1.

i.e.
4
25 25 20 30

i=1：前面没有人，输出 -1

i=2：检查 j=1，a[1]=25 不小于 a[2]=25，继续；没找到，输出 -1

i=3：检查 j=2，a[2]=25 > a[3]=20，继续；检查 j=1，a[1]=25 > a[3]=20，继续；没找到，输出 -1

i=4：检查 j=3，a[3]=20 < a[4]=30，找到！输出 20

answer:
-1 -1 -1 20
*/
int main(){
    
    int n, a[100005];
    
    cin >> n;
    
    bool ok = 0;
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
        
    for(int i = 1; i <= n; i++){
        ok = 0;
        for(int j = i - 1; j >= 1; j--){
            if(a[j] < a[i]){
                ok = 1;
                cout << a[j] << ' ';
                break;
            }
        }
        if(!ok) cout << -1 << ' ';
    }
    
    
    
    return 0;
}
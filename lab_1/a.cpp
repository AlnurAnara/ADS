#include <iostream>
#include <cstring>
using namespace std;

int main(){
    
    int n, x, a[1005];
    cin >> n;
    
    while(n--){
        int x;
        cin >> x;

        int a[1005];
        memset(a, -1, sizeof(a));

        int pos = 0;
        for (int cur = 1; cur <= x; cur++) {
            int cnt = cur + 1; 
            while (true) {
                if (a[pos] == -1){
                    cnt--;
                    if (cnt == 0){
                        a[pos] = cur;
                        break;
                    }
                }
                pos++;
                if (pos == x) pos = 0;
            }
        }
        for(int i = 0; i < x; i++) 
        cout << a[i] << ' ';

        cout << endl;
    }
    return 0;
}
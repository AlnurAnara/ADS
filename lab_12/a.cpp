#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*You have a complete directed weighted graph with n vertices.
The game removes vertices in an order, and you must add them back one by one (in reverse).

After adding vertex xᵢ, you must compute:
The longest shortest-path between any two currently active vertices.*/

long long n, g[505][505], a[505], used[505], cur, ans[505];

int main() {

    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> g[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++){
        int v = a[i];
        used[v] = 1;
        cur = 0;

        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                if(g[j][v] + g[v][k] < g[j][k])
                    g[j][k] = g[j][v] + g[v][k];


        for(int j = 1; j <= n; j++)
            if(used[j])
                for(int k = 1; k <= n; k++)
                    if(used[k] && cur < g[j][k]) cur = g[j][k];


        ans[i] = cur;
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << '\n';


    return 0;
}
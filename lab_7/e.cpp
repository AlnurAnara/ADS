#include <iostream>
#include <algorithm>
using namespace std;

/* sort rows, each row contain m integer elements. 
He decided to sort rows in decreasing order of their sum, 
i.e. the row with larger sum will be the first. 
In case the sums are equal, then he order rows lexicographically, 

i.e.
Input
5 3
1 2 3
1 2 4
1 3 2
6 0 0
2 3 2
Output
1 2 4 
2 3 2 
1 2 3 
1 3 2 
6 0 0 
*/
int n, m, x;

struct row{
    int sum;
    int elements[502];
};

bool cmp(row a, row b){
    if(a.sum != b.sum) return a.sum > b.sum; // descending order of sum
    
    for (int i = 1; i <= m; i++) {// lexicographical order
        if (a.elements[i] != b.elements[i])
            return a.elements[i] < b.elements[i];
    }
    return false;
}

int main() {
    
    row rows[502];

    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        rows[i].sum = 0;
        for(int j = 1; j <= m; j++){
            cin >> rows[i].elements[j];
            rows[i].sum += rows[i].elements[j];
        }
    }
    sort(rows + 1, rows + 1 + n, cmp);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << rows[i].elements[j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}

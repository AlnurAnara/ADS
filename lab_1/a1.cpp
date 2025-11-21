#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> solve(int n) {
    if (n == 0) return {};
    deque<int> deck;
    for (int t = n; t >= 1; t--) {
        deck.push_front(t);
        for (int i = 0; i < (t - 1) % deck.size(); i++) {
            int back_card = deck.back();
            deck.pop_back();
            deck.push_front(back_card);
        }
    }
    return vector<int>(deck.begin(), deck.end());
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> result = solve(n);
        for (int i = 0; i < result.size(); i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}
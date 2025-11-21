vector<int> get_h(string s) {
    int n = s.size();
    vector<int> h(n);

    h[0] = s[0];          // First character
    int p = 29;
    int p_pow = 29;       // p^1

    for (int i = 1; i < n; i++) {
        h[i] = h[i - 1] + s[i] * p_pow;
        p_pow *= p;
    }

    return h;
}

/*Example: s = "abcd"
h[0] = 'a' × p^0 = 97
h[1] = 'a' × p^0 + 'b' × p^1 = 97 + 98×29 = 2939
h[2] = 'a' × p^0 + 'b' × p^1 + 'c' × p^2 = 2939 + 99×841 = 86238
h[3] = 'a' × p^0 + 'b' × p^1 + 'c' × p^2 + 'd' × p^3 = ...
*/
### 字符串hash

```c++
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull base = 131;
void solve() {
    int n, q, l1, r1, l2, r2;
    string s;
    cin >> n >> q >> s;
    s = " " + s;
    vector<ull> p(n + 1), h(n + 1);
    p[0] = 1;
    for(int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] * base;
        h[i] = h[i - 1] * base + s[i];
    }
    function<ull(int, int)> query = [=](int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    };
    while(q-- && cin >> l1 >> r1 >> l2 >> r2) {
        if(query(l1, r1) == query(l2, r2)) {
            cout << "Yes\n";
        }else {
            cout << "No\n";
        }
    }
}
int main() {
    solve();
    return 0;
}
```


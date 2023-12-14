### kmp

```c++
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, m;
    string s, p; //主串 子串
    cin >> m >> p >> n >> s;
    s = " " + s, p = " " + p;
    vector<int> ne(m + 2, 0);
    //求nex 错位自己匹配自己 第一个位置不用匹配从2开始
    for(int i = 2, j = 0; i <= m; ++i) {
        while(j && p[i] != p[j + 1]) j = ne[j];
        if(p[i] == p[j + 1]) ++j;
        //cout << j << "\n";
        ne[i] = j;
    }
    //for(int i = 1; i <= m; ++i) cout << ne[i] << ' ';
    for(int i = 1, j = 0; i <= n; ++i) {
        while(j && s[i] != p[j + 1]) j = ne[j];
        if(s[i] == p[j + 1]) ++j;
        //cout << j << "\n";
        if(j == m) {
            cout << i - j << ' ';
            j = ne[j];
        }
    }
}
int main() {
    solve();
    return 0;
}
```


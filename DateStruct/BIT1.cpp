//单点修改+区间统计
#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
ll tree[N];
int n, m;
void update(int p, int x) {
    while (p <= n) {
        tree[p] += x;
        p += lowbit(p);
    }
}
ll query(int p) {
    ll res = 0;
    while (p > 0) {
        res += 1LL * tree[p];
        p -= lowbit(p);
    }
    return res;
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(i, x);
    }
    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, k;
            cin >> x >> k;
            update(x, k);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(r) - query(l - 1) << "\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

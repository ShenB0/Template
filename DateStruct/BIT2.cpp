//区间修改(差分)+单点查询
#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
const ll INF = 1LL << 60;
int n, m;
ll a[N], diff[N], tree[N];
void update(int i, ll k) {
    while (i <= n) {
        tree[i] += k;
        i += lowbit(i);
    }
}
ll query(ll i) {
    ll res = 0;
    while (i > 0) {
        res += tree[i];
        i -= lowbit(i);
    }
    return res;
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        diff[i] = a[i] - a[i - 1];
        update(i, diff[i]);
    }
    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            ll x, y, k;
            cin >> x >> y >> k;
            update(x, k);
            update(y + 1, -k);
        } else {
            ll x;
            cin >> x;
            cout << query(x) << "\n";
        }
    }
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

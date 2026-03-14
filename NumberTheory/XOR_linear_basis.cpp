//luogu3812
#include<bits/stdc++.h>
#define lowbit(x) ((x) & (-x))
using namespace std;
using ll = long long;
const int N = 55;
const ll INF = 1LL << 60;
ll a[N];
ll base[N];
ll mask[N];
void insert(ll x, ll b) {
    for (int i = 50; i >= 0; i--) {
            if ((x >> i) & 1) {
                if (!base[i]) {
                    base[i] = x;
                    mask[i] = b;
                    return ;
                } 
                x ^= base[i];
                b ^= mask[i];
            }
        }
}
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(base, 0,sizeof(base));
    memset(mask, 0,sizeof(mask));
    for (int i = 0; i < n; i++) {
        insert(a[i], 1LL << i);
    }
    ll ans = 0;
    for (int i = 50; i >= 0; i--) {
        if (base[i]) {
            ans = max(ans, ans ^ base[i]);
        }
    }
    cout << ans << "\n";
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
    

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 0x3f3f3f3f;
const int N =  5e5 + 10;
vector<int> adj[N];
int dep[N];
int fa[N][20];
void dfs(int u, int par) {
    dep[u] = dep[par] + 1;
    fa[u][0] = par;
    for (int i = 1; (1 << i) <= dep[u]; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (int v : adj[u]) {
        if (v == par) {
            continue;
        }
        dfs(v, u);
    }
}
int LCA(int x, int y){
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 19; i >= 0; i--) {
        if (dep[x] - (1 << i) >= dep[y]) {
            x = fa[x][i];
        } 
    } 
    if (x == y) return x;
    for (int i = 19; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}
void solve(){
    int n, m, root;
    cin >> n >> m >> root;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dep[root] = 0;
    dfs(root, root);
    while (m--) {
        int x, y;
        cin >> x >> y;
        cout << LCA(x, y) << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    while (t--) solve();
    return 0;
}

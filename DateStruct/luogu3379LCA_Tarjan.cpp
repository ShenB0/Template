//并查集
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 0x3f3f3f3f;
const int N =  5e5 + 10;
int fa[N];
int ans[N];
bool vis[N];
vector<int> adj[N];
vector<pair<int, int>> query[N];
int find(int x){
    if(fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}
void tarjan(int u){
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            tarjan(v);
            fa[v] = u;
        }
    }
    for (auto [v, id] : query[u]) {
        if (vis[v]) {
            ans[id] = find(v);
        }
    }
}
void solve(){
    int n, m, root;
    cin >> n >> m >> root;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        fa[i] = i;
    }
    fa[n] = n;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        query[x].push_back({y, i});
        query[y].push_back({x, i});
    }
    tarjan(root);
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << "\n";
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

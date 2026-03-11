#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int INF = 1 << 30;
const int N =  105;
const double eps = 1e-7;
double a[N][N];
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int id = i;
        for (int j = i + 1; j < n; j++) {
            if (fabs(a[j][i]) > fabs(a[id][i])) {
                id = j;
            }
        }
        for (int j = 0; j <= n; j++) {
            swap(a[id][j], a[i][j]);
        }
        if (fabs(a[i][i]) < eps) {
            cout << "No Solution" << "\n";
            return ;
        }
        double f = a[i][i];
        for (int j = n; j >= i; j--) {
            a[i][j] /= f;
        }
        for (int j = 0; j < n; j++) {
            if (j != i) {
                double tmp = a[j][i];
                for (int k = i; k <= n; k++) {
                    a[j][k] -= a[i][k] * tmp;
                }
            }
        }
    }
    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++) {
        cout << a[i][n] << "\n";
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
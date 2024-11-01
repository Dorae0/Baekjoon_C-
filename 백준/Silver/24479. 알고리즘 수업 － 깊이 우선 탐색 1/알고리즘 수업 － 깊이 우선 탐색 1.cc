#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vM[100005];
int ans[100005] = {0,};
int cnt = 1;
int n, m, r;

void recursion(int cur) {
    ans[cur] = cnt++;
    for (int i = 0; i < vM[cur].size(); i++) {
        int nxt = vM[cur][i];
        if (!ans[nxt]) {
            recursion(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        int tmp, tmp1;
        cin >> tmp >> tmp1;
        vM[tmp].push_back(tmp1);
        vM[tmp1].push_back(tmp);
    }
    for (int i = 1; i <= n; i++) {
        sort(vM[i].begin(), vM[i].end());
    }

    recursion(r);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
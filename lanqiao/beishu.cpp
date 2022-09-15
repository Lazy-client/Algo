//
// Created by 15776 on 2022/4/8.
//

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
// map<int,int> mp;//[x%k]->x
vector<int> a[maxn];

int mod(int x, int y) {
    return (x % y + y) % y;
}

signed main() {
    // 请在此输入您的代码
    // mp.clear();
    int n, k, x;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        a[x % k].push_back(x);
    }
    for (int i = 0; i < k; i++) {
        sort(a[i].begin(), a[i].end());
    }
    int res = -0x3f3f3f3f;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            int t = (k - (i + j) % k) % k;
            if (!a[i].empty() && !a[j].empty() && !a[t].empty()) {
                int A = *(a[i].end() - 1), B, C;
                if (i != j && j != t && i != t) {
                    B = *(a[j].end() - 1), C = *(a[t].end() - 1);
                } else if (i == j && i != t) {
                    if (a[j].size() < 2)continue;
                    B = *(a[j].end() - 2), C = *(a[t].end() - 1);
                } else if (j == t && i != t) {
                    if (a[j].size() < 2)continue;
                    B = *(a[j].end() - 1), C = *(a[j].end() - 2);
                } else if (i == t && i != j) {
                    if (a[i].size() < 2)continue;
                    B = *(a[j].end() - 1);
                    C = *(a[t].end() - 2);
                } else {
                    if (a[i].size() < 3)continue;
                    B = *(a[i].end() - 2), C = *(a[i].end() - 3);
                }
                res = max(res, A + B + C);
            }
        }
    }
    printf("%lld", res);
    return 0;
}
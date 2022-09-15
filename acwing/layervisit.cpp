//
// Created by 15776 on 2022/8/11.
//

#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;
const int N = 100005;
int d[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> g[n + 1];
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == b)
            continue;
        g[a].push_back(b);
    }
    queue<int> q;
    q.push(1);
    bool st[n + 1];
    memset(st, 0, sizeof(st));
    st[1] = true;
    memset(d, -1, sizeof(d));
    d[1] = 0;
    while (!q.empty()) {
        int fr = q.front();
        q.pop();
        for (int i:g[fr]) {
            if (!st[i]) {
                st[i] = true;
                d[i] = d[fr] + 1;
                q.push(i);
            }
        }
    }
    printf("%d", d[n]);
    return 0;
}
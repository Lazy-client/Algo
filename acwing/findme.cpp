//
// Created by 15776 on 2022/8/10.
//
#include <cstring>
#include "iostream"
#include "queue"

using namespace std;
int n, m;

auto x = EOF;

int main() {
    cin >> n >> m;
    bool visit[n + 1];
    vector<int> g[n + 1];
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int step = -1;
    int cnt = 0;
    int p = n + 1;

    queue<int> queue;
    queue.push(1);
    visit[1] = true;
    while (!queue.empty()) {
        int size = queue.size();
        step++;
        p = queue.front();
        for (int i = 0; i < size; ++i) {
            int a = queue.front();
            queue.pop();
            p = min(p, a);
            for (int b : g[a]) {
                if (!visit[b]) {
                    queue.push(b);
                    visit[b] = true;
                }
            }
        }
        if (queue.empty())
            cnt = size;
    }

    printf("%d %d %d", p, step, cnt);

    return 0;
}

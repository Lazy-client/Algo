//
// Created by 15776 on 2022/5/4.
//

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define MAXN 1000001
ll ans[MAXN << 2];
ll a[MAXN];
ll tag[MAXN << 2];
ll n, m;

inline ll ls(ll p) {//p的左儿子
    return (p << 1);
}

inline ll rs(ll p) {//p的右儿子
    return (p << 1 | 1);
}

inline void push_up(ll p) {//自底向上合并
    ans[p] = (ans[ls(p)] + ans[rs(p)]);
}

inline void f(ll p, ll l, ll r, ll k) {//消除一个懒标记
    tag[p] += k;
    ans[p] += k * (r - l + 1);
}

inline void push_down(ll p, ll l, ll r) {//自顶向下消除懒标记
    ll mid = (l + r) >> 1;
    f(ls(p), l, mid, tag[p]);
    f(rs(p), mid + 1, r, tag[p]);
    tag[p] = 0;
}

void build(ll p, ll l, ll r) {
    tag[p] = 0;
    if (l == r) {
        ans[p] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    push_up(p);
}

inline void update(ll nl, ll nr, ll l, ll r, ll p, ll k) {//维护区间【nl。。。nr】加k
    if (nl <= l && r <= nr) {
        tag[p] += k;
        ans[p] += k * (r - l + 1);
        return;
    }
    push_down(p, l, r);
    ll mid = (l + r) >> 1;
    if (mid >= nl)
        update(nl, nr, l, mid, ls(p), k);
    if (mid < nr)
        update(nl, nr, mid + 1, r, rs(p), k);
    push_up(p);
}

ll query(ll q_l, ll q_r, ll l, ll r, ll p) {//求q_l...q_r的区间和
    ll res = 0;
    if (q_l <= l && r <= q_r) {
        return ans[p];
    }
    push_down(p, l, r);
    ll mid = (l + r) >> 1;
    if (mid >= q_l)
        res += query(q_l, q_r, l, mid, ls(p));
    if (mid < q_r)
        res += query(q_l, q_r, mid + 1, r, rs(p));
    return res;
}

int main() {
    int op;
    ll l, r, nl, nr, q_l, q_r, k;
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    build(1, 1, n);
    for (int i = 0; i < m; i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%lld %lld %lld", &l, &r, &k);
            update(l, r, 1, n, 1, k);
        } else if (op == 2) {
            scanf("%lld %lld", &l, &r);
            printf("%lld\n", query(l, r, 1, n, 1));
        }
    }
    return 0;
}


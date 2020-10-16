#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct node
{
    int dis;
    vector<int> a;
    node()
    {
        for (int i = 0; i <= 44; i++)
            a.push_back(0);
        dis = 0;
    }
};

node t[400005];

node merge(node &x, node &y)
{
    node temp;
    for (int i = 0; i <= 41; i++)
    {
        temp.a[i] = x.a[i] + y.a[i];
        if (temp.a[i])
            temp.dis++;
    }
    return temp;
}
void build(ll a[], ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        t[v].dis = 1;
        t[v].a[a[tl]]++;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
}

void update(ll v, ll tl, ll tr, ll val, ll pos)
{
    if (tl == tr)
    {
        for (int i = 0; i <= 41; i++)
            t[v].a[i] = 0;

        t[v].a[val]++;
        t[v].dis = 1;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(1, tl, tm, pos, val);
        else
            update(1, tm + 1, tr, pos, val);

        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }
}

node get(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r || tl > tr)
    {
        node temp;
        temp.dis = 0;
        return temp;
    }
    if (tl == l && tr == r)
    {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    node temp1 = get(2 * v, tl, tm, l, min(r, tm));
    node temp2 = get(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
    return (merge(temp1, temp2));
}

int main()
{
    ll i, n, m;
    cin >> n >> m;
    ll a[n + 4];
    for (i = 0; i < n; i++)
        cin >> a[i];
    build(a, 1, 0, n - 1);

    while (m--)
    {
        ll x;
        cin >> x;
        if (x == 1)
        {
            ll y, z;
            cin >> y >> z;
            y--;
            z--;
            cout << get(1, 0, n - 1, y, z).dis << "\n"; 
        }
        else
        {
            ll y, z;
            cin >> y >> z;
            y--;
            update(1, 0, n - 1, y, z);
        }
    }

    return (0);
}
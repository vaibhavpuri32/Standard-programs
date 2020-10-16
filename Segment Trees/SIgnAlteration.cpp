#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll t1[4000005];
ll t2[4000005];
void build1(vector<ll> &a, ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        t1[v] = a[tl];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build1(a, 2 * v, tl, tm);
        build1(a, 2 * v + 1, tm + 1, tr);
        t1[v] = t1[2 * v] + t1[2 * v + 1];
    }
}
void build2(vector<ll> &a, ll v, ll tl, ll tr)
{
    if (tl == tr)
    {
        t2[v] = a[tl];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        build2(a, 2 * v, tl, tm);
        build2(a, 2 * v + 1, tm + 1, tr);
        t2[v] = t2[2 * v] + t2[2 * v + 1];
    }
}

void update1(ll v, ll tl, ll tr, ll pos, ll val)
{
    if (tl == tr)
    {
        t1[v] = val;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update1(2 * v, tl, tm, pos, val);
        else
            update1(2 * v + 1, tm + 1, tr, pos, val);
        t1[v] = t1[2 * v] + t1[2 * v + 1];
    }
}
void update2(ll v, ll tl, ll tr, ll pos, ll val)
{
    if (tl == tr)
    {
        t2[v] = val;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update2(2 * v, tl, tm, pos, val);
        else
            update2(2 * v + 1, tm + 1, tr, pos, val);
        t2[v] = t2[2 * v] + t2[2 * v + 1];
    }
}

ll sum1(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
    {
        return 0;
    }
    if (tl == l && tr == r)
        return t1[v];
    ll tm = (tl + tr) / 2;
    return (sum1(2 * v, tl, tm, l, min(tm, r)) + sum1(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

ll sum2(ll v, ll tl, ll tr, ll l, ll r)
{
    if (l > r)
    {
        return 0;
    }
    if (tl == l && tr == r)
        return t2[v];
    ll tm = (tl + tr) / 2;
    return (sum2(2 * v, tl, tm, l, min(tm, r)) + sum2(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}
int main()
{
    ll i, j, n;
    cin >> n;
    vector<ll> a, b;
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (i % 2 == 0)
        {
            a.push_back(x);
            b.push_back(0);
        }
        else
        {
            b.push_back(x);
            a.push_back(0);
        }
    }
    build1(a, 1, 0, n - 1);
    build2(b, 1, 0, n - 1);

    ll m;
    cin >> m;
    while (m--)
    {
        ll x;
        cin >> x;
        if (x == 0)
        {
            ll y, z;
            cin >> y >> z;
            y--;
            if (y % 2 == 0)
                update1(1, 0, n - 1, y, z);
            else
                update2(1, 0, n - 1, y, z);
        }
        else
        {
            ll y, z;
            cin >> y >> z;
            y--;
            z--;
            ll ans1 = sum1(1, 0, n - 1, y, z);
            ll ans2 = sum2(1, 0, n - 1, y, z);
            if (y % 2 == 0)
                cout << ans1 - ans2 << " \n";
            else
                cout << ans2 - ans1 << "\n";
        }
    }

    return (0);
}
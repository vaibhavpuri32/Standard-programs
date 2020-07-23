#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18
ll t[400005];
void build(ll a[], ll v, ll tl, ll tr)
{
    if (tl == tr)
        t[v] = a[tl];
    else
    {
        ll tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        t[v] = 0;
    }
}


void update(ll v, ll tl, ll tr, ll l, ll r, ll val)
{
    if (l > r)
        return;
    if (l == tl && r == tr)
    {
        t[v] = t[v] + val;
    }
    else
    {
        ll tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(r, tm), val);
        update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
    }
}

ll get(ll v, ll tl, ll tr, ll pos)
{
    if (tl == tr)
    {
        return t[v];
    }
    else
    {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
        {
            return t[v] + get(2 * v, tl, tm, pos);
        }
        else
        {
            return t[v] + get(2 * v + 1, tm + 1, tr, pos);
        }
    }
}

int main()
{
    ll i, n;
    cin >> n;
    ll a[n + 2];
    for (i = 0; i < n; i++)
        cin >> a[i];
    ll q;
    cin>>q;
    build(a, 1, 0, n - 1);

   

    while (q--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        update(1, 0, n - 1, x, y, z);
        
    }

    for (i = 0; i < n; i++)
        cout << get(1, 0, n - 1, i) << " ";

    return (0);
}
 
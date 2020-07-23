#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18
int main()
{
    ll i;
    string s;
    cin >> s;
    s = s + '$';
    ll n = s.length();
    vector<ll> p(n), c(n);
    vector<pair<char, ll>> a(n);
    for (i = 0; i < n; i++)
        a[i] = {s[i], i};
    sort(a.begin(), a.end());

    for (i = 0; i < n; i++)
        p[i] = a[i].second;
    c[p[0]] = 0;
    for (i = 1; i < n; i++)
    {
        if (a[i].first == a[i - 1].first)
            c[p[i]] = c[p[i - 1]];
        else
            c[p[i]] = c[p[i - 1]] + 1;
    }

    ll k = 0;
    while ((1 << k) < n)
    {
        vector<pair<pair<ll, ll>, ll>> a(n);
        for (i = 0; i < n; i++)
        {
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }
        sort(a.begin(), a.end());
        for (i = 0; i < n; i++)
            p[i] = a[i].second;
        c[p[0]] = 0;
        for (i = 1; i < n; i++)
        {
            if (a[i].first == a[i - 1].first)

                c[p[i]] = c[p[i - 1]];
            else
                c[p[i]] = c[p[i - 1]] + 1;
        }

        k++;
    }

    for (i = 0; i < n; i++)
        cout << p[i] << " ";
    return (0);
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18

ll RANK(string s, ll fact[])
{
    ll i, ans = 0;
    ll count[130] = {0};
    ll n = s.length();
    for (i = 0; i < n; i++)
    {
        count[s[i]]++;
    }

    for (i = 1; i < 129; i++)
        count[i] = count[i - 1] + count[i];

    for (i = 0; i < n; i++)
    {

        ans = ans + (count[s[i] - 1] * fact[n - i - 1]);
        for (ll j = s[i]; j < 129; j++)
            count[j]--;
    }

    return ans + 1;
}
int main()
{
    string s;
    cin >> s;
    ll i, n = s.length();

    ll fact[n + 10];

    fact[0] = 1;
    for (i = 1; i <= n + 2; i++)
    {
        fact[i] = fact[i - 1] * i;
    }

    cout << RANK(s, fact) << "\n";

    return (0);
}

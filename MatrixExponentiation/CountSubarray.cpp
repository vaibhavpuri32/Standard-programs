#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18
#define P 1000000007
void MatrixExpo(ll a[][2], ll b[][2])
{
    ll product[2][2] = {{0, 0}, {0, 0}};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                product[i][k] = (product[i][k] + ((a[i][j] % P) * (b[j][k] % P)) % P) % P;
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            a[i][j] = (product[i][j]+P)%P;
        }
    }
}

ll calc(ll a[][2], ll n, ll m)
{
    ll result[2][2] = {{1, 0}, {0, 1}};
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            MatrixExpo(result, a);
        }
        n = n / 2;
        MatrixExpo(a, a);
    }
     /*
     for (ll i = 0; i < 2; i++)
    {
        for (ll j = 0; j < 2; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }*/

    return (((result[0][0] + result[1][0]) % P) * (m % P)) % P;
}
 int main()
{
    ll t, i;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll a[2][2] = {{m - 1, m - 1}, {1, 0}};
        if (n == 1)
            cout << m%P << "\n";
        else
        {
            n--;
            cout << calc(a, n, m) << "\n";
        }
    }
    return (0);
}



 




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
                product[i][k] += (a[i][j] * b[j][k]) % P;
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            a[i][j] = (product[i][j] + P) % P;
        }
    }
}

ll calc(ll n)
{
    if (n == 1)
    {
        return 1;
    }
    ll a[2][2] = {{1, 1}, {1, 0}};
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
    return result[0][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i, n;
    cin >> n;
    if (n == 0 || n == 1)
    {
        cout << n << "\n";
        exit(0);
    }
    n--;

    cout << calc(n) << "\n";

    return (0);
}
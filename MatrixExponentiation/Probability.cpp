#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1e18
#define P 1000000007
long happy[2] = {1, 0};

void MatrixExpo(double a[][2], double b[][2])
{
    double product[2][2] = {{0, 0}, {0, 0}};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                product[i][k] += a[i][j] * b[j][k];
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            a[i][j] = product[i][j];
        }
    }
}
long double calc(ll n, double p, double a[][2])
{
    double result[2][2] = {{1, 0}, {0, 1}};

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
    long double p;
    ll i, j, n;
    cin >> n >> p;
    double a[2][2] = {{(1.0 - p), p}, {p, (1.0 - p)}};
    std::cout << fixed << setprecision(11) << calc(n, p, a) << "\n";
    return (0);
}
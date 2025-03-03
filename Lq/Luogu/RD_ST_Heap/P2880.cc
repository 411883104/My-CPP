/*
 * @Author       : Outsider
 * @Date         : 2023-03-01 19:14:52
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-04 10:13:33
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\RD_ST_Heap\P2880.cc
 */
#include <iostream>
using namespace std;

int a[1005][20];
int b[1005][20];
int log[1005];
int pow[20];
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}
int main()
{
    int n, t;
    cin >> n >> t;
    log[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            b[i][j] = 0xffffff;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        b[i][0] = a[i][0] = read();
        log[i] = log[i >> 1] + 1;
    }
    pow[0] = 1;
    for (int i = 1; i < log[n] + 1; i++)
    {
        pow[i] = pow[i - 1] << 1;
    }
    for (int j = 1; j <= log[n]; j++)
    {
        for (int i = 1; i + pow[j] - 1 <= n; i++)
        {
            a[i][j] = max(a[i][j - 1], a[i + pow[j - 1]][j - 1]);
            b[i][j] = min(b[i][j - 1], b[i + pow[j - 1]][j - 1]);
        }
    }

    int ll, rr;
    while (t--)
    {
        ll = read();
        rr = read();
        int len = log[rr - ll + 1];
        printf("%d\n", max(a[ll][len], a[rr - pow[len] + 1][len]) -
                           min(b[ll][len], b[rr - pow[len] + 1][len]));
    }
}
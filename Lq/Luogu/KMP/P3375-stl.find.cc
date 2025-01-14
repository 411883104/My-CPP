/*
 * @Author       : Outsider
 * @Date         : 2023-02-27 17:06:17
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-24 16:23:29
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\KMP\P3375-stl.find.cc
 */
#include <iostream>
using namespace std;
int nextval[1005];
int main()
{
    string a, b;
    cin >> a >> b;
    size_t i = 1, j = 1, k = 0;
    while (j <= b.size())
    {
        if (k == 0 || b[j - 1] == b[k - 1])
        {
            nextval[++j] = ++k;
        }
        else
        {
            k = nextval[k];
        }
    }
    i = 0;
    while ((i = a.find(b, i)) != string::npos)
    {
        cout << i + 1 << endl;
        i += 1;
    }

    for (size_t i = 2; i <= b.size() + 1; i++)
    {
        cout << nextval[i] - 1 << " ";
    }
    cout << endl;
}
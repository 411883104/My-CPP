/*
 * @Author       : Outsider
 * @Date         : 2023-03-05 09:04:58
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-05 09:48:19
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Graph\P3916.cc
 */
#include <iostream>
#include <cstring>
using namespace std;

struct Edge
{
    int idx;
    Edge* next;
    Edge(int idx) : idx(idx), next(nullptr) {}
};

struct Node
{
    Edge* edge;
    Node() : edge(nullptr) {}
};

Node G[1005];
bool check[1005];
int vis[10005];
int maxx = 0;
void dfs(int n)
{
    auto e = G[n].edge;
    maxx = max(n, maxx);
    while (e)
    {
        if (!check[e->idx])
        {
            check[e->idx] = true;
            if (vis[e->idx] != 0)
            {
                maxx = max(maxx, vis[e->idx]);
            }
            else
            {
                dfs(e->idx);
            }
        }
        e = e->next;
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    int x, y;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        Edge* e = new Edge(y);
        e->next = G[x].edge;
        G[x].edge = e;
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] != 0)
        {
            maxx = vis[i];
        }
        else
        {
            maxx = 0;
            memset(check, 0, sizeof(bool) * (n + 1));
            check[i] = true;
            dfs(i);
            vis[i] = maxx;
        }
        printf("%d ", maxx);
    }
    printf("\n");
    return 0;
}
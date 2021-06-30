/*
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!
  
  https://github.com/UAPSPC/Code-Archive/blob/master/graph/floyd.c

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
#define MAXN 510
#define CType long long
CType g[MAXN][MAXN], dist[MAXN][MAXN];
void floyd(int n)
{
  int i, j, k;
  memcpy(dist, g, sizeof(g));
  for(k = 0; k < n; k++) for(i = 0; i < n; i++) for(j = 0; j < n; j++){
    if(dist[i][k] != -1 && dist[k][j] != -1){
      CType temp = dist[i][k] + dist[k][j];
      if(dist[i][j] == -1 || dist[i][j] > temp)
	dist[i][j] = temp;
    }
  }
  for(i = 0; i < n; i++) dist[i][i] = 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, t, d;
    cin>>n>>m>>t>>d;
    memset(g, -1, sizeof(g));
    vector<int> an;
    for(int i=0;i<t;i++)
    {
        int a;
        cin>>a;
        an.push_back(a-1);
    }
    for(int i=0;i<m;i++)
    {
        int from, to, distance;
        cin>>from>>to>>distance;
        from--;
        to--;
        g[to][from]=g[from][to]=distance;
    }
    floyd(n);
    if(dist[0][n-1]==-1)
    {
        cout<<"stuck";
        return 0;
    }
    memset(g, -1, sizeof(g));
    an.push_back(0);
    an.push_back(n-1);
    for(auto i:an)
    {
        for(auto j:an)
        {
            if(dist[i][j]<=d)
            {
                g[i][j]=g[j][i]=dist[i][j];
            }
        }
    }
    memset(dist, -1, sizeof(dist));
    floyd(n);
    if(dist[0][n-1]==-1)
    {
        cout<<"stuck";
    }
    else
    {
        cout<<dist[0][n-1];
    }
    return 0;
}
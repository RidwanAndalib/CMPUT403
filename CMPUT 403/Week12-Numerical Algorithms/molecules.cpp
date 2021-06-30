/*
  Problem: https://open.kattis.com/problems/molecules
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!
  
  Lecture Video
  https://eclass.srv.ualberta.ca/pluginfile.php/6659206/mod_resource/content/1/equationsolverplus.cpp

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
const long double EPS = 1e-8;
using vd = vector<long double>;
using vvd = vector<vd>;

void rref(vvd& m) {
  int nr = m.size(), nc = m[0].size();
  for (int r = 0, c = 0; c < nc; ++c) {
    int p = -1;
    for (int i = r; i < nr; ++i)
      if (fabs(m[i][c]) > EPS && (p == -1 || fabs(m[i][c]) < fabs(m[p][c])))
        p = i;
    if (p == -1) continue;
    swap(m[p], m[r]);
    for (int tc = nc-1; tc >= c; --tc) m[r][tc] /= m[r][c];
    for (int tr = 0; tr < nr; ++tr) {
      if (tr == r || fabs(m[tr][c]) < EPS) continue;
      for (int tc = nc-1; tc >= c; --tc)
        m[tr][tc] -= m[r][tc]*m[tr][c];
    }
    ++r;
  }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<int> edges[n];
    vector<int> unknown;
    vvd matrixX(n, vd(n+1));
    vvd matrixY(n, vd(n+1));
    for(int i=0;i<n;i++)
    {
        int x, y;
        cin>>x>>y;
        if(x!=-1 or y!=-1)
        {
            matrixX[i][i]=1;
            matrixY[i][i]=1;
            matrixX[i][n]=x;
            matrixY[i][n]=y;
        }
        else
        {
            unknown.push_back(i);
        }
    }
    for(int i=0;i<m;i++)
    {
        int x, y;
        cin>>x>>y;
        edges[--x].push_back(--y);
        edges[y].push_back(x);
    }
    for(auto& i: unknown)
    {
        matrixX[i][i]=edges[i].size();
        matrixY[i][i]=matrixX[i][i];
        for(auto& j: edges[i])
        {
            matrixX[i][j]=-1;
            matrixY[i][j]=-1;
        }
    }
    rref(matrixX);
    rref(matrixY);
    for(int i=0;i<n;i++)
    {
        cout<<matrixX[i][n]<<' '<<matrixY[i][n]<<'\n';
    }
    return 0;
}

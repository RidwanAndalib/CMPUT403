/*
  Problem: https://open.kattis.com/problems/cheeseifyouplease
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!
  
  Lecture Video
  https://eclass.srv.ualberta.ca/pluginfile.php/6659208/mod_resource/content/2/p10498.cpp
  https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1439

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define MAXN 100 // max # of variables
#define MAXC 100 // max # of constraints
#define EPS  1e-8
using namespace std;

double A[MAXC+1][MAXN+1], b[MAXC], c[MAXN], x[MAXN], val;
int xB[MAXC], xN[MAXN];
void pivot(int n, int m, int r, int c) {
  for (int j = 0; j <= n; ++j)
    if (j != c)
      A[r][j] /= A[r][c];

  for (int i = 0; i <= m; ++i)
    if (i != r && fabs(A[i][c]) > EPS)
      for (int j = 0; j <= n; ++j)
        if (j != c)
          A[i][j] -= A[r][j]*A[i][c];

  for (int i = 0; i <= m; ++i)
    if (i != r)
      A[i][c] = -A[i][c]/A[r][c];

  A[r][c] = 1/A[r][c];

  swap(xB[r], xN[c]);
}

void bland(int a, int& b, int* v) {
  if (b < 0 || v[a] < v[b]) b = a;
}

bool phase1(int n, int m) {
  while (true) {
    int r = -1, c = -1;

    for (int i = 0; i < m; ++i)
      if (A[i][n] < -EPS)
        bland(i, r, xB);

    if (r == -1) return true;

    for (int j = 0; j < n; ++j)
      if (A[r][j] < -EPS)
        bland(j, c, xN);

    if (c == -1) return false;

    pivot(n, m, r, c);
  }
}

bool phase2(int n, int m) {
  while (true) {
    int r = -1, c = -1;
    for (int j = 0; j < n; ++j)
      if (A[m][j] > EPS)
        bland(j, c, xN);

    if (c == -1) return true;

    for (int i = 0; i < m; ++i)
      if (A[i][c] > EPS) {
        if (r == -1) r = i;
        else {
          double lhs = A[i][c]*A[r][n], rhs = A[r][c]*A[i][n];
          if (lhs > rhs + EPS) r = i;
          else if (fabs(lhs-rhs) < EPS) bland(i, r, xB);
        }
      }

    if (r == -1) return false;

    pivot(n, m, r, c);
  }
}

int simplex(int n, int m) {
  for (int j = 0; j < n; ++j) {
    A[m][j] = c[j];
    xN[j] = j;
  }

  for (int i = 0; i < m; ++i) {
    A[i][n] = b[i];
    xB[i] = i+n;
  }

  A[m][n] = 0;

  if (!phase1(n, m)) return 0;

  if (!phase2(n, m)) return -1;

  val = -A[m][n];
  for (int i = 0; i < n; ++i) x[i] = 0;
  for (int i = 0; i < m; ++i)
    if (xB[i] < n)
      x[xB[i]] = A[i][n];

  return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>A[j][i];
        }
        cin>>c[i];
    }
    assert(simplex(n, m) == 1);
    cout<<fixed;
    cout<<setprecision(2);
    cout<<val*100;
    return 0;    
}

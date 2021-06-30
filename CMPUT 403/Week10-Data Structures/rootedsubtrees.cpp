/*
  Problem: https://open.kattis.com/problems/rootedsubtrees
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!
  
  Lecture Video
  Textbook
  https://eclass.srv.ualberta.ca/pluginfile.php/7035320/mod_resource/content/3/tourists.cpp

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define MAXN 200010
#define LOGN 18
using namespace std;
typedef long long ll;
vector<int> g[MAXN];
int up[LOGN][MAXN], depth[MAXN];
void dfs(int v, int pre, int d) {
    depth[v] = d;

    for (auto w : g[v])
        if (w != pre)
            dfs(w, v, d+1);

    up[0][v] = pre;
}
int lca(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);
    for (int j = LOGN-1; j >= 0; --j)
        if (depth[a] + (1<<j) <= depth[b])
            b = up[j][b];
    if (a == b) return a;
    for (int j = LOGN-1; j >= 0; --j)
        if (up[j][a] != up[j][b]) {
            a = up[j][a];
            b = up[j][b];
        }
    return up[0][a];
}

ll dist(ll a, ll b) {
    return depth[a] + depth[b] - 2*depth[lca(a, b)] + 1;
}
ll formula(ll d, ll n)
{
    ll value=n;
    for(int i=1;i<d;i++)
    {
        value+=i;
    }
    return value;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q, r, p;
    cin>>n>>q;
    for(ll i=0;i<n-1;i++)
    {
        ll u, v;
        cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    for (auto x : up) fill(x, x+n, -1);
    dfs(0, -1, 0);
    for (ll j = 1; j < LOGN; ++j)
        for (ll v = 0; v < n; ++v)
            if (up[j-1][v] != -1)
                up[j][v] = up[j-1][up[j-1][v]];
    for(ll i=0;i<q;i++)
    {
        cin>>r>>p;
        cout<<formula(dist(r-1,p-1),n)<<endl;
    }
    return 0;
}

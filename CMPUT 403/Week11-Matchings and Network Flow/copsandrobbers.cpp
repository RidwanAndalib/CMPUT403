/*
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!
  
  Lecture Video
  https://eclass.srv.ualberta.ca/pluginfile.php/6659203/mod_resource/content/3/openpitmining.cpp

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
#include <queue>
using namespace std;

using ll = long long;
const ll INF = (1ll<<50);

struct Edge {
  int u, v;
  ll cap;
};

vector<Edge> edges;
vector<vector<int>> g;

vector<int> par;

ll augment(int s, int t) {
  for (int& x : par) x = -1;
  queue<int> q;
  q.push(s);

  while (q.size() > 0 && par[t] == -1) {
    int u = q.front();
    q.pop();

    for (int i : g[u]) {
      int v = edges[i].v;
      if (par[v] != -1 || edges[i].cap == 0) continue;
      par[v] = i;
      q.push(v);
    }
  }

  if (par[t] == -1) return 0;

  ll aug = INF;
  int tmp = t;
  while (tmp != s) {
    int i = par[tmp];
    aug = min(aug, edges[i].cap);
    tmp = edges[i].u;
  }

  tmp = t;
  while (tmp != s) {
    int i = par[tmp];
    edges[i].cap -= aug;
    edges[i^1].cap += aug;
    tmp = edges[i].u;
  }

  return aug;
}

ll maxflow(int s, int t) {
  par.resize(g.size());

  ll flow = 0;

  while (true) {
    ll aug = augment(s, t);
    if (!aug) return flow;
    flow += aug;
  }
}

void push(int u, int v, ll c) {
  g[u].push_back(edges.size());
  edges.push_back({u, v, c});
}

void add_edge(int u, int v, ll c) {
  push(u, v, c);
  push(v, u, 0);
}

void init_graph(int n) {
  edges.clear();
  g.assign(n, vector<int>(0));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int nc, nr, c, nodes;
    cin>>nc>>nr>>c;
    nodes=nc*nr;
    char nodemap[nodes];
    int nodecost[c];
    init_graph(nodes*2+2);
    int s=nodes*2, t=nodes*2+1;
    for (int i=0;i<nodes;i++)
    {
        cin>>nodemap[i];
    }
    for(int i=0;i<c;i++)
    {
        cin>>nodecost[i];
    }
    for (int i=0;i<nodes;i++)
    {
        int iout=i+nodes;
        if(nodemap[i]=='B')
        {
            add_edge(s,i,INF);
            add_edge(i,iout,INF);
        }
        if(nodemap[i]=='.')
        {
            add_edge(i,iout,INF);
        }
        else 
        {
            add_edge(i,iout,nodecost[nodemap[i]-'a']);
        }
        int r, c, nexti;
        r=i/nc;
        c=i%nc;
        if(r+1<nr)
        {
            nexti=(r+1)*nc+c;
            add_edge(iout,nexti,INF);
        }
        else
        {
            add_edge(iout,t,INF);
        }
        if(r-1>=0)
        {
            nexti=(r-1)*nc+c;
            add_edge(iout,nexti,INF);
        }
        else
        {
            add_edge(iout,t,INF);
        }
        if(c+1<nc)
        {
            nexti=r*nc+c+1;
            add_edge(iout,nexti,INF);
        }
        else
        {
            add_edge(iout,t,INF);
        }
        if(c-1>=0)
        {
            nexti=r*nc+c-1;
            add_edge(iout,nexti,INF);
        }
        else
        {
            add_edge(iout,t,INF);
        }
    }
    ll ans=maxflow(s,t);
    if(ans>=INF)
    {
        ans=-1;
    }
    cout<<ans;
    return 0;    
}
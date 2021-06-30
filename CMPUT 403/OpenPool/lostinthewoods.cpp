/*
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!
  
  N/A

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
#include <limits>
#include <iomanip>
using namespace std;
long double total=0;
long double eps=numeric_limits<long double>::epsilon();
int e;
vector<vector<int>> edges;
vector<long double> p;
queue<int> qi;
queue<long double> qp;
int d=0;
void traverse()
{
    d++;
    for(int i=0;i<e;i++)
    {
        if(p[i]>eps)
        {
            qi.push(i);
            qp.push(p[i]);
        }
        p[i]=0;
    }
    if(qi.empty())
    {
        return;
    }
    while(!qi.empty())
    {
        
        int curri=qi.front();
        long double currp=qp.front();
        int len=edges[curri].size();
        qi.pop();
        qp.pop();
        for(auto next:edges[curri])
        {
            if(next==e)
            {
                total+=currp/len*d;
            }
            else
            {
                p[next]+=currp/len;
            }
        }
    }
    traverse();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    edges.resize(n);
    p.resize(n);
    p[0]=1;
    for(int i=0;i<m;i++)
    {
        int k, l;
        cin>>k>>l;
        edges[l].push_back(k);
        edges[k].push_back(l);
    }
    e=n-1;
    traverse();
    cout<<fixed;
    cout<<setprecision(5);
    cout<<total;
    return 0;
}
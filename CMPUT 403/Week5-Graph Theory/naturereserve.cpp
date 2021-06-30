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
#include <utility>
using namespace std;
void processdataset()
{
    int n, m, l, s, from, to, value;
    long long int total=0;
    cin>>n>>m>>l>>s;
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    vector<bool> installed(n, false);
    vector<pair<int,int>> edges[n];
    for(int i=0;i<s;i++)
    {
        cin>>from;
        installed[from-1]=true;
    }
    for(int i=0;i<m;i++)
    {
        cin>>from>>to>>value;
        edges[from-1].push_back(make_pair(to-1,value+l));
        edges[to-1].push_back(make_pair(from-1,value+l));
    }
    for(int i=0;i<n;i++)
    {
        if(installed[i])
        {
            for(int j=0;j<edges[i].size();j++)
            {
                q.push(make_pair(edges[i][j].second,edges[i][j].first));
            }
        }
    }
    while(!q.empty())
    {
        value=q.top().first;
        to=q.top().second;
        q.pop();
        if(!installed[to])
        {
            total+=value;
            installed[to]=true;
            for(int j=0;j<edges[to].size();j++)
            {
                q.push(make_pair(edges[to][j].second,edges[to][j].first));
            }
        }
    }
    cout<<total<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int dataset;
    cin>>dataset;
    while(dataset--)
    {
        processdataset();
    }
    return 0;
}
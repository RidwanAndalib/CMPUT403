/*
  Problem: https://open.kattis.com/problems/getshorty
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
#include <iomanip>
using namespace std;
void findPath(int n, int m)
{
    vector<pair<int,long double>> edge[n];
    long double highest[n]={};
    priority_queue<pair<long double,int>> q;
    int from, to, current;
    long double value;
    for(int i=0;i<m;i++)
    {
        cin>>from>>to>>value;
        edge[from].push_back(make_pair(to,value));
        edge[to].push_back(make_pair(from,value));
    }
    highest[0]=1;
    q.push(make_pair(1,0));
    while(!q.empty())
    {
        current=q.top().second;
        value=highest[current];
        q.pop();
        for(int i=0;i<edge[current].size();i++)
        {
            if(highest[edge[current][i].first]<value*edge[current][i].second)
            {
                highest[edge[current][i].first]=value*edge[current][i].second;
                q.push(make_pair(highest[edge[current][i].first],edge[current][i].first));
            }
        }
    }
    cout<<fixed;
    cout<<setprecision(4);
    cout<<highest[n-1]<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    while(1)
    {
        cin>>n>>m;
        if(n==0 and m==0)
            break;
        findPath(n,m);
    }
    return 0;
}

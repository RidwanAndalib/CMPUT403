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
#include <stack>
using namespace std;
void visit(int current, vector<int> edge[], vector<bool> &visited, stack<int> &order)
{
    visited[current]=true;
    for(int i=0;i<edge[current].size();i++)
    {
        if(!visited[edge[current][i]])
        {
            visit(edge[current][i],edge,visited,order);
        }
    }
    order.push(current);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, from, to;
    cin>>n>>m;
    vector<int> edge[n];
    vector<bool> visited(n, false);
    stack<int> order;
    int sorted[n], index[n];
    for(int i=0;i<m;i++)
    {
        cin>>from>>to;
        edge[from-1].push_back(to-1);
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            visit(i,edge,visited,order);
        }
    }
    for(int i=0;!order.empty();i++)
    {
        sorted[i]=order.top();
        index[order.top()]=i;
        order.pop();
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<edge[sorted[i]].size();j++)
        {
            if(index[sorted[i]]>=index[edge[sorted[i]][j]])
            {
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<sorted[i]+1<<'\n';
    }
    return 0;
}
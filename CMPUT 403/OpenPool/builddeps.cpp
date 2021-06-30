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
#include <sstream>
#include <unordered_map>
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
    int n, nextindex=0, from, to;
    string line, s;
    unordered_map<string,int> stim;
    unordered_map<int,string> itsm;
    cin>>n;
    vector<int> edge[n];
    vector<bool> visited(n, false);
    stack<int> order;
    getline(cin,line);
    for(int i=0;i<n;i++)
    {
        getline(cin,line);
        istringstream iss(line);
        iss>>s;
        s.erase(s.size()-1,1);
        if(stim.count(s)==0)
        {
            stim[s]=nextindex;
            itsm[nextindex]=s;
            nextindex++;
        }
        from=stim[s];
        while(iss>>s)
        {
            if(stim.count(s)==0)
            {
                stim[s]=nextindex;
                itsm[nextindex]=s;
                nextindex++;
            }
            to=stim[s];
            edge[to].push_back(from);
        }
    }
    cin>>s;
    from=stim[s];
    visit(from,edge,visited,order);
    while(!order.empty())
    {
        cout<<itsm[order.top()]<<'\n';
        order.pop();
    }
    return 0;
}
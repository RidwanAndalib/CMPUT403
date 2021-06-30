/*
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  http://www.cplusplus.com/reference/queue/priority_queue/
  https://www.cplusplus.com/reference/vector/vector/
  http://www.cplusplus.com/reference/utility/pair/

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
#include <functional>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, s;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> r;
    priority_queue<int,vector<int>,greater<int>> w;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a>>s;
        r.push(make_pair(a,a+s));
    }
    while (!r.empty())
    {
        if(w.empty())
        {
            w.push(r.top().second);
            r.pop();
            n--;
        }
        else if(w.top()>r.top().first)
        {
            w.push(r.top().second);
            r.pop();
            n--;
        }
        else if(w.top()<=r.top().first and r.top().first<=w.top()+m)
        {
            w.pop();
            w.push(r.top().second);
            r.pop();
        }
        else
        {
            w.pop();
        }
    }
    cout<<n;
    return 0;
}
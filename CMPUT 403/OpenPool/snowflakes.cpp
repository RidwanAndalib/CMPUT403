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
#include <unordered_set>
#include <queue>
using namespace std;
void process()
{
    queue<int> q;
    unordered_set<int> sfs;
    int n, sf, largest=0, size;
    cin>>n;
    while(n--)
    {
        cin>>sf;
        if(sfs.count(sf)!=0)
        {
            size=q.size();
            if(size>largest)
            {
                largest=size;
            }
            while(q.front()!=sf)
            {
                sfs.erase(q.front());
                q.pop();
            }
            q.pop();
            q.push(sf);
        }
        else
        {
            q.push(sf);
            sfs.insert(sf);
        }
    }
    size=q.size();
    if(size>largest)
    {
        largest=size;
    }
    cout<<largest<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tcases;
    cin>>tcases;
    while(tcases--)
    {
        process();
    }
    return 0;
}
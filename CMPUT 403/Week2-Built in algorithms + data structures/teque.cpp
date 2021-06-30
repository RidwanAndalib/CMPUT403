/*
  Problem: https://open.kattis.com/problems/teque
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://www.cplusplus.com/reference/deque/deque/

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    string s;
    deque<int> l;
    deque<int> r;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s>>x;
        if(s[0]=='g')
        {
            if(x<l.size())
                cout<<l[x]<<'\n';
            else
                cout<<r[x-l.size()]<<'\n';
        }
        else if(s[5]=='b')
        {
            r.push_back(x);
            if(l.size()+2==r.size())
            {
                l.push_back(r[0]);
                r.pop_front();
            }
        }
        else if(s[5]=='f')
        {
            l.push_front(x);
            if(l.size()==r.size()+2)
            {
                r.push_front(l.back());
                l.pop_back();
            }
        }
        else
        {
            if(l.size()<r.size())
            {
                l.push_back(r[0]);
                r.pop_front();
            }
            r.push_front(x);
            if(l.size()+2==r.size())
            {
                l.push_back(r[0]);
                r.pop_front();
            }
        }
    }
    return 0;
}

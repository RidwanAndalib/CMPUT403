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
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, wo, bo, wd, bd, longest, ws, bs, temp, w1, w2, b1, b2;
    cin>>n;
    vector<string> names;
    vector<int> wp1, wp2;
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        string name;
        cin>>name;
        names.push_back(name);
        if(i>3)
        {
            q.push(i);
        }
    }
    wo=0;
    w1=0;
    bo=1;
    b1=1;
    wd=2;
    w2=2;
    bd=3;
    b2=3;
    longest=0;
    ws=0;
    bs=0;
    char c;
    while(cin>>c)
    {
        if(c=='W')
        {
            ws++;
            temp=wo;
            wo=wd;
            wd=temp;
            if(bs>=longest)
            {
                if(bs>longest)
                {
                    wp1.clear();
                    wp2.clear();
                    longest=bs;
                }
                wp1.push_back(b1);
                wp2.push_back(b2);
            }
            bs=0;
            q.push(bd);
            bd=bo;
            b1=bd;
            bo=q.front();
            b2=bo;
            q.pop();
        }
        else
        {
            bs++;
            temp=bo;
            bo=bd;
            bd=temp;
            if(ws>=longest)
            {
                if(ws>longest)
                {
                    wp1.clear();
                    wp2.clear();
                    longest=ws;
                }
                wp1.push_back(w1);
                wp2.push_back(w2);
            }
            ws=0;
            q.push(wd);
            wd=wo;
            w1=wd;
            wo=q.front();
            w2=wo;
            q.pop();
        }
    }
    if(ws>=longest)
    {
        if(ws>longest)
        {
            wp1.clear();
            wp2.clear();
            longest=ws;
        }
        wp1.push_back(w1);
        wp2.push_back(w2);
    }
    if(bs>=longest)
    {
        if(bs>longest)
        {
            wp1.clear();
            wp2.clear();
            longest=bs;
        }
        wp1.push_back(b1);
        wp2.push_back(b2);
    }
    int winners=wp1.size();
    for(int i=0;i<winners;i++)
    {
        cout<<names[wp1[i]]<<' '<<names[wp2[i]]<<'\n';
    }
    return 0;
}
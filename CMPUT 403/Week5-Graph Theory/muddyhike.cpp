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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int r, c, currentr, currentc, newv, minpath;
    cin>>r>>c;
    int depths[r][c], shallowest[r][c];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>depths[i][j];
            if(j==0)
            {
                q.push(make_pair(depths[i][j],i*c+j));
                shallowest[i][j]=depths[i][j];
            }
            else
            {
                shallowest[i][j]=1000000;
            }
        }
    }
    while(!q.empty())
    {
        currentr=q.top().second/c;
        currentc=q.top().second%c;
        if(shallowest[currentr][currentc]==q.top().first)
        {
            q.pop();
            if(currentr!=0)
            {
                newv=max(shallowest[currentr][currentc],depths[currentr-1][currentc]);
                if(shallowest[currentr-1][currentc]>newv)
                {
                    shallowest[currentr-1][currentc]=newv;
                    q.push(make_pair(newv,(currentr-1)*c+currentc));
                }
            }
            if(currentr!=r-1)
            {
                newv=max(shallowest[currentr][currentc],depths[currentr+1][currentc]);
                if(shallowest[currentr+1][currentc]>newv)
                {
                    shallowest[currentr+1][currentc]=newv;
                    q.push(make_pair(newv,(currentr+1)*c+currentc));
                }
            }
            if(currentc!=0)
            {
                newv=max(shallowest[currentr][currentc],depths[currentr][currentc-1]);
                if(shallowest[currentr][currentc-1]>newv)
                {
                    shallowest[currentr][currentc-1]=newv;
                    q.push(make_pair(newv,currentr*c+currentc-1));
                }
            }
            if(currentc!=c-1)
            {
                newv=max(shallowest[currentr][currentc],depths[currentr][currentc+1]);
                if(shallowest[currentr][currentc+1]>newv)
                {
                    shallowest[currentr][currentc+1]=newv;
                    q.push(make_pair(newv,currentr*c+currentc+1));
                }
            }
        }
        else
        {
            q.pop();
        }
    }
    minpath=shallowest[0][c-1];
    for(int i=1;i<r;i++)
    {
        minpath=min(minpath,shallowest[i][c-1]);
    }
    cout<<minpath;
    return 0;
}
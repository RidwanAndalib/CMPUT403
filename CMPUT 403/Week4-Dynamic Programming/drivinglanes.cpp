/*
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://www.cplusplus.com/reference/cmath/abs/
  https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
  http://www.cplusplus.com/reference/algorithm/min/
  https://www.cplusplus.com/reference/climits/

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k, r;
    cin>>n>>m>>k>>r;
    long long l[250], s[250], c[250];
    long long curveddistance[250][250]={};
    long long shortest[250][250];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            shortest[i][j]=LLONG_MAX;
        }
    }
    for(int i=0;i<n;i++)
    {
        cin>>l[i];
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>s[i]>>c[i];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            curveddistance[i][j]=s[i]+c[i]*(j+1);
        }
    }
    for(int i=0;i<m;i++)
    {
        if(i*k<=l[0])
        {
            shortest[0][i]=l[0]+i*r+s[0]+c[0]*(i+1);
        }
    }
    for(int i1=1;i1<n;i1++)
    {
        for(int i2=0;i2<m;i2++)
        {
            if(shortest[i1-1][i2]==LLONG_MAX)
                continue;
            for(int i3=0;i3<m;i3++)
            {
                if(abs(i2-i3)*k>l[i1])
                    continue;
                shortest[i1][i3]=min(shortest[i1-1][i2]+l[i1]+abs(i2-i3)*r+curveddistance[i1][i3],shortest[i1][i3]);
            }
        }
    }
    cout<<shortest[n-1][0];
    return 0;
}
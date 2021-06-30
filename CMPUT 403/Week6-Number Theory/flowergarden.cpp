/*
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!
  
  Lecture slides:
  https://eclass.srv.ualberta.ca/mod/resource/view.php?id=4785518

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
#include <cmath>
using namespace std;
double getdistance(int x1, int y1, int x2, int y2)
{
    return sqrt((double)((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}
void processtestcase()
{
    int n, x, y, max, count, posx, posy;
    double d;
    cin>>n>>d;
    vector<bool> isprime(n+1, true);
    isprime[0]=false;
    isprime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(isprime[i])
        {
            for(int j=2*i;j<=n;j+=i)
            {
                isprime[j]=false;
            }
        }
    }
    max=0;
    count=0;
    posx=0;
    posy=0;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        d-=getdistance(x,y,posx,posy);
        posx=x;
        posy=y;
        if(d>=0)
        {
            count++;
            if(isprime[count])
            {
                max=count;
            }
        }
    }
    cout<<max<<'\n';
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        processtestcase();
    }
    return 0;
}
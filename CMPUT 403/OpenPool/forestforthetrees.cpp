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
using namespace std;
typedef long long ll;
ll xl, xh, yl, yh;
bool isTree(ll x, ll y)
{
    if(x>=xl and x<=xh and y>=yl and y<=yh)
    {
        return false;
    }
    else
    {
        return true;
    }
}
ll gcd (ll a, ll b)
{
    if(b)
    {
        return gcd(b,a%b);
    }
    else
    {
        return a;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll bx, by, stepx, stepy;
    cin>>bx>>by>>xl>>yl>>xh>>yh;
    ll d=gcd(bx,by);
    if(d==1)
    {
        cout<<"Yes";
        return 0;
    }
    stepx=bx/d;
    stepy=by/d;
    if(isTree(stepx,stepy))
    {
        cout<<"No\n"<<stepx<<' '<<stepy;
        return 0;
    }
    bool obstucted=false;
    ll l=0, r=d, m=(l+r)/2;
    while(m!=l and m!=r)
    {
        if(isTree(stepx*m,stepy*m))
        {
            obstucted=true;
            r=m;
        }
        else
        {
            l=m;
        }
        m=(l+r)/2;
    }
    if(obstucted)
    {
        cout<<"No\n"<<stepx*r<<' '<<stepy*r;
    }
    else
    {
        cout<<"Yes";
    }
    return 0;
}
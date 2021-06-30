/*
  Problem: https://open.kattis.com/problems/candydistribution
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
using namespace std;
int gcd(int a, int b)
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
void processdataset()
{
    int k, c;
    cin>>k>>c;
    if(k==1 and c==1)
    {
        cout<<"2\n";
        return;
    }
    if(k==1)
    {
        cout<<"1\n";
        return;
    }
    if(c==1)
    {
        cout<<k+1<<'\n';
        return;
    }
    if(gcd(k,c)==1)
    {
        int r1, r2, s1, s2, t1, t2, q, temp;
        r1=c;
        r2=k;
        s1=1;
        s2=0;
        t1=0;
        t2=1;
        while(r2)
        {
            q=r1/r2;
            temp=r1-(q*r2);
            r1=r2;
            r2=temp;
            temp=s1-(q*s2);
            s1=s2;
            s2=temp;
            temp=t1-(q*t2);
            t1=t2;
            t2=temp;
        }
        cout<<(s1%k+k)%k<<'\n';
        return;
    }
    else
    {
        cout<<"IMPOSSIBLE\n";
        return;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int d;
    cin>>d;
    while(d--)
    {
        processdataset();
    }
    return 0;
}

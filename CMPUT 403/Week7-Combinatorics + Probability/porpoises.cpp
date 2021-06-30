/*
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!
  
  Lecture Video

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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long int	a[49], b[49], c[49], d[49], two[49], y, fiba, fibb, fibc, fibd, tempa,tempb, tempc, tempd;
    int p, k;
    a[0]=1;
    b[0]=1;
    c[0]=1;
    d[0]=0;
    two[0]=1;
    for(int i=1;i<49;i++)
    {
        two[i]=2*two[i-1];
        a[i]=((a[i-1]*a[i-1])%1000000000+(b[i-1]*c[i-1])%1000000000)%1000000000;
        b[i]=((a[i-1]*b[i-1])%1000000000+(b[i-1]*d[i-1])%1000000000)%1000000000;
        c[i]=((a[i-1]*c[i-1])%1000000000+(d[i-1]*c[i-1])%1000000000)%1000000000;
        d[i]=((b[i-1]*c[i-1])%1000000000+(d[i-1]*d[i-1])%1000000000)%1000000000;
    }
    cin>>p;
    while(p--)
    {
        fiba=1;
        fibb=0;
        fibc=0;
        fibd=1;
        cin>>k>>y;
        for(int i=48;i>=0;i--)
        {
            if(y>=two[i])
            {
                tempa=fiba;
                tempb=fibb;
                tempc=fibc;
                tempd=fibd;
                y-=two[i];
                fiba=((tempa*a[i])%1000000000+(tempb*c[i])%1000000000)%1000000000;
                fibb=((tempa*b[i])%1000000000+(tempb*d[i])%1000000000)%1000000000;
                fibc=((tempc*a[i])%1000000000+(tempd*c[i])%1000000000)%1000000000;
                fibd=((tempc*b[i])%1000000000+(tempd*d[i])%1000000000)%1000000000;
            }
        }
        cout<<k<<' '<<fibc<<'\n';
    }
    return 0;
}
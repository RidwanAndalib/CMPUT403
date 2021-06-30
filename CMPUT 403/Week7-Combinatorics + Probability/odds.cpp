/*
  Problem: https://open.kattis.com/problems/odds
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
int strengthclass(int d1, int d2)
{
    if((d1==1 and d2==2) or (d1==2 and d2==1))
        return 3;
    else if(d1==d2)
        return 2;
    else
        return 1;
}
int eval(int d1, int d2, int values[][6])
{
    if(values[d1-1][d2-1]==0)
    {
        if(d1>d2)
        {
            values[d1-1][d2-1]=d1*10+d2;
            values[d2-1][d1-1]=values[d1-1][d2-1];
        }
        else
        {
            values[d1-1][d2-1]=d2*10+d1;
            values[d2-1][d1-1]=values[d1-1][d2-1];
        }
    }
    return values[d1-1][d2-1];
}
bool p1win(int s0, int s1, int r0, int r1, int values[][6])
{
    int str1=strengthclass(s0,s1);
    int str2=strengthclass(r0,r1);
    if(str1>str2)
    {
        return true;
    }
    else if(str2>str1)
    {
        return false;
    }
    else
    {
        if(str1==1)
        {
            if(eval(s0,s1,values)>eval(r0,r1,values))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(str1==2)
        {
            if(s0>r0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    
}
void process(char s0, char s1, char r0, char r1, int values[][6])
{
    int l1s, l1e, l2s, l2e, l3s, l3e, l4s, l4e, n, d, divisor;
    n=0;
    d=0;
    if(s0=='*')
    {
        l1s=1;
        l1e=6;
    }
    else
    {
        l1s=s0-'0';
        l1e=l1s;
    }
    if(s1=='*')
    {
        l2s=1;
        l2e=6;
    }
    else
    {
        l2s=s1-'0';
        l2e=l2s;
    }
    if(r0=='*')
    {
        l3s=1;
        l3e=6;
    }
    else
    {
        l3s=r0-'0';
        l3e=l3s;
    }
    if(r1=='*')
    {
        l4s=1;
        l4e=6;
    }
    else
    {
        l4s=r1-'0';
        l4e=l4s;
    }
    for(int i1=l1s;i1<=l1e;i1++)
    {
        for(int i2=l2s;i2<=l2e;i2++)
        {
            for(int i3=l3s;i3<=l3e;i3++)
            {
                for(int i4=l4s;i4<=l4e;i4++)
                {
                    d++;
                    if(p1win(i1,i2,i3,i4,values))
                    {
                        n++;
                    }
                }
            }
        }
    }
    if(n==0)
    {
        cout<<"0\n";
    }
    else if(n==d)
    {
        cout<<"1\n";
    }
    else
    {
        divisor=gcd(n,d);
        n/=divisor;
        d/=divisor;
        cout<<n<<'/'<<d<<'\n';
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    char s0, s1, r0, r1;
    int values[6][6]={0};
    while(true)
    {
        cin>>s0>>s1>>r0>>r1;
        if(s0=='0' and s1=='0' and r0=='0' and r1=='0')
            break;
        process(s0,s1,r0,r1, values);
        
    }
    return 0;
}

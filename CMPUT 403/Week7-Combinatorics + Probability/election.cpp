/*
  Problem: https://open.kattis.com/problems/election
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
#include <cmath>
using namespace std;
unsigned long long int comb(int n, int k, unsigned long long int c[][51])
{
    if(c[n][k]==0)
    {
        c[n][k]=comb(n-1,k,c)+comb(n-1,k-1,c);
    }
    return c[n][k];
}
void process(unsigned long long int c[][51])
{
    int n, v1, v2, w, votestowin, pn;
    unsigned long long int total, possible;
    cin>>n>>v1>>v2>>w;
    votestowin=(n/2)+1;
    if((n-v2)<votestowin)
    {
        cout<<"RECOUNT!\n";
        return;
    }
    pn=n-v1-v2;
    total=0;
    for(int i=votestowin-v1;i<=pn;i++)
    {
        total+=comb(pn,i,c);
    }
    possible=pow(2,pn);
    if(((double)total/possible)*100>w)
    {
        cout<<"GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!\n";
        return;
    }
    cout<<"PATIENCE, EVERYONE!\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned long long int c[51][51];
    for(int n=0;n<51;n++)
    {
        for(int k=0;k<=n;k++)
        {
            if(k==1)
            {
                c[n][k]=n;
                continue;
            }
            if(k==0 or k==n)
            {
                c[n][k]=1;
                continue;
            }
            c[n][k]=0;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        process(c);
    }
    return 0;
}

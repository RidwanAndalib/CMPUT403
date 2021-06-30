/*
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!
  
  Lecture Video
  https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/
#include <iostream>
#include <algorithm>
using namespace std;
void computeLPSArray(int pat[], int M, int* lps) 
{
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<M)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
    return;
}
void KMPSearch(int pat[], int txt[], int n)
{ 
    int M=n;
    int N=2*n;
    int lps[M];
    computeLPSArray(pat, M, lps);
    int i=0;
    int j=0;
    while(i<N)
    {
        if(pat[j]==txt[i])
        {
            j++;
            i++;
        }
        if(j==M)
        {
            cout<<"possible\n";
            return;
        }
        else if(i<N&&pat[j]!=txt[i])
        {
            if(j!=0)
                j=lps[j-1];
            else
                i=i+1;
        }
    }
    cout<<"impossible\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int c1[n], c2[n];
    for(int i=0;i<n;i++)
    {
        cin>>c1[i];
    }
    sort(c1,c1+n);
    for(int i=0;i<n;i++)
    {
        cin>>c2[i];
    }
    sort(c2,c2+n);
    int txt[2*n], pat[n];
    for(int i=0;i<n-1;i++)
    {
        txt[i]=c1[i+1]-c1[i];
        txt[i+n]=txt[i];
        pat[i]=c2[i+1]-c2[i];
    }
    txt[n-1]=360000+c1[0]-c1[n-1];
    txt[(2*n)-1]=txt[n-1];
    pat[n-1]=360000+c2[0]-c2[n-1];
    KMPSearch(pat,txt,n);
    return 0;
}
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
void printpath(int c[], int s, int path[])
{
    if(path[s]!=-2)
    {
        printpath(c,s-c[path[s]-1],path);
        cout<<path[s]<<' ';
    }
}
void expandpath(int c[], int i, int path[], int maxs)
{
    for(int j=0;j<=maxs;j++)
    {
        if(path[j]!=0)
        {
            if(path[j]==-1)
            {
                path[j+c[i]]=-1;
            }
            else
            {
                if(path[j+c[i]]==0)
                {
                    path[j+c[i]]=i+1;
                }
                else
                {
                    path[j+c[i]]=-1;
                }
                
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, maxs;
    int path[31001]={};
    cin>>n;
    int c[n];
    for(int i=0;i<n;i++)
        cin>>c[i];
    cin>>m;
    int s[m];
    for(int i=0;i<m;i++)
    {
        cin>>s[i];
        if(i==0)
            maxs=s[i];
        else
            maxs=max(maxs,s[i]);
    }
    path[0]=-2;
    for(int i=0;i<n;i++)
    {
        expandpath(c,i,path,maxs);
    }
    for(int i=0;i<m;i++)
    {
        if(path[s[i]]==0)
            cout<<"Impossible\n";
        else if(path[s[i]]==-1)
            cout<<"Ambiguous\n";
        else
        {
            printpath(c,s[i],path);
            cout<<'\n';
        }
    }
    return 0;
}
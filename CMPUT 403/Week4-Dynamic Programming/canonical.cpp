/*
  Problem: https://open.kattis.com/problems/canonical
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://en.wikipedia.org/wiki/Change-making_problem
  https://www.researchgate.net/publication/220150545_Optimal_Bounds_for_the_Change-Making_Problem
  http://www.cplusplus.com/reference/algorithm/min/

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
int greedify(int x, int n, int c[])
{
    int count, q;
    count=0;
    n--;
    while(x!=0)
    {
        if(x>=c[n])
        {
            q=x/c[n];
            x-=c[n]*q;
            count+=q;
        }
        n--;
    }
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, end, i, j;
    cin>>n;
    int c[n];
    for(i=0;i<n;i++)
        cin>>c[i];
    end=c[n-1]+c[n-2];
    int memo[n][end];
    for(i=0;i<end;i++)
        memo[0][i]=i;
    for(i=1;i<n-1;i++)
    {
        for(j=0;j<end;j++)
        {
            if(c[i]>j)
                memo[i][j]=memo[i-1][j];
            else
                memo[i][j]=min(memo[i][j-c[i]]+1,memo[i-1][j]);
        }
    }
    for(j=0;j<end;j++)
    {
        if(c[i]>j)
            memo[i][j]=memo[i-1][j];
        else
            memo[i][j]=min(memo[i][j-c[i]]+1,memo[i-1][j]);
        if(memo[i][j]!=greedify(j,n,c))
        {
            cout<<"non-canonical";
            return 0;
        }
    }
    cout<<"canonical";
    return 0;
}

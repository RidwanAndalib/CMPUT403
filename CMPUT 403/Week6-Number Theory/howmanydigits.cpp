/*
  Problem: https://open.kattis.com/problems/howmanydigits
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
#include <vector>
#include <cmath>
using namespace std;
double memoize(int n, vector<double> &memo)
{
    if(memo[n]==-1)
    {
        memo[n]=memoize(n-1,memo)+log10(n);
    }
    return memo[n];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<double> memo(1000001, -1);
    memo[0]=0;
    memo[1]=0;
    while(cin>>n)
    {
        cout<<(int)memoize(n,memo)+1<<'\n';
    }
    return 0;
}

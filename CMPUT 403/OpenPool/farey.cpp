/*
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!
  
  https://github.com/UAPSPC/Code-Archive/blob/aec4f893e30c90081c0b4d91f5489ada2414a63b/num_theory/eulerphi.c?fbclid=IwAR3xsFWUu3sC-x5hXzVWunU5TmL1hiHGP0-SoyTqwXgfUj21Q_UHYZHxOAY

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
#include <math.h>
using namespace std;
vector<int> memo(10010, -1);
int phi(int n){
  int i, count, res = 1;
  
  for(i = 2; i*i <= n; i++){
    count = 0;
    while(n % i == 0){
      n /= i;
      count++;
    }
    if(count > 0) res *= (pow(i, count)-pow(i, count-1));
  }
  if(n > 1) res *= (n-1);
  return res;
}
void processcase()
{
    int t, n;
    long int total=0;
    cin>>t>>n;
    for(int i=0;i<=n;i++)
    {
        if(memo[i]==-1)
        {
            memo[i]=phi(i);
        }
        total+=memo[i];
    }
    cout<<t<<' '<<total<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    while(n--)
    {
        processcase();
    }
    return 0;
}
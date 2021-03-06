/*
  Problem: https://open.kattis.com/problems/pieceofcake2
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
int main()
{
    int n, h, v;
    cin>>n>>h>>v;
    if(h<(n*0.5))
        h=n-h;
    if(v<(n*0.5))
        v=n-v;
    cout<<4*h*v;
    return 0;
}

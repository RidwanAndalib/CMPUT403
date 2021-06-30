/*
  Problem: https://open.kattis.com/problems/ants
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
    int c, l, n, p, min, max, hl, sp, lp;
    cin>>c;
    for(int i=0;i<c;i++)
    {
        cin>>l>>n;
        min=0;
        max=0;
        hl=l/2;
        for(int j=0;j<n;j++)
        {
            cin>>p;
            if(p<hl)
            {
                sp=p;
                lp=l-p;
            }
            else
            {
                sp=l-p;
                lp=p;
            }
            if(sp>min)
                min=sp;
            if(lp>max)
                max=lp;
        }
        cout<<min<<" "<<max<<"\n";
    }
    return 0;
}

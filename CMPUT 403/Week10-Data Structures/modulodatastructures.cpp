/*
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!
  
  Lecture Video
  Textbook

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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long Arr[200000];
    long long bucket[560][560];
    int n, q, t, a, b, c, d;
    cin>>n>>q;
    double sqN=sqrt(n);
    for(int i=0;i<q;i++)
    {
        cin>>t;
        if(t==1)
        {
            cin>>a>>b>>c;
            if(b<=sqN)
            {
                bucket[b][a]+=c;
            }
            else
            {
                for(int j=a;j<=n;j+=b)
                {
                    Arr[j]+=c;
                }
            }
        }
        else
        {
            cin>>d;
            long long bsum=Arr[d];
            for(b=1;b<=sqN;b++)
            {
                bsum+=bucket[b][d%b];
            }
            cout<<bsum<<'\n';
        }
    }
    return 0;
}
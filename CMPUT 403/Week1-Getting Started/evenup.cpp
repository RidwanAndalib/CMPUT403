/*
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  http://www.cplusplus.com/reference/stack/stack/stack/

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n, x;
    cin>>n;
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        x%=2;
        if(s.empty())
            s.push(x);
        else
        {
            if(s.top()==x)
                s.pop();
            else
                s.push(x);
        }
    }
    cout<<s.size();
    return 0;
}
/*
  Problem: https://open.kattis.com/problems/symmetricorder
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
#include <string>
using namespace std;
void helper(int n)
{
    string s1, s2;
    if(n>2)
    {
        cin>>s1>>s2;
        cout<<s1<<"\n";
        helper(n-2);
        cout<<s2<<"\n";
    }
    else if(n==2)
    {
        cin>>s1>>s2;
        cout<<s1<<"\n";
        cout<<s2<<"\n";
    }
    else
    {
        cin>>s1;
        cout<<s1<<"\n";
    }
}

int main()
{
    int n;
    for(int i=1;1;i++)
    {
        cin>>n;
        if(n==0)
            break;
        cout<<"SET "<<i<<"\n";
        helper(n);
    }
    return 0;
}

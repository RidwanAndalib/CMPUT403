/*
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  http://www.cplusplus.com/reference/stack/stack/stack/
  http://www.cplusplus.com/reference/string/string/getline/

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
#include <string>
using namespace std;
int main()
{
    int n;
    char c;
    string s;
    bool op1, op2;
    cin>>n;
    bool arr[n];
    stack<bool> st;
    for(int i=0;i<n;i++)
    {
        cin>>c;
        if(c=='T')
            arr[i]=true;
        else
            arr[i]=false;
    }
    getline(cin,s);
    getline(cin,s);
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!=' ')
        {
            if(s[i]=='+')
            {
                op1=st.top();
                st.pop();
                op2=st.top();
                st.pop();
                st.push(op1 or op2);
            }
            else if(s[i]=='-')
            {
                st.top()=!st.top();
            }
            else if(s[i]=='*')
            {
                op1=st.top();
                st.pop();
                op2=st.top();
                st.pop();
                st.push(op1 and op2);
            }
            else
            {
                st.push(arr[s[i]-'A']);
            }
        }
    }
    if(st.top())
        cout<<'T';
    else
        cout<<'F';
    return 0;
}
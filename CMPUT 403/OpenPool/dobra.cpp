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
#include <string>
using namespace std;
int chartype(char c)
{
    if(c=='_')
    {
        return 3;
    }
    else if(c=='A' or c=='E' or c=='I' or c=='O' or c=='U')
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
long long processString(string s, int nc, int nv, int nl, int index, int size)
{
    if(nc>2 or nv>2)
    {
        return 0;
    }
    if(index==size)
    {
        if(nl>0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    long long total=0;
    int ct=chartype(s[index]);
    if(ct==1)
    {
        total+=processString(s,0,nv+1,nl,index+1,size);
    }
    else if(ct==2)
    {
        if(s[index]=='L')
        {
            nl++;
        }
        total+=processString(s,nc+1,0,nl,index+1,size);
    }
    else
    {
        total+=processString(s,0,nv+1,nl,index+1,size)*5;
        total+=processString(s,nc+1,0,nl,index+1,size)*20+processString(s,nc+1,0,nl+1,index+1,size);
    }
    return total;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    cout<<processString(s,0,0,0,0,s.size());
    return 0;
}
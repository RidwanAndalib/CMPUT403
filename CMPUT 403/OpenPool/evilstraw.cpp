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
#include <vector>
#include <algorithm>
using namespace std;
bool isValid(string s, int len)
{
    vector<int> countc(26,0);
    int odd=0;
    for(int i=0;i<len;i++)
    {
        countc[s[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(countc[i]%2==1)
        {
            odd++;
        }
    }
    if(len%2==0)
    {
        if(odd)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        if(odd>1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
int getSwaps(int l, int r, string s)
{
    if(l>=r)
    {
        return 0;
    }
    int ml, mr;
    for(ml=r;ml>l;ml--)
    {
        if(s[ml]==s[l])
        {
            break;
        }
    }
    for(mr=l;mr<r;mr++)
    {
        if(s[mr]==s[r])
        {
            break;
        }
    }
    int ld=mr-l;
    int rd=r-ml;
    int total;
    if(ld<rd)
    {
        total=ld;
        for(int i=mr;i>l;i--)
        {
            swap(s[i],s[i-1]);
        }
    }
    else
    {
        total=rd;
        for(int i=ml;i<r;i++)
        {
            swap(s[i],s[i+1]);
        }
    }
    return total+getSwaps(l+1,r-1,s);
}
void processString(string s)
{
    int len=s.size();
    if(!isValid(s,len))
    {
        cout<<"Impossible\n";
        return;
    }
    cout<<getSwaps(0,len-1,s)<<'\n';
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, p=0;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        processString(s);
    }
    return 0;
}
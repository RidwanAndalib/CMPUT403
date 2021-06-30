/*
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  http://www.cplusplus.com/reference/algorithm/next_permutation/
  https://www.cplusplus.com/reference/set/set/
  https://www.cplusplus.com/reference/utility/pair/pair/
  http://www.cplusplus.com/reference/unordered_map/unordered_map/

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
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<pair<int,int>> p;
    unordered_map<string,int> sm;
    int m, n, i1, i2;
    bool found;
    int iarr[10];
    string sarr[10];
    string s1, s2;
    while(cin>>n)
    {
        p.clear();
        sm.clear();
        for(int i=0;i<n;i++)
        {
            cin>>s1;
            sarr[i]=s1;
            iarr[i]=i;
        }
        sort(sarr,sarr+n);
        for(int i=0;i<n;i++)
            sm[sarr[i]]=i;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            cin>>s1>>s2;
            i1=sm[s1];
            i2=sm[s2];
            p.emplace(make_pair(i1,i2));
            p.emplace(make_pair(i2,i1));
        }
        found=false;
        do
        {
            found=true;
            for(int i=0;i<n-1;i++)
            {
                if(p.count(make_pair(iarr[i],iarr[i+1]))!=0)
                {
                    found=false;
                    break;
                }
            }
            if(found)
                break;
        } while(next_permutation(iarr,iarr+n));
        if(found)
        {
            cout<<sarr[iarr[0]];
            for(int i=1;i<n;i++)
            {
                cout<<' '<<sarr[iarr[i]];
            }
            cout<<'\n';
        }
        else
            cout<<"You all need therapy.\n";
    }
    return 0;
}
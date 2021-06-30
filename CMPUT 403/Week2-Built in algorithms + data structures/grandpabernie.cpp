/*
  Problem: https://open.kattis.com/problems/grandpabernie
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  http://www.cplusplus.com/reference/unordered_map/unordered_map/
  https://www.cplusplus.com/reference/vector/vector/
  http://www.cplusplus.com/reference/algorithm/sort/
  https://www.geeksforgeeks.org/fast-io-for-competitive-programming/

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
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, y, z;
    z=0;
    string x;
    unordered_map<string,int> m;
    vector<int> v[100000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        if(m.count(x)==0)
        {
            m[x]=z;
            z++;
        }
        v[m[x]].push_back(y);
    }
    for(int i=0;i<z;i++)
        sort(v[i].begin(),v[i].end());
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        cout<<v[m[x]][y-1]<<"\n";
    }
    return 0;
}

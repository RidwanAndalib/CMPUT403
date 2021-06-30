/*
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  https://www.cplusplus.com/reference/map/map/map/
  https://stackoverflow.com/questions/1939953/how-to-find-if-a-given-key-exists-in-a-c-stdmap

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/

#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n, d, x;
    unsigned long long int count;
    map<int,int> m;
    count=0;
    cin>>n>>d;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        x=x/d;
        if(m.count(x)==0)
            m[x]=0;
        count+=m[x];
        m[x]++;
    }
    cout<<count;
    
    return 0;
}
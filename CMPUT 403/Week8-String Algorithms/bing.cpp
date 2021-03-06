/*
  Problem: https://open.kattis.com/problems/bing
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
#include <unordered_map>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<string,int> m;
    string word;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>word;
        cout<<m[word]<<'\n';
        for(int i=0;i<word.size();i++)
        {
            m[word.substr(0,i+1)]++;
        }
    }
    return 0;
}

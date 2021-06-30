/*
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!
  
  Lecture Video
  https://eclass.srv.ualberta.ca/pluginfile.php/7015489/mod_resource/content/1/hashing.cpp

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
const __uint128_t X=8675309;
const uint64_t P=9223372036854775783;
const __uint128_t INV_X=8261199684264045559;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, maxlen=0;
    cin>>n;
    string s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        maxlen=max(maxlen,(int)s[i].length());
    }
    vector<__uint128_t> xp(1, 1);
    for(int i=0;i<maxlen;i++)
    {
        xp.push_back((xp.back()*X)%P);
    }
    vector<__uint128_t> poly[n];
    map<__uint128_t,int> shm;
    for(int i=0;i<n;i++)
    {
        poly[i].push_back(0);
        int len=s[i].length();
        for(int j=0;j<len;j++)
        {
            poly[i].push_back((poly[i].back()+xp[j]*s[i][j])%P);
        }
        shm[poly[i][len]]++;
    }
    bool typo=false;
    for(int i=0;i<n;i++)
    {
        int len=s[i].length();
        __uint128_t value;
        for(int j=0;j<len;j++)
        {
            if(j==len-1)
            {
                value=poly[i][len-1];
            }
            else
            {
                value=(poly[i][j]+((P+poly[i][len]-poly[i][j+1])*INV_X)%P)%P;
            }
            if(shm[value]!=0)
            {
                typo=true;
                cout<<s[i]<<'\n';
                break;
            }
        }
    }
    if(!typo)
    {
        cout<<"NO TYPOS\n";
    }
    return 0;
}
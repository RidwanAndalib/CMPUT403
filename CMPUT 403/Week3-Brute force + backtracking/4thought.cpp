/*
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

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
#include <unordered_map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<int,string> um;
    
    // *+-/

    um[256]="***";
    um[68]="**+";
    um[60]="**-";
    um[16]="**/";
    um[32]="*+*";
    um[24]="*++";
    //um[16]="*+-";
    um[17]="*+/";
    um[0]="*-*";
    //um[16]="*-+";
    um[8]="*--";
    um[15]="*-/";
    //um[16]="*/*";
    //um[8]="*/+";
    //um[0]="*/-";
    um[1]="*//";
    
    //um[68]="+**";
    //um[24]="+*+";
    //um[16]="+*-";
    //um[8]="+*/";
    //um[24]="++*";
    //um[16]="+++";
    //um[8]="++-";
    um[9]="++/";
    um[-8]="+-*";
    //um[8]="+-+";
    //um[0]="+--";
    um[7]="+-/";
    //um[8]="+/*";
    //um[9]="+/+";
    //um[1]="+/-";
    um[4]="+//";
    
    um[-60]="-**";
    //um[-8]="-*+";
    um[-16]="-*-";
    //um[0]="-*/";
    //um[16]="-+*";
    //um[8]="-++";
    //um[0]="-+-";
    //um[1]="-+/";
    //um[-16]="--*";
    //um[0]="--+";
    //um[-8]="---";
    um[-1]="--/";
    //um[0]="-/*";
    //um[7]="-/+";
    //um[-1]="-/-";
    //um[4]="-//";

    //um[16]="/**";
    //um[8]="/*+";
    //um[0]="/*-";
    //um[1]="/*/";
    //um[17]="/+*";
    //um[9]="/++";
    //um[1]="/+-";
    um[2]="/+/";
    um[-15]="/-*";
    //um[1]="/-+";
    um[-7]="/--";
    //um[0]="/-/";
    //um[0]="//*";
    //um[4]="//+";
    um[-4]="//-";
    //um[0]="///";
    int m, n;
    string s;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>n;
        if(um.count(n)!=0)
            cout<<"4 "<<um[n][0]<<" 4 "<<um[n][1]<<" 4 "<<um[n][2]<<" 4 = "<<n<<'\n';
        else
            cout<<"no solution\n";
    }
    return 0;
}
/*
  Problem: https://open.kattis.com/problems/justforsidekicks
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!
  
  Lecture Video
  https://eclass.srv.ualberta.ca/pluginfile.php/6659187/mod_resource/content/2/supercomputer.cpp

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/
#include <iostream>
using namespace std;
#define MAXN (1<<20)
int tree[6][2*MAXN-1]={};
void update(int b, int t)
{
  int node=b+MAXN-1;
  tree[t][node]^=1;
  do {
    node = (node-1)>>1;
    tree[t][node] = tree[t][2*node+1] + tree[t][2*node+2];
  } while (node != 0);
}
int query(int i, int j, int t, int node = 0, int l = 0, int r = MAXN) {
  if (i <= l && r <= j) return tree[t][node];
  if (r <= i || j <= l) return 0;
  int m = (l+r)>>1;
  return query(i, j,t, 2*node+1, l, m) + query(i, j,t, 2*node+2, m, r);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, v[6];
    cin>>n>>q>>v[0]>>v[1]>>v[2]>>v[3]>>v[4]>>v[5];
    int p[n];
    for(int i=0;i<n;i++)
    {
        char c;
        cin>>c;
        p[i]=c-'0'-1;
        update(i,p[i]);
    }
    for(int i=0;i<q;i++)
    {
        int i1, i2, i3;
        cin>>i1>>i2>>i3;
        if(i1==1)
        {
            update(i2-1,p[i2-1]);
            p[i2-1]=i3-1;
            update(i2-1,p[i2-1]);
        }
        else if(i1==2)
        {
            v[i2-1]=i3;
        }

        else
        { 
            long long s[6];
            long long sum;
            s[0]=query(i2-1,i3,0);
            s[1]=query(i2-1,i3,1);
            s[2]=query(i2-1,i3,2);
            s[3]=query(i2-1,i3,3);
            s[4]=query(i2-1,i3,4);
            s[5]=query(i2-1,i3,5);
            sum=s[0]*v[0]+s[1]*v[1]+s[2]*v[2]+s[3]*v[3]+s[4]*v[4]+s[5]*v[5];
            cout<<sum<<'\n';
        }
    }
    return 0;
}

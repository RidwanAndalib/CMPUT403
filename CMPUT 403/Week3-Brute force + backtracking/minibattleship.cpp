/*
  Problem: https://open.kattis.com/problems/minibattleship
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
using namespace std;
bool placeShip(int n, int x, int y, int z, int ss, int pg[5][5], char cg[5][5])
{
    if(z==0)
    {
        if(y+ss-1>=n)
            return false;
        for(int i=0;i<ss;i++)
        {
            if(pg[x][y+i]!=0)
                return false;
            if(cg[x][y+i]=='X')
                return false;
            pg[x][y+i]++;
        }
    }
    else
    {
        if(x+ss-1>=n)
            return false;
        for(int i=0;i<ss;i++)
        {
            if(pg[x+i][y]!=0)
                return false;
            if(cg[x+i][y]=='X')
                return false;
            pg[x+i][y]++;
        }
        
    }
    return true;
}
bool validateHit(int n, int pg[5][5], char cg[5][5])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(cg[i][j]=='O')
                if(pg[i][j]==0)
                    return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, count;
    count=0;
    char cg[5][5];
    int pg1[5][5];
    int pg2[5][5];
    int pg3[5][5];
    int pg4[5][5];
    int pg5[5][5];
    int ss[5];
    cin>>n>>k;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>cg[i][j];
    for(int i=0;i<k;i++)
        cin>>ss[i];
    for(int i1=0;i1<n;i1++)
    {
        for(int j1=0;j1<n;j1++)
        {
            for(int o1=0;o1<2;o1++)
            {
                if(ss[0]==1 and o1==1)
                    continue;
                for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                        pg1[i][j]=0;
                if(!placeShip(n,i1,j1,o1,ss[0],pg1,cg))
                    continue;
                if(k==1)
                {
                    if(validateHit(n,pg1,cg))
                        count++;
                }
                else
                {
                    for(int i2=0;i2<n;i2++)
                    {
                        for(int j2=0;j2<n;j2++)
                        {
                            for(int o2=0;o2<2;o2++)
                            {
                                if(ss[1]==1 and o2==1)
                                    continue;
                                for(int i=0;i<n;i++)
                                    for(int j=0;j<n;j++)
                                        pg2[i][j]=pg1[i][j];
                                if(!placeShip(n,i2,j2,o2,ss[1],pg2,cg))
                                    continue;
                                if(k==2)
                                {
                                    if(validateHit(n,pg2,cg))
                                        count++;
                                }
                                else
                                {
                                    for(int i3=0;i3<n;i3++)
                                    {
                                        for(int j3=0;j3<n;j3++)
                                        {
                                            for(int o3=0;o3<2;o3++)
                                            {
                                                if(ss[2]==1 and o3==1)
                                                    continue;
                                                for(int i=0;i<n;i++)
                                                    for(int j=0;j<n;j++)
                                                        pg3[i][j]=pg2[i][j];
                                                if(!placeShip(n,i3,j3,o3,ss[2],pg3,cg))
                                                    continue;
                                                if(k==3)
                                                {
                                                    if(validateHit(n,pg3,cg))
                                                        count++;
                                                }
                                                else
                                                {
                                                    for(int i4=0;i4<n;i4++)
                                                    {
                                                        for(int j4=0;j4<n;j4++)
                                                        {
                                                            for(int o4=0;o4<2;o4++)
                                                            {
                                                                if(ss[3]==1 and o4==1)
                                                                    continue;
                                                                for(int i=0;i<n;i++)
                                                                    for(int j=0;j<n;j++)
                                                                        pg4[i][j]=pg3[i][j];
                                                                if(!placeShip(n,i4,j4,o4,ss[3],pg4,cg))
                                                                    continue;
                                                                if(k==4)
                                                                {
                                                                    if(validateHit(n,pg4,cg))
                                                                        count++;
                                                                }
                                                                else
                                                                {
                                                                    for(int i5=0;i5<n;i5++)
                                                                    {
                                                                        for(int j5=0;j5<n;j5++)
                                                                        {
                                                                            for(int o5=0;o5<2;o5++)
                                                                            {
                                                                                if(ss[4]==1 and o5==1)
                                                                                    continue;
                                                                                for(int i=0;i<n;i++)
                                                                                    for(int j=0;j<n;j++)
                                                                                        pg5[i][j]=pg4[i][j];
                                                                                if(!placeShip(n,i5,j5,o5,ss[4],pg5,cg))
                                                                                    continue;
                                                                                if(validateHit(n,pg5,cg))
                                                                                    count++;
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<count;
    return 0;
}

/*
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!
  
  Lecture Video
  https://eclass.srv.ualberta.ca/pluginfile.php/7035236/mod_resource/content/1/collidingtraffic.cpp?fbclid=IwAR0dBOyrnvuSba5KC2H5z0VdWpfvkj7oYerAV1aIZGUZhXEcHz-nK0Hzt2Y

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define SQR(x) ((x)*(x))
#define EPS 1e-8
typedef struct
{
  double x, y, z;
} Point;
double dot(Point p, Point q)
{ 
    return p.x*q.x+p.y*q.y+p.z*q.z;
}
void process()
{
    Point s, d, v;
    double r, temp;
    cin>>s.x>>s.y>>s.z>>r>>v.x>>v.y>>v.z>>d.x>>d.y>>d.z>>temp;
    r+=temp;
    cin>>temp;
    v.x-=temp;
    cin>>temp;
    v.y-=temp;
    cin>>temp;
    v.z-=temp;
    Point d0;
    d0.x=s.x-d.x;
    d0.y=s.y-d.y;
    d0.z=s.z-d.z;
    double A=dot(v, v);
    double B=2*dot(d0,v);
    double C=dot(d0, d0)-r*r;
    if (fabs(A) < EPS)
    {
        cout<<"No collision\n";
        return;
    }
    if (B*B < 4*A*C)
    {
        cout<<"No collision\n";
        return;
    }
    double t = (-B - sqrt(B*B - 4*A*C))/(2*A);
    if (t<0)
    {
        cout<<"No collision\n";
        return;
    }
    cout<<t<<endl;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    while(n--)
    {
        process();
    }
    return 0;
}
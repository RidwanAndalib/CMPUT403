/*
  Problem: https://open.kattis.com/problems/biggesttriangle
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!
  
  Lecture Video
  https://github.com/UAPSPC/Code-Archive/blob/master/2d_geometry/isect_iline.c

  List any classmate you discussed the problem with. Remember, you can only
  have high-level verbal discussions. No code should be shared, developed,
  or even looked at in these chats. No formulas or pseudocode should be
  written or shared in these chats.

  N/A

  By submitting this code, you are agreeing that you have solved in accordance
  with the collaboration policy in CMPUT 403.
*/
#include <iostream>
#include <complex>
#include <cmath>
#include <vector>
#include <utility>
#include <iomanip>
using namespace std;
typedef complex<double> Point;
#define EPS 1e-8
int isect_iline(Point a, Point b, Point c, Point d, Point *p)
{
  double r, denom, num1, x, y;
  num1  = (a.imag() - c.imag()) * (d.real() - c.real()) - (a.real() - c.real()) * (d.imag() - c.imag());
  denom = (b.real() - a.real()) * (d.imag() - c.imag()) - (b.imag() - a.imag()) * (d.real() - c.real());
  if (fabs(denom)>=EPS)
  {
    r = num1 / denom;
    x = a.real() + r*(b.real() - a.real());
    y = a.imag() + r*(b.imag() - a.imag());
    *p=Point(x,y);
    return 1;
  } 
  if (fabs(num1) >= EPS) return 0;
  return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    bool found=false;
    double maxperi=0;
    cin>>n;
    vector<pair<Point,Point>> lines;   
    for(int c=0;c<n;c++)
    {
        double x1, x2, y1, y2;
        cin>>x1>>y1>>x2>>y2;
        lines.push_back(make_pair(Point(x1,y1),Point(x2,y2)));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                Point p1, p2, p3;
                int check;
                double peri;
                check=isect_iline(lines[i].first, lines[i].second, lines[j].first, lines[j].second, &p1);
                if(check!=1)
                {
                    continue;
                }
                check=isect_iline(lines[j].first, lines[j].second, lines[k].first, lines[k].second, &p2);
                if(check!=1)
                {
                    continue;
                }
                check=isect_iline(lines[i].first, lines[i].second, lines[k].first, lines[k].second, &p3);
                if(check!=1)
                {
                    continue;
                }
                if(abs(p1-p2)>EPS and abs(p2-p3)>EPS and abs(p1-p3)>EPS)
                {
                    found=true;
                    peri=abs(p1-p2)+abs(p2-p3)+abs(p1-p3);
                    maxperi=max(maxperi,peri);
                }
            }
        }
    }
    if(found)
    {
        cout<<fixed;
        cout<<setprecision(10);
        cout<<maxperi;
    }
    else
    {
        cout<<"no triangle";
    }
    return 0;
}

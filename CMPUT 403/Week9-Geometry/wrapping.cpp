/*
  Problem: https://open.kattis.com/problems/wrapping
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!
  
  Lecture Video
  https://github.com/UAPSPC/Code-Archive/blob/master/2d_geometry/convex_hull.cpp
  https://github.com/UAPSPC/Code-Archive/blob/master/2d_geometry/area_poly.cpp
  https://github.com/UAPSPC/Code-Archive/blob/master/2d_geometry/rotate_2d.c

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
#include <complex>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
#define EPS 1e-8
typedef complex<double> Point;
Point rotate_2d(Point p, Point o, double theta)
{
  double m[2][2];
  Point r;
  m[0][0] = m[1][1] = cos(theta);
  m[0][1] = -sin(theta);
  m[1][0] = -m[0][1];
  p=Point(p.real()-o.real(),p.imag()-o.imag());
  r=Point(m[0][0]*p.real()+m[0][1]*p.imag()+o.real(),m[1][0]*p.real()+m[1][1]*p.imag()+o.imag());
  if(fabs(r.real()) < EPS)
  {
      r=Point(0,r.imag());
  }
  if(fabs(r.imag()) < EPS)
  {
      r=Point(r.real(),0);
  }
  return r;
}
bool operator<(const Point & p1, const Point &p2)
{
    return p1.imag() < p2.imag() || 
            (fabs(p1.imag() - p2.imag()) < EPS && p1.real() < p2.real());
}

double cross(const Point &a, const Point &b) {
    return imag(conj(a)*b);
}


Point P0;

enum Direction {CCW, CW, CL};

Direction cross_prod_dir(const Point &p1, const Point &p2, const Point &p0)
{
    double res = cross(p1 - p0, p2 - p0);

    if (fabs(res) < EPS)
        return CL;
    else if (res > 0.0)
        return CW;
    else
        return CCW;
}


bool polar_cmp(Point p1, Point p2)
{
    Direction res = cross_prod_dir(p1, p2, P0);

    if (res == CW)
        return true;
    else if (res == CCW)
        return false;
    else {
        double d = norm(p1 - P0) - norm(p2 - P0);

        if (fabs(d) < EPS)
            return false;
        else if (d < 0.0)
            return true;
        else
            return false;
    }
}

vector<Point> convex_hull(vector<Point> &poly)
{
    if (poly.size() <= 1)
        return poly;

    vector<Point> hull;

    int min = 0;
    P0 = poly[0];

    // Find point that has lowest y, and then has lowest x
    for (int i = 1; i < poly.size(); i++) {
        if (poly[i].imag() < P0.imag() || (fabs(poly[i].imag() - P0.imag()) < EPS && (poly[i].real() < P0.real()))) {
          min = i;
          P0 = poly[i];
        }
    }

    // Put P0 into start of poly
    poly[min] = poly[0];
    poly[0] = P0;
    hull.push_back(P0);

    sort(poly.begin() + 1, poly.end(), polar_cmp);
  
    // Find first distinct element from P0
    int i;
    for (i = 1; i < poly.size(); i++) {
        if (norm(poly[i] - P0) > EPS)
          break;
    }

    if (i == poly.size())
        return hull;

    hull.reserve(poly.size());
    hull.push_back(poly[i++]);

    for ( ; i < poly.size(); i++) {
        while (hull.size() > 1 && cross_prod_dir(poly[i], *(hull.end() - 1), *(hull.end() - 2)) != CCW)
            hull.pop_back();

        hull.push_back(poly[i]);
    }

    return hull;
}
double area_poly(const vector<Point> &p){
    double sum = 0;

    for(int i = p.size()-1, j = 0; j < p.size(); i = j++)
        sum += cross(p[i], p[j]);

    return sum/2.0;
}
void process()
{
    int n;
    vector<Point> polygon, hull;
    double barea=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        double x, y, w, h, v;
        Point a, b, c, d;
        cin>>x>>y>>w>>h>>v;
        barea+=w*h;
        v=-v*M_PI/180;
        a=rotate_2d(Point(x+(w/2),y+(h/2)),Point(x,y),v);
        b=rotate_2d(Point(x+(w/2),y-(h/2)),Point(x,y),v);
        c=rotate_2d(Point(x-(w/2),y+(h/2)),Point(x,y),v);
        d=rotate_2d(Point(x-(w/2),y-(h/2)),Point(x,y),v);
        polygon.push_back(a);
        polygon.push_back(b);
        polygon.push_back(c);
        polygon.push_back(d);
    }
    hull = convex_hull(polygon);
    cout<<fixed;
    cout<<setprecision(1);
    cout<<barea/area_poly(hull)*100<<" %\n";
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

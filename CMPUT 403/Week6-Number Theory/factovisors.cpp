/*
  Problem: https://open.kattis.com/problems/factovisors
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!
  
  Lecture slides:
  https://eclass.srv.ualberta.ca/mod/resource/view.php?id=4785518
  Exponent of prime in factorial:
  https://en.wikipedia.org/wiki/Legendre%27s_formula

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
#include <vector>
using namespace std;
int getexp(int n, int p)
{
    int count = 0;
    for(long long pi=p;pi<=n;pi*=p)
        count+=n/pi;
    return count;
}
vector<int> getprimes()
{
    vector<int> primes(46350), listprimes;
    for(int i=2;i<46350;i++)
        primes[i]=i;
    for(int p=2;p<46350;p++)
    {
        if(primes[p]==p)
        {
            listprimes.push_back(p);
            for(long long int q=2*p;q<46350;q+=p)
                primes[q]=p;
        }
    }
    return listprimes;
}
map<int,int> factorize(int m, vector<int> &primes)
{
    map<int,int> factors;
    for(int i=0;i<primes.size();i++)
    {
        if(primes[i]>m)
            break;
        while(m%primes[i]==0)
        {
            factors[primes[i]]++;
            m/=primes[i];
        }
    }
    if(m>1)
        factors[m]++;
    return factors;
}
void process(int n, int m, vector<int> &primes)
{
    map<int,int> factors=factorize(m,primes);
    bool divides=true;
    for(auto&x:factors)
    {
        if(getexp(n,x.first)<x.second)
        {
            divides=false;
            break;
        }
    }
    if(divides)
    {
        cout<<m<<" divides "<<n<<"!\n";
    }
    else
    {
        cout<<m<<" does not divide "<<n<<"!\n";
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> primes=getprimes();
    int n, m;
    while(cin>>n)
    {
        cin>>m;
        if(n==0)
        {
            if(m!=1)
            {
                cout<<m<<" does not divide "<<n<<"!\n";
            }
            else
            {
                cout<<m<<" divides "<<n<<"!\n";
            }
        }
        else if(m==0)
        {
            cout<<m<<" does not divide "<<n<<"!\n";
        }
        else if(m==n or m==1)
        {
            cout<<m<<" divides "<<n<<"!\n";
        }
        else if(m<=n)
        {
            cout<<m<<" divides "<<n<<"!\n";
        }
        else
        {
            process(n,m,primes);
        }
    }
    return 0;
}

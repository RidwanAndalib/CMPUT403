/*
  Ridwan Andalib
  1597362

  List any resources you used below (eg. urls, name of the algorithm from our code archive).
  Remember, you are permitted to get help with general concepts about algorithms
  and problem solving, but you are not permitted to hunt down solutions to
  these particular problems!

  http://www.cplusplus.com/reference/string/stoi/
  http://www.cplusplus.com/reference/string/string/compare/
  http://www.cplusplus.com/reference/cmath/round/

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
#include <math.h>
using namespace std;
int main()
{
    string x;
    double f, p, su, st, a, fc, pc, suc, stc, ac, flag, tc, tp;
    char uf, up, usu, ust, ua;
    fc=0;
    pc=0;
    suc=0;
    stc=0;
    ac=0;
    tc=0;
    tp=0;
    flag=1;
    while(1)
    {
        cin>>x;
        if(x.compare("-")==0)
        {
            if(flag)
                return 0;
            else
            {
                cout<<round((fc/(fc+pc+suc+stc+ac))*100)<<"%\n";
                flag=1;
                fc=0;
                pc=0;
                suc=0;
                stc=0;
                ac=0;
                continue;
            }
        }
        flag=0;
        uf=x[x.length()-1];
        f=stoi(x);
        cin>>p>>up>>su>>usu>>st>>ust>>a>>ua;
        if(uf=='g')
        {
            uf='C';
            f*=9;
        }
        if(up=='g')
        {
            up='C';
            p*=4;
        }
        if(usu=='g')
        {
            usu='C';
            su*=4;
        }
        if(ust=='g')
        {
            ust='C';
            st*=4;
        }
        if(ua=='g')
        {
            ua='C';
            a*=7;
        }
        if(uf=='%')
            tp+=f;
        else
            tc+=f;
        if(up=='%')
            tp+=p;
        else
            tc+=p;
        if(usu=='%')
            tp+=su;
        else
            tc+=su;
        if(ust=='%')
            tp+=st;
        else
            tc+=st;
        if(ua=='%')
            tp+=a;
        else
            tc+=a;
        tc/=(100-tp);    
        if(uf=='%')
            f*=tc;
        if(up=='%')
            p*=tc;
        if(usu=='%')
            su*=tc;
        if(ust=='%')
            st*=tc;
        if(ua=='%')
            a*=tc;
        tc=0;
        tp=0;
        fc+=f;
        pc+=p;
        suc+=su;
        stc+=st;
        ac+=a;
    }
    return 0;
}
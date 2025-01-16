#include<bits/stdc++.h>
using namespace std;
#define e 0.001

double fun(double x)
{
    return x*x*x-x-1;
}




double false_pos(double a, double b)
{

    if(fun(a)*fun(b)>=0)
    {
        cout<<"Incorrect value"<<endl;
        return 0.0;
    }
    double c = a;
    int it = 0;

    while(fabs(fun(c)) > e)//stopping for relative a-b/a //for
    {
        c = (a*fun(b)-b*fun(a))/(fun(b)-fun(a));//for future ref change here.......

        if(fun(c)==0)break;
        else if(fun(a)*fun(c)<0)b=c;

        else a=c;

        it++;
        cout<<"Change of a and b: "<<a<<"   "<<b<<"     "<<b-a<<endl;
        cout<<it<<" iteration assumption root "<<c<<endl;
        cout<<endl;




    }


    return c;



}

int main()
{
    double a,b,c;
    cin>>a>>b;
    c=false_pos(a,b);
    cout<<"final Root "<<c<<endl;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define e 0.01

double fun(double x)
{
    return x*x*x-x-1;
}




double bisc(double a, double b)
{

    if(fun(a)*fun(b)>=0)
    {
        cout<<"Incorrect value"<<endl;
        return 0.0;
    }
    double c = a;
    int it = 0;

    while(fabs((b-a)/a) > e)//stopping for relative a-b/a //for
    {
        c = (a+b)/2;

        if(fun(c)==0)break;
        else if(fun(a)*fun(c)<0)b=c;

        else a=c;

        it++;
        cout<<"Change of a and b: "<<a<<"   "<<b<<"     "<<b-a<<endl;
        cout<<it<<" iteration assumption root"<<" "<<c<<endl;
        cout<<endl;




    }


    return c;



}

int main()
{
    double a,b,c;
    cin>>a>>b;
    c=bisc(a,b);
    cout<<"final Root "<<c<<endl;
    return 0;
}

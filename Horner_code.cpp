#include<bits/stdc++.h>
using namespace std;
#define e 0.01

double c;

double fun(double x)
{
    return x*x*x-4*x*x+x+6;
}

double dif_fun(double x){
    return 3*x*x-8*x+1;
}



double horner()
{
    cout<<"First enter degree then  Enter the coefficient "<<endl;
    int n;
    cin>>n;
    double a[n] , p[n];

    for(int i=n;i>=0;i--)
    {
        cin>>a[i];
    }

    p[n]=a[n];
    for(int i=n-1;i>0;i--)
    {
        p[i]=p[i+1]*c+a[i];
    }
    cout<<p[0]<<endl;
    return p[0];

}

double newton(double a)
{

    double c = a;
    int it = 0;

    while(fabs(fun(c)) > e)//stopping for relative a-b/a //for
    {
        c = c - (fun(c)/dif_fun(c));


        it++;
        cout<<it<<" iteration assumption root"<<c<<endl;




    }


    return c;



}

int main()
{
    double a,h;
    cin>>a;
    c=newton(a);
    cout<<"final Root "<<c<<endl;
    h = horner();
    return 0;
}


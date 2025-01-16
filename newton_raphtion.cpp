///this program is using user input

#include<bits/stdc++.h>
using namespace std;
#define para cout<<endl
#define e 0.01

vector<double>coV ;

//x^3-4x^2+x+6 roots {3,-1,2}
 /*

 for input
3
1
-4
1
6

 */

double fun(double x)
{
    double res=0;
    double degree = coV.size()-1;

    for(int i=0;i<=coV.size();i++)
    {
       res += (coV[i]*pow(x,degree));
       degree--;
    }
    return res;

}

double diff_fun(double x)
{
    double dres=0;
    double degree = coV.size()-1;

    for(int i=0;i<=coV.size()-1;i++)
    {
       dres += (degree*coV[i]*pow(x,degree-1));//diff er function
       degree--;
    }
    return dres;

}


double newton(double a)
{

    double c = a;
    int it = 0;

    while(fabs(fun(c)) > e)//stopping for relative a-b/a //for
    {
        c = c - (fun(c)/diff_fun(c));


        it++;
        cout<<it<<" iteration assumption root"<<c<<endl;




    }


    return c;

}


int main()
{
    int degree;
    cout<<"Enter The highest number of Degree:"<<endl;
    cin>>degree;
    para;


    for(int i = degree;i>=0;i--){
        double co;
        cout<<"Enter x^"<<i<<" coefficient:"<<endl;
        cin>>co;

        coV.push_back(co);
    }
    para;

//    cout<<"The Poly function is..";
//    para;
//    for(int i=0;i<=degree;i++)
//    {
//      cout<<coV[i]<<endl;
//    }

    para;
    cout<<"Enter estimate value ";
    double scr;
    cin>>scr;
//    double test1 = fun(scr);//2*4+3*2-1=13
//    para;
//    cout<<test1<<endl;
//    para;
//    double test2 = diff_fun(scr);//2*4+3=11
//    para;
//    cout<<test2<<endl;

    para;
    double root = newton(scr);
    cout<<root<<endl;




    return 0;
}


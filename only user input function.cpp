#include<bits/stdc++.h>
using namespace std;
#define para cout<<endl

 vector<double>coV ;

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
    double test1 = fun(scr);//2*4+3*2-1=13
    para;
    cout<<test1<<endl;
    para;
    double test2 = diff_fun(scr);//2*4+3=11
    para;
    cout<<test2<<endl;




    return 0;
}


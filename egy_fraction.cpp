#include <bits/stdc++.h>
using namespace std;

int fraction[100]={0};

float value(int nr ,int dr){
    /*if (dr == 0 || nr == 0)
        return;
 
    // If numerator divides denominator, then simple division
    // makes the fraction in 1/n form
    if (dr%nr == 0)
    {
        //cout << "1/" << dr/nr;
        return 1.0/(float(dr)/float(nr);)
    }
 
    // If denominator divides numerator, then the given number
    // is not fraction
    if (nr%dr == 0)
    {
        cout << nr/dr;
        return;
    }
*/
    return float(nr)/float(dr); 
}
int sub_fraction(int n1,int n2,int d1,int d2){
    float n=(float(n1*d2)-float(n2*d1))/float(d1*d2);
    if(n>=0)
        return 1;
    else 
        return 0;
}
void return_value(int nr,int dr){
    int num=1;
    float x,val;
  
    val=value(nr,dr);
      while(val>0){
        x=value(1,num);

        //cout<<x<<" "<<val<<endl;
        if(sub_fraction(nr,dr,1,num)){
            nr=(nr*num)-(1*dr);
            dr=dr*num;
            //cout<<x<<" "<<val<<endl;
            val=value(nr,dr);

            cout<<"1/"<<num<<"+"; 
            //cout<<x<<" "<<val<<" "<<nr<<" "<<dr<<endl;
        }
        num=num+1;
    }
}


int main()
{   int nr=12,dr=13;
     //cout<<value(nr,dr);
    return_value(nr,dr);
    
 
    return 0;
}
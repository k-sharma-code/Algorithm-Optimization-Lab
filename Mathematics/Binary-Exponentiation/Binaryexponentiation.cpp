#include<iostream>
using namespace std;
double power(double base,int pow){
  if(pow==0) return 1.0;
  if(base==0) return 0.0;
  if(base==1) return 1.0;
  if(base==-1 && pow%2==0) return 1.0;
  if(base==-1 && pow%2!=0) return -1.0;
long binform = pow;
if(binform < 0){
  base = 1/base;
  binform = -binform;
}
double ans=1;
while(binform > 0){
  if(binform % 2==1){
    ans *= base;
  }
  base *= base;
  binform /=2;
}
return ans;
}
int main(){
  double a;
  cout<<"enter base = ";
  cin>>a;
  int b;
  cout<<"enter power = ";
  cin>>b;
  cout<<"The power of "<<a<<"^"<<b<<" = "<<power(a,b)<<endl;
  return 0;
}

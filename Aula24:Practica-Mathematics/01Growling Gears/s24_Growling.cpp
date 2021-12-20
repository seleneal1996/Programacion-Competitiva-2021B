//https://open.kattis.com/problems/growlinggears
#include <bits/stdc++.h>
void Calculate(){
  int n_gears;
  std::cin>>n_gears;
  int mx_gear=0;
  double mxRPM=0,mxTorque=-1;
  for (int gear = 1; gear <= n_gears; gear++)
  {
    double a,b,c;
    std::cin>>a>>b>>c;
    int rpm = b / (2 * a);
    int torque = -a*rpm*rpm + b*rpm + c;
    if (torque > mxTorque+1e-6){
	    mx_gear = gear;
	    mxRPM = rpm;
	    mxTorque = torque;
    }
  }
  int rounded_max_rpm = mxRPM+ .5;
  std::cout<<mx_gear<<std::endl;
}
int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n;
  while(n--){
    Calculate();
  }
  return 0;
}

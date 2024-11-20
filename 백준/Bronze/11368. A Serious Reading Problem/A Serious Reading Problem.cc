#include <bits/stdc++.h>
using namespace std;

int Power(int val, int p)
{
   int res = 1;
   int multiply = val;

   while(p > 0)
   {
      if(p & 1) res *= multiply;

      p >>= 1;
      multiply *= multiply;
   }  
   return res;
}

int main()
{
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int c, w, l, p;
   
   while(cin>>c>>w>>l>>p)
   {
      if(c == 0 && w == 0 && l == 0 && p == 0) break;

      int power = w * l * p;
      cout<<Power(c, power)<<"\n";
   }
}
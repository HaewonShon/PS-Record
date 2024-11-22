#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int n;
   cin>>n;

   if(n <= 3) 
   {
      cout<<"-1";
      return 0;
   }

   if(n % 2 == 0)
   {
      cout<<n-1<<"\n"<<n<<"\n";

      for(int i = 0; i < n-2; ++i)
      {
         cout<<i+1<<"\n";
      }
   }
   else
   {
      for(int i = 0; i < n-3; ++i)
      {
         cout<<i+2<<"\n";
      }
      cout<<"1\n"<<n<<"\n"<<n-1;
   }
   
}
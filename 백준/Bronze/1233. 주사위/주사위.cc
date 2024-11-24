#include <bits/stdc++.h>
using namespace std;

int frequency[20+20+40+1];

int main()
{
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   memset(frequency, 0, sizeof(frequency));

   int s1, s2, s3;
   cin>>s1>>s2>>s3;

   int s1Val = s1;
   while(s1Val > 0)
   {
      int s2Val = s2;
      while(s2Val > 0)
      {
         int s3Val = s3;
         while(s3Val > 0)
         {
            ++frequency[s1Val+s2Val+s3Val];
            --s3Val;
         }
         --s2Val;
      }
      --s1Val;
   }

   int ans = 0;
   for(int i = 1; i <= s1+s2+s3; ++i)
   {
      if(frequency[i] > frequency[ans]) ans = i;
   }

   cout<<ans;
}
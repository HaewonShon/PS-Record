#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int n;
   cin>>n;

   vector<pair<int, pair<int, int>>> shoes(n);
   for(int i = 0; i < n; ++i)
   {
      shoes[i].first = i;
      cin>>shoes[i].second.first>>shoes[i].second.second;
   }

   sort(shoes.begin(), shoes.end(), [](auto& p1, auto& p2){
      int p1Top = p1.second.first * p2.second.second;
      int p2Top = p2.second.first * p1.second.second;

      if(p1Top == p2Top)
      {
         return p1.first < p2.first;
      }
      return p1Top < p2Top;
   });

   for(int i = 0; i < n; ++i)
   {
      cout<<shoes[i].first+1<<" ";
   }
}
#include <bits/stdc++.h>
using namespace std;

int Search(const vector<vector<int>>& field, const int n, const int m,
   const vector<pair<int, int>>& component, const int x, const int y)
{
   int res = INT_MAX;

   for(int i = 0; i + y - 1 < n; ++i)
   {
      for(int j = 0; j + x - 1 < m; ++j)
      {
         int partialRes = 0;
         for(auto p : component)
         {
            partialRes += field[i+p.first][j+p.second];
         }
         res = min(res, partialRes);
      }
   }
   return res;
}

int main()
{
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int n, m;
   cin>>n>>m;

   int a, b, c;
   cin>>a>>b>>c;

   vector<vector<int>> field(n, vector<int>(m));
   for(int i = 0; i < n; ++i)
   {
      for(int j = 0; j < m; ++j)
      {
         cin>>field[i][j];
      }
   }

   int ans = INT_MAX;
   
   vector<pair<int, int>> caseComponents;

   // case 1
   for(int i = 0; i < a; ++i)
   {
      for(int j = 0; j < b + c; ++j)
      {
         caseComponents.push_back({i, j});
      }
   }
   ans = min(ans, Search(field, n, m, caseComponents, b+c, a));
   caseComponents.clear();

   // case 2
   for(int i = 0; i < a; ++i)
   {
      for(int j = 0; j < c; ++j)
      {
         caseComponents.push_back({i, j});
      }
   }

   for(int i = 0; i < b; ++i)
   {
      for(int j = 0; j < a; ++j)
      {
         caseComponents.push_back({a + i, c + j});
      }
   }
   ans = min(ans, Search(field, n, m, caseComponents, c+a, a+b));
   caseComponents.clear();

   // case 3
   for(int i = 0; i < a; ++i)
   {
      for(int j = 0; j < b; ++j)
      {
         caseComponents.push_back({i, j});
      }
   }
   for(int i = 0; i < c; ++i)
   {
      for(int j = 0; j < a; ++j)
      {
         caseComponents.push_back({a + i, b + j});
      }
   }
   ans = min(ans, Search(field, n, m, caseComponents, b+a, a+c));

   cout<<ans;
   
}
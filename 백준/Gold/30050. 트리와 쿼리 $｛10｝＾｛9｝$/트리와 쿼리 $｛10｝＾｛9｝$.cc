#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int q;
    cin>>q;

    unordered_map<int, int> parentMap;

    while(q--)
    {
        int cmd, a, b;
        cin>>cmd>>a>>b;

        if(cmd == 1)
        {
            parentMap[b] = a;
        }   
        else
        {            
            stack<int> aParents;
            stack<int> bParents;
            
            while(a != 1)
            {
                aParents.push(a);
                if(parentMap.find(a) == parentMap.end()) // 쿼리로 인해 부모가 바뀌지 않은 경우
                {
                    a /= 2;
                }
                else
                {
                    a = parentMap[a];
                }
            }

            while(b != 1)
            {
                bParents.push(b);
                if(parentMap.find(b) == parentMap.end()) // 쿼리로 인해 부모가 바뀌지 않은 경우
                {
                    b /= 2;
                }
                else
                {
                    b = parentMap[b];
                }
            }

            int commonParent = 1;
            while(!aParents.empty() && !bParents.empty() && aParents.top() == bParents.top())
            {
                commonParent = aParents.top();
                aParents.pop();
                bParents.pop();
            }

            long long res = commonParent;
            while(!aParents.empty())
            {
                res += aParents.top();
                aParents.pop();
            }
            while(!bParents.empty())
            {
                res += bParents.top();
                bParents.pop();
            }
            cout<<res<<"\n";
        } 
    }
}
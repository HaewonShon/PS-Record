#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int q, k;
        cin>>q>>k;

        priority_queue<int> vals; // -val을 저장함. 작은 순으로 정렬하기 위한 꼼수
        int printResult = 0;

        for(int i = 0; i < q; ++i)
        {
            string cmd;
            cin>>cmd;

            if(cmd == "insert")
            {
                int val;
                cin>>val;

                if(vals.size() == k) // 이미 k개 채워짐-> 바꿔야 하는가?
                {
                    int minVal = -vals.top();
                    if(minVal < val)
                    {
                        printResult ^= minVal;
                        vals.pop();
                        vals.push(-val);
                        printResult ^= val;
                    }
                }
                else
                {
                    vals.push(-val);
                    printResult ^= val;
                }
            }
            else if(cmd == "print")
            {
                cout<<printResult<<"\n";
            }
        }
    }
}
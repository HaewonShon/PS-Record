#include <bits/stdc++.h>
using namespace std;

int GetValidSlot(vector<int>& slots, int index)
{
    if(index == -1 || slots[index] == -1) return -1;
    if(slots[index] == index) return index;
    slots[index] = GetValidSlot(slots, slots[index]);
    return slots[index];
}

void Print(vector<int>& slots)
{
    cout<<"Print\n";
    for(int i = 0; i < slots.size(); ++i)
    {
        cout<<i<<" "<<slots[i]<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, p;
    cin>>n>>p;

    vector<int> emptySlots(n);
    for(int i = 0; i < n; ++i) emptySlots[i] = i;

    for(int i = 0; i < p; ++i)
    {
        int g;
        cin>>g; 
        --g;

        int index = GetValidSlot(emptySlots, g);
        if(index != -1)
        {
            if(index == 0)
            {
                emptySlots[index] = -1;
            }
            else
            {
                emptySlots[index] = GetValidSlot(emptySlots, index-1);
                emptySlots[g] = emptySlots[index];
                //cout<<g<<": "<<emptySlots[g]<<"\n";
            }
        }
        else
        {
            cout<<i;
            return 0;
        }
    }
    cout<<n;
}
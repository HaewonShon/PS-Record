#include <bits/stdc++.h>
using namespace std;

bool DFS(const string& s, int index)
{
    if(index == s.length())
    {
        return true;
    }

    // 01
    if(index < s.length() - 1
        && (s[index] == '0' && s[index+1] == '1'))
    {
        if(DFS(s, index+2)) return true;
    }

    // 100~1~
    if(index < s.length() - 3
        && (s[index] == '1' && s[index+1] == '0' && s[index+2] == '0'))
    {
        int i = index+3;
        while(i < s.length() && s[i] == '0') ++i; // 뒤따라 붙는 0
        
        if(i == s.length()) return false; // 뒤에 오는 1이 없음 -> 중단
        
        while(i < s.length() && s[i] == '1') // 뒤따라 오는 1
        {   
            ++i;
            if(DFS(s, i)) return true;
        } 
    }

    return false;   
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    string s;
    cin>>s;

    if(DFS(s, 0))
    {
        cout<<"SUBMARINE";
    }
    else
    {
        cout<<"NOISE";
    }
}
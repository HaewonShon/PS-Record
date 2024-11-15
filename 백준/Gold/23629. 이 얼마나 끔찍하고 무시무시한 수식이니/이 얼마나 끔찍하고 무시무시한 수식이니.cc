#include <bits/stdc++.h>
using namespace std;

string numbers[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int numberLength[10] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4};

int Parse(const string& s, int& index)
{
    for(int i = 0; i < 10; ++i)
    {
        if(s[index] == numbers[i][0] && s.substr(index, numberLength[i]) == numbers[i])
        {
            index += numberLength[i];
            return i;
        }
    }
    return -1;
}


int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    string s;
    cin>>s;
    int n = s.length();

    int index = 0;
    deque<char> q;
    while(index < n)
    {
        if(s[index] < 'A' || s[index] > 'Z') // operators
        {
            if(q.back() < '0' || q.back() > '9') // double operator
            {
                cout<<"Madness!";
                return 0;
            }

            q.push_back(s[index]);
            ++index;
        }
        else
        {
            int parseRes = Parse(s, index);
            if(parseRes == -1)
            {
                cout<<"Madness!";
                return 0;
            }
            else
            {
                q.push_back('0' + parseRes);
            }
        }
    }

    long long res = 0;
    int recentVal = 0;
    char recentOp = '+';

    while(!q.empty())
    {
        char c = q.front();
        q.pop_front();

        cout<<c;

        if(c >= '0' && c <= '9')
        {
            recentVal *= 10;
            recentVal += (c - '0');
        }
        else
        {
            switch(recentOp)
            {
                case '+': // add
                res += recentVal;
                break;
                case '-': // subtract
                res -= recentVal;
                break;
                case 'x': // multiply
                res *= recentVal;
                break;
                case '/': // divide
                res /= recentVal;
                break;
            }

            recentVal = 0;
            recentOp = c;
        }
    }
    cout<<"\n";
    
    string ansString = to_string(res);
    for(char c : ansString)
    {
        switch(c)
        {
            case '-': cout<<"-"; break;
            case '0': cout<<"ZERO"; break;
            case '1': cout<<"ONE"; break;
            case '2': cout<<"TWO"; break;
            case '3': cout<<"THREE"; break;
            case '4': cout<<"FOUR"; break;
            case '5': cout<<"FIVE"; break;
            case '6': cout<<"SIX"; break;
            case '7': cout<<"SEVEN"; break;
            case '8': cout<<"EIGHT"; break;
            case '9': cout<<"NINE"; break;
        }
    }
}
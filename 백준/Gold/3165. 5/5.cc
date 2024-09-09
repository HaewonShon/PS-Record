#include <bits/stdc++.h>
using namespace std;

void Add1(string& s, int index)
{
    s[index] += 1;
    
    while(index > 0)
    {
        if(s[index] > '9')
        {
            s[index] = '0';
            s[index-1] += 1;
            --index;
        }
        else
        {
            break;
        }
    }
    if(s.front() > '9')
    {
        s.front() = '0';
        s = '1' + s;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    string s;
    int k;
    cin>>s>>k;

    // 가능한 최솟값 = n+1
    Add1(s, s.length()-1);
    
    int count = 0;
    for(char c : s)
    {
        if(c == '5') ++count;
    }

    if(count >= k)
    {
        cout<<s;
        return 0;
    }

    // 만약 제일 작은 수가 충족하지 않는다면 - 뒷자리부터 5로 바꿔나가기
    int index = s.length() - 1;
    while(count < k && index > 0)
    {
        int currentVal = s[index];
        if(currentVal < '5')
        {
            s[index] = '5';
            ++count;
        }
        else if(currentVal > '5')
        {
            s[index] = '9';
            Add1(s, index);
            if(s.front() > '9')
            {
                s = '1' + s;
            }

            // 자릿수 올림 후 5의 갯수 갱신
            count = 0;
            for(char c : s)
            {
                if(c == '5') ++count;
            }

            if(count < k)
            {
                s[index] = '5';
                ++count;
            }
        }
        --index;
    }

    // 제일 앞자리
    if(count < k)
    {
        // 앞을 5로 바꾸고 모자란 자릿수를 앞에 더 붙인다
        if(s[0] < '5')
        {
            s[0] = '5';
            ++count;

            s = string(k - count, '5') + s;
        }
        // 앞에 모자란 자릿수를 더 붙인다
        else if(s[0] == '5')
        {
            s = string(k - count, '5') + s;
        }
        // 한개만 필요할 경우- 15~~~ 꼴, 아닐시 앞자리를 그냥 5로 만들고 진행
        else // > '9'
        {
            if(k - count == 1)
            {
                s[0] = '5';
                s = '1' + s;
            }
            else
            {
                s[0] = '5';
                ++count;

                s = string(k - count, '5') + s;
            }
        }
    }

    cout<<s;

}

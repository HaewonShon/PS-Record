#include <bits/stdc++.h>
using namespace std;

unsigned long long Pow(int val, int times)
{
    if(times < 0) return 0;

    unsigned long long res = 1;
    while(times-- > 0)
    {
        res *= val;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    string val;
    cin>>val;

        //자릿수가 현재 수보다 작은 경우-> 모든 경우 가능
        unsigned long long res = 0;
        int len = val.length();
        int half = len / 2 + (len % 2);

        // n 이하 중 가능한 가장 큰 회문수 구하기
        string palindromeVal = val;
        for(int i = 0; i < half; ++i)
        {
            palindromeVal[len-1-i] = val[i]; // 앞 절반으로 만든 최대 palindrome 값
        }

        if(palindromeVal > val) // 앞자리로 만든 최대값이 현재보다 큼
        {
            --palindromeVal[half-1];
            fill(palindromeVal.begin() + half, palindromeVal.end(), '9');

            for(int i = half-1; i > 0; --i)
            {
                if(palindromeVal[i] < '0')
                {
                    --palindromeVal[i-1];
                    palindromeVal[i] = '9';
                }
            }

            if(palindromeVal[0] == '0')
            {
                palindromeVal = palindromeVal.substr(1);
                --len;
                half = len / 2 + (len % 2);
            }

            for(int i = 0; i < half; ++i)
            {
                palindromeVal[len-1-i] = palindromeVal[i]; // 앞 절반으로 만든 최대 palindrome 값
            }
        }
        
        for(int i = 1; i < len; ++i) // 자릿수가 len 미만일 떄->모든 경우가 가능
        {
            int halfLen = (i/2 + i%2);
            res += 9 * Pow(10, halfLen-1);
        }


        // 길이가 palindromeVal과 같으면서 이보다 작은 모든 palindrome 수 구하기 -> 바깥에서부터 고정시켜가는 컨셉
        // 첫자리수 : 1~palindromeVal[0]
        if(len > 2)
            res += (palindromeVal[0] - '1') * Pow(10, (len-2)/2 + (len-2)%2);

        // 중간자리수 : 0~palindromeVal[i]
        for(int i = 1; i < half-1; ++i)
        {
            res += (palindromeVal[i] - '0') * Pow(10, (len-2-2*i)/2 + (len-2-2*i)%2);
        }

        // 가운뎃자리수 : 0~palindromeVal[half-1]
        res += (palindromeVal[half-1] - ((half-1 == 0) ? '1' : '0') + 1); // 11 22 중복체크
        cout<<res; //<<" "<<palindromeVal<<"\n";

}
#include <bits/stdc++.h>
using namespace std;

void Rotate(char target[3][3], bool isClockwise)
{
    char temp;

    if(isClockwise)
    {
        temp = target[0][0];
        target[0][0] = target[2][0];
        target[2][0] = target[2][2];
        target[2][2] = target[0][2];
        target[0][2] = temp;

        temp = target[0][1];
        target[0][1] = target[1][0];
        target[1][0] = target[2][1];
        target[2][1] = target[1][2];
        target[1][2] = temp;
    }
    else
    {
        temp = target[0][0];
        target[0][0] = target[0][2];
        target[0][2] = target[2][2];
        target[2][2] = target[2][0];
        target[2][0] = temp;

        temp = target[0][1];
        target[0][1] = target[1][2];
        target[1][2] = target[2][1];
        target[2][1] = target[1][0];
        target[1][0] = temp;
    }
}

void RotateNeighbors(vector<char*> v)
{
    char temp[3] = {*v[0], *v[1], *v[2]};

    for(int i = 0; i < 9; ++i)
    {
        *v[i] = *v[i+3];
    }
    *v[9] = temp[0];
    *v[10] = temp[1];
    *v[11] = temp[2];
}

int main()
{ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        char up[3][3], down[3][3], front[3][3], back[3][3], left[3][3], right[3][3];
        memset(up, 'w', sizeof(up));
        memset(down, 'y', sizeof(down));
        memset(front, 'r', sizeof(front));
        memset(back, 'o', sizeof(back));
        memset(left, 'g', sizeof(left));
        memset(right, 'b', sizeof(right));

        while(n--)
        {
            string cmd;
            cin>>cmd;

            bool isClockwise = cmd[1] == '+' ? true : false;

            switch(cmd[0])
            {
                case 'L':
                Rotate(left, isClockwise);
                if(isClockwise) RotateNeighbors({&up[2][0], &up[1][0], &up[0][0],
                                                &back[0][2], &back[1][2], &back[2][2],
                                                &down[2][0], &down[1][0], &down[0][0],
                                                &front[2][0], &front[1][0], &front[0][0]});
                else RotateNeighbors({&up[0][0], &up[1][0], &up[2][0],
                                        &front[0][0], &front[1][0], &front[2][0],
                                        &down[0][0], &down[1][0], &down[2][0],
                                        &back[2][2], &back[1][2], &back[0][2]});
                break;
                case 'R':
                Rotate(right, isClockwise);
                if(isClockwise) RotateNeighbors({&up[0][2], &up[1][2], &up[2][2],
                                                &front[0][2], &front[1][2], &front[2][2],
                                                &down[0][2], &down[1][2], &down[2][2],
                                                &back[2][0], &back[1][0], &back[0][0]});
                else RotateNeighbors({&up[2][2], &up[1][2], &up[0][2],
                                        &back[0][0], &back[1][0], &back[2][0],
                                        &down[2][2], &down[1][2], &down[0][2],
                                        &front[2][2], &front[1][2], &front[0][2]});
                break;
                case 'U':
                Rotate(up, isClockwise);
                if(isClockwise) RotateNeighbors({&back[0][0], &back[0][1], &back[0][2],
                                                &left[0][0], &left[0][1], &left[0][2],
                                                &front[0][0], &front[0][1], &front[0][2],
                                                &right[0][0], &right[0][1], &right[0][2]});
                else RotateNeighbors({&back[0][2], &back[0][1], &back[0][0],
                                        &right[0][2], &right[0][1], &right[0][0],
                                        &front[0][2], &front[0][1], &front[0][0],
                                        &left[0][2], &left[0][1], &left[0][0]});
                break;
                case 'D':
                Rotate(down, isClockwise);
                if(isClockwise) RotateNeighbors({&front[2][2], &front[2][1], &front[2][0],
                                                &left[2][2], &left[2][1], &left[2][0],
                                                &back[2][2], &back[2][1], &back[2][0],
                                                &right[2][2], &right[2][1], &right[2][0]});
                else RotateNeighbors({&front[2][0], &front[2][1], &front[2][2],
                                        &right[2][0], &right[2][1], &right[2][2],
                                        &back[2][0], &back[2][1], &back[2][2],
                                        &left[2][0], &left[2][1], &left[2][2]});
                break;
                case 'F':
                Rotate(front, isClockwise);
                if(isClockwise) RotateNeighbors({&up[2][2], &up[2][1], &up[2][0],
                                                &left[0][2], &left[1][2], &left[2][2],
                                                &down[0][0], &down[0][1], &down[0][2],
                                                &right[2][0], &right[1][0], &right[0][0]});
                else RotateNeighbors({&up[2][0], &up[2][1], &up[2][2],
                                        &right[0][0], &right[1][0], &right[2][0],
                                        &down[0][2], &down[0][1], &down[0][0],
                                        &left[2][2], &left[1][2], &left[0][2]});
                break;
                case 'B':
                Rotate(back, isClockwise);
                if(isClockwise) RotateNeighbors({&up[0][0], &up[0][1], &up[0][2],
                                                &right[0][2], &right[1][2], &right[2][2],
                                                &down[2][2], &down[2][1], &down[2][0],
                                                &left[2][0], &left[1][0], &left[0][0]});
                else RotateNeighbors({&up[0][2], &up[0][1], &up[0][0],
                                        &left[0][0], &left[1][0], &left[2][0],
                                        &down[2][0], &down[2][1], &down[2][2],
                                        &right[2][2], &right[1][2], &right[0][2]});
                break;
            }
        }

        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                cout<<up[i][j];
            }
            cout<<"\n";
        }
    }
}
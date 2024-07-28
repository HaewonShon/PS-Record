#include <iostream>
#include <set>
using namespace std;

set<int> s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a;
    string cmd; 
    cin >> n;
    while(n--){
        cin >> cmd;
        if(cmd == "add"){
            cin >> a;
            s.insert(a); 
        }
        else if(cmd == "remove"){
            cin >> a;
            s.erase(a);
        }
        else if(cmd == "check"){
            cin >> a;
            if(s.find(a) != s.end())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if(cmd == "toggle"){
            cin >> a;
            if(s.find(a) != s.end())
                s.erase(a);
            else
                s.insert(a);
        }
        else if(cmd == "all"){
            for(int i = 1; i<=20; i++){
                s.insert(i);
            }
        }
        else if(cmd == "empty"){
            s.clear();
        }
    }
}
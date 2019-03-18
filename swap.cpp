#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int main(){
    fast;

    int n , num ;
    while(cin >> n && n != 0){
        stack<int> s;
        int counter = 1;
        bool state = true;
        for(int i = 0 ; i < n ; i++){
            cin >> num ;
            while (!s.empty() && s.top() == counter) {
                counter++;
                s.pop();
            }
            if (num == counter) {
                counter++;
            } else if (!s.empty() && s.top() < num) {
                state = false;
                break;
            } else {
                s.push(num);
            }
        }
        //cout << "Counter :" << counter << endl;
        if(state){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
}

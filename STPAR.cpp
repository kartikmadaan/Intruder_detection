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
        vector<int> order;
        for(int i = 0 ; i < n ; i++){
            cin >> num;
            order.push_back(num);
        }
        stack<int> lane; int need = 1;
        bool state = true;
        for (int i = 0; i < order.size(); i++) {
            while (!lane.empty() && lane.top() == need) {
                need++;
                lane.pop();
            }
            if (order[i] == need) {
                need++;
            } else if (!lane.empty() && lane.top() < order[i]) {
                state = false;
                break;
            } else {
                lane.push(order[i]);
            }
        }
        if (state) cout << "yes" << "\n";
        else cout << "no" << "\n";

    }
    return 0;
}

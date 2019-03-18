#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int main(){
    fast;
    int n , num;
    while(cin >> n && n != 0){
        vector<int> arr;
        int permut[n+2] = {0};
        for(int i = 0 ; i < n ; i++){
            cin >> num;
            arr.push_back(num);
            permut[num] = i + 1;
        }
        // permut is from 1 ... n
        // arr is from 0 to n - 1
        bool state = true;
        for(int i = 0 ; i < n ; i++){
            if(arr[i] != permut[i + 1]){
                state = false;
                break;
            }
        }
        if(state){
            cout << "ambiguous" << endl;
        }
        else{
            cout << "not ambiguous" << endl;
        }

    }
    return 0;
}

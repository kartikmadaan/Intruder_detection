#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int main(){
    fast;
    ll n;
    cin >> n;
    if(n % 10 == 0){
        cout << "2" << endl;
    }
    else{
        cout << "1" << endl;
        cout << n % 10 << endl;
    }
    return 0;
}

#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)


using namespace std;

int arr[10009];

void precompute(){
    int sum = 0;
    for(int i = 0 ; i < 10007 ; i++){
        sum += i;
        arr[i] = sum;
    }
}

int main(){
    fast;
    precompute();
    int n , num ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        cin >> num;
        int *p = lower_bound(arr , arr+10009 , num);
        int loc = (p - arr) ;
        int start = *(p-1) + 1;
        //cout << loc << endl;
        int numPlusDen = loc + 1;
        // loc is either numerator or denominator
        bool upward = true;
        if(loc % 2 == 0){
            upward = false;
        }
        int numerator = 1 , denominator = 1;
        if(upward){
            numerator = loc ;
            for(int i = start ; i < num ; i++){
                numerator -- ;
            }
            denominator = numPlusDen - numerator ;
        }
        else{
            denominator = loc;
            for(int i = start ; i < num ; i++){
                denominator--;
            }
            numerator = numPlusDen - denominator ;
        }
        cout << "TERM " << num << " IS " << numerator << "/" << denominator << endl;
    }
    return 0;
}

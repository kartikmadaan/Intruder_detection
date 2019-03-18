#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int LCS(string s1 , string s2){
    int dp[s1.size() + 1][s2.size() + 1] = {0};
    for(int i = 0 ; i < s2.size() ; i++){
        int k = i + 1;
        for(int j = 0 ; j < s1.size() ; j++){
            int l = j + 1;
            if(s1[i] == s2[j]){
                dp[k][l] = dp[k-1][l-1] + 1;
            }
            else{
                dp[k][l] = max(dp[k-1][l] , dp[k][l-1]);
            }
        }
    }
    //Printing array
    for(int i = 0 ; i <= s2.size() ; i++){
        for(int j = 0 ; j <= s1.size() ; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[s1.size()][s2.size()];
}

int main(){
    string s1 = "alphabet";
    string s2 = "compabot";
    cout << LCS(s1,s2) << endl;
}

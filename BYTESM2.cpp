#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;


/*int ps(int arr[101][101] , int prevRow , int prevCol , int h , int w){
    if(prevRow == -1 && prevCol == -1){

    }

    if(prevRow != -1 && prevCol != -1){
        if(prevCol - 1 < 0 ){
            return max(arr[prevRow][prevCol] , arr[prevRow][prevCol+1]);
        }
        else if(prevCol + 1 >= w  ){
            return max(arr[prevRow][prevCol - 1] , arr[prevRow][prevCol]);
        }
        return max(arr[prevRow][prevCol - 1] , arr[prevRow][prevCol] , arr[prevRow][prevCol + 1] )
    }


}*/

int max(int a , int b , int c){
    return max(max(a , b) , c);
}


int main(){
    int t;
    cin >> t;
    while(t--){
        //cout << "Hi" << endl;
        int h , w;
        cin >> h >> w;
        int sum = 0;
        int arr[101][101] = {0};
        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                cin >> arr[i][j];
            }
        }
        //cout << "First " << first(arr , h , w) << endl;
        //cout << "hi" << endl;
        int dp[101][103] = {0};
        for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w ; j++){
                dp[i][j+1] = arr[i][j];
            }
        }
        for(int i = 1 ; i < h  ; i++){
            for(int j = 0 ; j < w  ; j++){
                //currently at second row , filling from first
                dp[i][j+1] = max(dp[i-1][j+1] , dp[i-1][j] , dp[i-1][j+2]) + arr[i][j] ;
            }
        }
        /*for(int i = 0 ; i < h ; i++){
            for(int j = 0 ; j < w + 2 ; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/
        int last = h-1;
        int maxi = INT_MIN;
        for(int i = 0 ; i < w+2 ; i++){
            if(dp[last][i] > maxi)
                maxi = dp[last][i];
        }
        cout << maxi << endl;

    }
    return 0;
}

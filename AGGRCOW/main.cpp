#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)


using namespace std;

// some random error in bin()
bool bin(int arr[] , int val , int c , int n){
        int counter = c - 1;
        int i = 0 , j = 1;
        while(j < n){
          if(counter == 0)
            return true;
          if(arr[j] - arr[i] >= val){
            c--;
            i = j;
          }
          j++;
        }
        return false;

}

int aggc(int arr[] , int n , int c){
    int low = 1 , high = 1000000002 ;
    // if possible at this , try at smaller
    while(low <= high){
        int mid = (low + high)/2;
        //cout << "mid " <<  mid << endl;
        if(bin(arr , mid , c , n) == true)
            low = mid + 1;
        else
            high = mid - 1;

    }
    return low - 1 ;
}

int main()
{
    //fast;
    int t;
    scanf("%d" , &t);
    while(t--){
        int n , c , temp;
        scanf("%d %d" , & n , & c);
        int arr[n] ;
        for(int i = 0 ; i < n ; i++){
            scanf("%d" , &arr[i]);
        }
        sort(arr , arr + n);
        printf("%d\n" , aggc(arr , n , c) ) ;
    }

    return 0;
}

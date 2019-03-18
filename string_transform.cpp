#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pii pair<int,int>
using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)

int main(){
    fast;
    string s1 = "ACAAGC" , s2 = "CCGT"  ;
    //cin >> s1 >> s2;
    //transform s1 -> s2
    int arr[s1.length()+2][s2.length()+2] ;
    for(int i = 0 ; i < s1.length()+2 ; i++){
        for(int j = 0 ; j < s2.length() + 2 ; j++){
            arr[i][j] = 0;
        }
    }
    string op[s1.length() + 2 ][s2.length() + 2] ;
    op[0][0] = "null\t";
    for(int i = 1 ; i < s1.length() + 1 ; i++){
        arr[i][0] = 2 * i ;
        string p = "";
        p += s1[i-1];
        op[i][0] = "Delete " + p;
    }
    for(int i = 1 ; i < s2.length() + 2 ; i++){
        arr[0][i] = 2 * i ;
        string p = "";
        p += s2[i-1];
        p += "\t";
        op[0][i] = "Insert " + p;
    }

    for(int i = 1 ; i < s1.length() + 1 ; i++){
        for(int j = 1 ; j < s2.length() + 1 ; j++){

            if(s1[i-1] == s2[j-1]){
                arr[i][j] =  arr[i-1][j-1] - 1 ;
                string n1 = "";
                 n1 += s1[i-1];
                 n1 += "\t\t";
                string s = "Copy " + n1 ;
                op[i][j] = s ;
            }
            //replace
            else if(s1[i-1] != s2[j-1]){
                arr[i][j] = arr[i-1][j-1] + 1 ;
                string n1 = "";
                 n1 += s1[i-1];
                string n2 = "";
                n2 += s2[j-1];
                string s = "Replace " + n1 + " with " + n2;
                op[i][j] = s ;
            }
            //Insert or delete
            if(arr[i-1][j] + 2 < arr[i][j]){
                arr[i][j] = arr[i-1][j] + 2;
                string p = "";
                p += s1[i-1];
                op[i][j] = "Delete " + p;
            }
            if(arr[i][j-1] + 2 < arr[i][j]){
                arr[i][j] = arr[i][j-1] + 2;
                string p = "";
                p += s2[j-1];
                op[i][j] = "Insert " + p;
            }
        }
    }

    for(int i = 0 ; i < s1.size() + 1 ; i++){
        for(int j = 0 ; j < s2.size() + 1 ; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

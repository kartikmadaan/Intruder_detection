#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n ;
    int u , v ;
    vector<int> tree[n+1];
    for(int i = 0 ; i < n ; i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    //tree constructed
    bool visited[n+1] = {false};
    int levels[n+1] = {0};
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int fr = q.front();
        //cout << "BFS : " << fr << endl;
        q.pop();
        if(visited[fr] == true)
            continue;
        //visit front
        else
        {
            visited[fr] = true;
            for(int i = 0; i < tree[fr].size() ; i++){
                //cout << "Child #" << i+1 << " is " << tree[fr][i] << endl;
                if(!visited[tree[fr][i]]){
                    q.push(tree[fr][i]);
                    levels[tree[fr][i]] = levels[fr] + 1;

                }
            }
        }

    }
    int maxi = INT_MIN;
    int save = 0;
    for(int i = 0 ;  i < n+1 ; i++){
    //cout << levels[i] << endl;
        if(maxi < levels[i])
        {
            maxi = levels[i];
            save = i;
        }
    }
    cout << "max level at " << save << endl;
    //clear q
    while(!q.empty()){
        q.pop();
    }
    memset(levels , 0 , sizeof(levels));
    memset(visited , false , sizeof(visited));
    q.push(save);
    while(!q.empty()){
        int fr = q.front();
        q.pop();
        if(visited[fr])
            continue;
        else
        {
            visited[fr] = true;
            for(int i = 0; i < tree[fr].size() ; i++){
                //cout << "Child #" << i+1 << " is " << tree[fr][i] << endl;
                if(!visited[tree[fr][i]]){
                    q.push(tree[fr][i]);
                    levels[tree[fr][i]] = levels[fr] + 1;
                }
            }
        }
    }
    sort(levels+1 , levels + n + 1);
    cout<<"ANSWER " << levels[n] << endl;
    return 0;
}

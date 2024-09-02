#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<utility>
#include<map>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<set>
#include<limits.h>
#define tp tuple<int,int,int>
#define pp pair<int, int>
using namespace std;
int n;
vector<vector<int>> v;
void input(){
    cin >> n;
    v.resize(n+1);
    bool temp;
    for(int i=1 ;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> temp;
            if(temp == 1){
                v[i].push_back(j);
            }
        }
    }
}
bool bfs(int start, int target){
    queue<int> q;
    q.push(start);
    bool ans = 0;
    vector<vector<int>> check;
    check.resize(n+1);
    for(int i = 1;i<=n;i++){
        check[i].resize(n+1,0);
    }
    bool isNotFirst = 0;
    while(!q.empty()){
        int front = q.front();
        if(front == target && isNotFirst == 1){
            ans = 1;
            break;
        }
        q.pop();
        isNotFirst = 1;
        for(int i = 0;i<v[front].size();i++){
            if(check[front][i] == 0){
                q.push(v[front][i]);
                check[front][i] = 1;
            }
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    input();
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cout << bfs(i,j) << ' ';
        }
        cout << '\n';
    }
    return 0;
}
    


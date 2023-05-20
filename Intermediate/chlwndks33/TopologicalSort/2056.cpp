#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int n;
int times[10001];
int d[10001];
vector<int> adj[10001];
priority_queue<int, vector<int>, greater<int>> pq;
int inComing[10001];
int ans;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> times[i];
        int k;
        cin >> k;
        for(int j=0; j<k; j++) {
            int c;
            cin >> c;
            adj[i].push_back(c);
            inComing[c]++;
        }
    }
    for(int i=1; i<=n; i++) {
        if(inComing[i] == 0) {
            pq.push(i);
            d[i] = times[i];
        }
    }
    while(!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        for(auto nxt : adj[cur]) {
            inComing[nxt]--;
            d[nxt] = max(d[nxt], d[cur]+ times[nxt]);
            if(inComing[nxt] == 0) {
                pq.push(nxt);
            }
        }
    }
    cout << *max_element(d+1, d+1+n);

    
}
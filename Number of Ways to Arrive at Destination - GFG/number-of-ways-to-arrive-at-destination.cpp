//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    const int MOD=1e9+7;
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];

        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<long long>dist(n,LONG_MAX);
        vector<int>ways(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            long long distance=it.first;
            int node=it.second;

            for(auto ngh:adj[node]){
                int adjNode=ngh.first;
                long long wgt=ngh.second;

                if(distance+wgt<dist[adjNode]){
                    dist[adjNode]=distance+wgt;
                    pq.push({distance+wgt,adjNode});
                    ways[adjNode]=ways[node];
                }

                else if(distance+wgt==dist[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%MOD;
                }
            }
        }

        return ways[n-1]%MOD;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int timer=1;
    
    void dfs(int node,int parent,vector<int>&low,vector<int>&insertion,vector<int>&mark,vector<int>&vi,vector<int>adj[]){
        vi[node]=1;
        low[node]=insertion[node]=timer++;
        int child=0;
        
        for(auto it:adj[node]){
            if(it==parent){
                continue;
            }
            
            if(vi[it]==0){
                dfs(it,node,low,insertion,mark,vi,adj);
                low[node]=min(low[node],low[it]);
                if(low[it]>=insertion[node] && parent!=-1){
                    mark[node]=1;
                }
                child++;
            }
            
            else{
                low[node]=min(low[node],insertion[it]);
            }
        }
        
        if(child>1 && parent==-1){
            mark[node]=1;
        }
    }
  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int>low(n);
        vector<int>insertion(n);
        vector<int>mark(n);
        vector<int>vi(n);
        
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            if(vi[i]==0){
                dfs(i,-1,low,insertion,mark,vi,adj);
            }
        }
        
        for(int i=0;i<n;i++){
            if(mark[i]==1){
                ans.push_back(i);
            }
        }
        
        if(ans.size()==0){
            return {-1};
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
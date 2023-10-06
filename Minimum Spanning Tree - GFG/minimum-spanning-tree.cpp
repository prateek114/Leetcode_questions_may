//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int>rank,parent,size;

    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int ultimateParent(int node){
        if(node==parent[node]){
            return node;
        }

        return parent[node]=ultimateParent(parent[node]);
    }

    void unionByRank(int u,int v){
        int ulP_u=ultimateParent(u);
        int ulP_v=ultimateParent(v);

        if(ulP_u==ulP_v){
            return;
        }

        if(rank[ulP_u]<rank[ulP_v]){
            parent[ulP_u]=ulP_v;
        }

        else if(rank[ulP_v]<rank[ulP_u]){
            parent[ulP_v]=ulP_u;
        }

        else{
            parent[ulP_u]=ulP_v;
            rank[ulP_v]++;
        }
    }

    void unionBySize(int u,int v){
        int ulP_u=ultimateParent(u);
        int ulP_v=ultimateParent(v);

        if(ulP_u==ulP_v){
            return;
        }

        if(size[ulP_u]<size[ulP_v]){
            parent[ulP_u]=ulP_v;
            size[ulP_v]+=size[ulP_u];
        }

        else{
            parent[ulP_v]=ulP_u;
            size[ulP_u]+=size[ulP_v];
        }
    }

};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edges;
        
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int adjNode=it[0];
                int wt=it[1];
                int node=i;
                
                edges.push_back({wt,{node,adjNode}});
            }
        }
        
        sort(edges.begin(),edges.end());
        DisjointSet ds(V);
        
        int minSt=0;
        
        for(auto ele:edges){
            int wt=ele.first;
            int u=ele.second.first;
            int v=ele.second.second;
            
            if(ds.ultimateParent(u)!=ds.ultimateParent(v)){
                minSt+=wt;
                ds.unionBySize(u,v);
            }
        }
        
        return minSt;
    }
};




//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
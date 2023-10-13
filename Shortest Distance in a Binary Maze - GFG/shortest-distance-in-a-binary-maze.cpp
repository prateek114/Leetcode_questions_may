//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        if(source.first==destination.first && source.second==destination.second){
            return 0;
        }
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        
        // {dist,{row,col}}
        
        queue<pair<int,pair<int,int>>>pq;
        dist[source.first][source.second]=0;
        pq.push({0,{source.first,source.second}});
        
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        
        while(!pq.empty()){
            auto it=pq.front();
            pq.pop();
            int distance=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
            for(int i=0;i<4;i++){
                int newRow=row+dr[i];
                int newCol=col+dc[i];
                
                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]==1){
                    if(distance+1<dist[newRow][newCol]){
                        dist[newRow][newCol]=distance+1;
                        
                        if(newRow==destination.first && newCol==destination.second){
                            return dist[newRow][newCol];
                        }
                        pq.push({distance+1,{newRow,newCol}});
                    }
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/?page=1&status[]=unsolved&curated[]=5&sortBy=submissions#

class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
        
    vector<pair<int,int>> moves = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
    
    int maxans = 0;
    
    bool isvalid(int i,int j,int n,int m){
        return i>-1 && j>-1 && i<n && j<m;
    }
    
    void bfs(vector<vector<int>>& grid,vector<vector<int>> &visited,int i,int j){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        int ans = 0;
        visited[i][j] =1 ;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            ans++;
            maxans = max(maxans,ans);
            for(int i=0;i<8;i++){
                int x = p.first + moves[i].first;
                int y = p.second + moves[i].second;
                if(isvalid(x,y,n,m) && !visited[x][y] && grid[x][y] ==1 ){
                    q.push({x,y});
                    visited[x][y] = 1;
                }
            }
        }
    }
    
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited;
        for(int i=0;i<n;i++){
            vector<int> here(m,0);
            visited.push_back(here);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !visited[i][j])
                    bfs(grid,visited,i,j);
            }
        }
        return maxans;
    }
};

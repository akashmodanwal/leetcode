// https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1/?page=1&status[]=unsolved&curated[]=5&sortBy=submissions#

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    struct cell{
        int x;
        int y;
        int d;
        cell(int i,int j,int k){
            x = i;
            y = j;
            d = k;
        }
    };
    
    vector<pair<int,int>> moves = {
        {1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}
    };
    
    bool isvalid(cell c,int n){
        return c.x>-1 && c.y>-1 && c.x<n && c.y<n;
    }
    
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	   queue<cell>q;
	   vector<vector<int>> visited;
	   for(int i=0;i<N;i++){
	       vector<int> here(N,0);
	       visited.push_back(here);
	   }
	   q.push(cell(KnightPos[0]-1,KnightPos[1]-1,0));
	   visited[KnightPos[0]-1][KnightPos[1]-1] = 1;
	   while(!q.empty()){
	       cell c = q.front();
	       q.pop();
	      // cout<<c.x<<c.y<<endl;
	       if(c.x == TargetPos[0]-1 && c.y == TargetPos[1]-1)
	            return c.d;
	       for(int i=0;i<8;i++){
	           cell adj = cell(c.x + moves[i].first , c.y + moves[i].second, c.d +1);
	           if(isvalid(adj,N) && !visited[adj.x][adj.y]){
	               visited[adj.x][adj.y] = 1;
	               q.push(adj);
	           }
	       }
	   }
	   return -1;
	}
};

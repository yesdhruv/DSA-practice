class Solution {
public:
    int solveRec(vector<vector<int>>& grid,int n,int m,int i,int j)
    {
        // if(i>=n or j>=m)return INT_MAX;// IF RETURN 0 THEN OBTAINED SUM WILL BECOME 0 AS MIN CONDITION 
        // if(i==n-1&&j==m-1) return grid[n-1][m-1];
        // int right = solveRec(grid,n,m,i+1,j);
        // int bottom =solveRec(grid,n,m,i,j+1);
        //  return min(right,bottom)+grid[i][j];
        
        if(i==0&&j==0) return grid[0][0];
        if(i<n or j<m)return INT_MAX;// IF RETURN 0 THEN OBTAINED SUM WILL BECOME 0 AS MIN CONDITION 
        if(i==n-1&&j==m-1) return grid[n-1][m-1];
        int left = solveRec(grid,n,m,i-1,j);
        int up =solveRec(grid,n,m,i,j-1);
         
    return min(left,up)+grid[i][j];
    }
    // Time Complexity: O(NxM)
    // Space Complexity: O(NxM)^2
    int solveMem(vector<vector<int>>& grid,int n,int m,int i,int j,vector<vector<int>> &dp)
    {
        
            if(dp[i][j]!=-1)return dp[i][j] ;
        if(i>=n or j>=m)return INT_MAX;// IF RETURN 0 THEN OBTAINED SUM WILL BECOME 0 AS MIN CONDITION 
        if(i==n-1&&j==m-1) return grid[n-1][m-1];
        int right= solveMem(grid,n,m,i+1,j,dp);
        int bottom  =solveMem(grid,n,m,i,j+1,dp);
         
        return dp[i][j] = min(right,bottom)+grid[i][j];
    }
    // Time Complexity: O(NxM)
    // Space Complexity: O(NxM) + O(N+M)
    // (O(NxM) for dp grid and O(N+M) for extra stack space)
    int solveTab(vector<vector<int>>& grid,int n,int m,int i,int j)
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(i==0 and j==0) dp[i][j]=grid[i][j];
                else{
                    int up =0,left=0; 
                    
                    if(i>0) up+=grid[i][j]+dp[i-1][j];
                    else
                        up+=1e9;
                    
                    if(j>0) left+=grid[i][j]+dp[i][j-1];
                    else
                        left+=1e9;
                    
                    dp[i][j] = min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
    // Time Complexity: O(MxN)
    // Space Complexity: O(M)

   
    int solveSO(vector<vector<int>>& grid,int n,int m,int i,int j)
    {
        vector<int>prev(m,0);
         for(int i=0;i<n;i++)
        {
             vector<int>cur(m,0);
            for(int j=0;j<m;j++)
            {
               if(i==0 and j==0) cur[j]=grid[i][j];
                else{
                    int up =0,left=0; 
                    
                    if(i>0) up+=grid[i][j]+prev[j];
                    else
                        up+=1e9;
                    
                    if(j>0) left+=grid[i][j]+cur[j-1];
                    else
                        left+=1e9;
                    
                    cur[j] = min(up,left);
                }  
            }
             prev = cur;
        }
        return prev[m-1];
    }
     // Time Complexity: O(MxN)
    // Space Complexity: O(M)
    
    int minPathSum(vector<vector<int>>& grid) {
        int n= size(grid);
        int m = size(grid[0]);
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      // return solveMem(grid,n,m,0,0,dp);
         // return solveTab(grid,n,m,0,0);
        return solveSO(grid,n,m,0,0);
    }
    
};

class Solution {
public:
    int solveRec(vector<vector<int>>& matrix,int i ,int j , int n, int m)
    {
        // from bottom to up 
        if(i==0)return matrix[0][j];
        // out of boundary conditions
        if(j<0 or j>=m)return 1e9; //to stopoverflow i.e(+ve + INT_MAX )
        // why return min cause ot will not affect our answer(as we found max )
        
         int s = matrix[i][j]+ solveRec(matrix,i-1,j,n,m);// straight
         int ld = matrix[i][j]+ solveRec(matrix,i-1,j-1,n,m);//left direction
         int rd = matrix[i][j]+ solveRec(matrix,i-1,j+1,n,m);// right dirction
        
      return min(s,min(ld,rd));
    }
    
    int solveMem(vector<vector<int>>& matrix,int i ,int j , int n, int m,vector<vector<int>>& dp)
    {
        // from bottom to up 
        if(i==0)return matrix[0][j];
        // out of boundary conditions
        if(j<0 or j>=m)return 1e9; //to stopoverflow i.e(+ve + INT_MAX )
        // why return min cause ot will not affect our answer(as we found max )
        
        if(dp[i][j]!=-1)return dp[i][j];
        
         int s = matrix[i][j]+ solveMem(matrix,i-1,j,n,m,dp); // straight
         int ld = matrix[i][j]+ solveMem(matrix,i-1,j-1,n,m,dp);//left direction
         int rd = matrix[i][j]+ solveMem(matrix,i-1,j+1,n,m,dp);// right dirction
        
        return dp[i][j]=min(s,min(ld,rd));
    }
    
    int solveTab(vector<vector<int>>& matrix, int n, int m,vector<vector<int>>& dp)
    {
        // tab always fill in oppsoite to reccurence rel.
        // base case
       for(int j=0;j<m;j++)dp[0][j]=matrix[0][j];
        
        // filling up 2d in opp. to recurence relt
         for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int ld = matrix[i][j]; int rd= matrix[i][j];
                int s = matrix[i][j]+ dp[i-1][j]; // straight
                if(j-1>=0)// out of bound condn
                    {  ld +=  dp[i-1][j-1];}//left direction
                else ld+=1e8;
                if(j+1<m)
                    {  rd += dp[i-1][j+1];}// right dirction
                else rd+=1e8;
                
                dp[i][j]=min(s,min(ld,rd));
            }
        }
        
//         // last row contains the minimums
        int mini= dp[n-1][0];
        for(int j=0;j<m;j++) mini = min(mini, dp[n-1][j]);
        
        return mini;
    }
    
       int solveSO(vector<vector<int>>& matrix, int n, int m)
       {
            vector<int> prev(m,0);

            for(int j=0;j<m;j++)prev[j]=matrix[0][j];

            for(int i=1;i<n;i++){
                vector<int>curr(m,0);
                for(int j=0;j<m;j++){
                    int up=matrix[i][j]+prev[j];
                    int leftd=matrix[i][j];
                    if(j-1>=0)leftd+=prev[j-1];
                    else leftd+=1e8;

                    int rd=matrix[i][j];
                    if(j+1<m)rd+=prev[j+1];
                    else rd+=1e8;

                    curr[j]=min(up,min(leftd,rd));
                }
                prev=curr;
            }

            int mini=1e8;

            for(int j=0;j<m;j++){
                mini=min(mini,prev[j]);
            }
            return mini;
    
        }
int solveSOMore(vector<vector<int>>& matrix, int n, int m)
{        
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<m;j++)
        {
            int lDiag=INT_MAX;
            int rDiag=INT_MAX;
            if(j-1>=0)  lDiag=matrix[i+1][j-1];
            int bottom=matrix[i+1][j]; 
            if(j+1<m)   rDiag=matrix[i+1][j+1];
            
            matrix[i][j]=matrix[i][j]+min(lDiag,min(bottom,rDiag));
        }
    }
    
    int ans=INT_MAX;
    for(int j=0;j<m;j++) ans=min(ans,matrix[0][j]);
    return ans;
}

       int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = size(matrix);
        int m = size(matrix[0]);
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int ans = 1e9;
//         for(int j=0;j<m;j++)
//         {
//             //ans = min(solveRec(matrix,n-1,j,n,m) ,ans);
//             ans = min(solveMem(matrix,n-1,j,n,m,dp) ,ans);
//         }
        
       // in tabulation we maintin a 2dp so we dont need to loop as such
    //     vector<vector<int>> dp1(n,vector<int>(m,-1));
    //    return solveTab(matrix,n,m,dp1);
    // return ans;
       // return solveSO(matrix,n,m);
           ans=solveSOMore(matrix,n,m);
    return ans;
    }
};

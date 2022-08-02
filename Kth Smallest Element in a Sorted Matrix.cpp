Idea :
Count number of elements which are smaller than or equal to mid in every row, and if count is less than k than we increase l to mid+1 because we need a larger mid which increase the count else decrease r= mid-1,

Time Complexity : O ( NLogNLogN )
Space Complexity : O( 1 )*/

// [[-5,-4],[-5,-4]] exmapleleads to tle
// 2
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       // can use max heap and store k elements then pop the top i.e our kth smallest t.c ->O(n^2*logk)
//         priority_queue<int>pq;
//         for(int i=0;i<size(matrix);i++)
//         {
//             for(int j=0;j<size(matrix[0]);j++)
//             {
//                  pq.push(matrix[i][j]);
//                 if(pq.size()>k)
//                 {
//                     pq.pop();   
//                 }
              
//             }
//         }return pq.top();
        int n=matrix.size();
        int l=matrix[0][0],r=matrix[n-1][n-1];
        
        while(l<=r){
            int mid=(l+r)/2;
            int cnt=0;
            for(int i=0;i<n;i++){
                cnt+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            
            if(cnt<k){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        
        return l;
    }
};

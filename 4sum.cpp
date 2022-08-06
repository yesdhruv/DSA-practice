// 3sum --> 4 sum
class Solution {
public:
   vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n=nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());  //sorting is the mandatory step!!
    for(int i=0;i<n-3;i++)
    {
        if( i>0&&nums[i]==nums[i-1]) continue;  //skipping duplicates
        for(int j=i+1;j<n-2;j++)
        {
            if( j>i+1&&nums[j]==nums[j-1]) continue;  ////skipping duplicates
            int s=j+1; int e=n-1;
            while(s<e)
            { 
			    //Handling [1e7,1e7,1e7] case make them long long
                long long lr_sum=nums[s]+nums[e]; //left right sum;
                long long sum=nums[i]+nums[j]+lr_sum;  //4sum
                if(sum==target) 
                {
                    ans.push_back((vector<int>{nums[i],nums[j],nums[s],nums[e]}));
                    do{s++;}while(s<e&&nums[s]==nums[s-1]);
                    do{e--;}while(e>s&&nums[e]==nums[e+1]);
                }
                else
                  sum>target?e--:s++;
            }
        }
    }
    return ans;
}
};

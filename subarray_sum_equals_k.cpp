class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // we are using a cummulative sum array or prefix sum array
        // and store it in hashamp
        
        unordered_map<int,int>mp;// gain ==k and value
        mp[0]=1;
        int ans=0;
        int sum=0;
        for(int i=0;i<size(nums);i++)
        {
           sum+=nums[i];
            if(mp.find(sum-k)!=mp.end())
            {
                // i have found the gain
                ans+=mp[sum-k];
            }
           /* if(mp.find(sum)==mp.end())
            {
                mp[sum]=1;
            }
            else*/ mp[sum]++;
        }
        return ans;
    }
};

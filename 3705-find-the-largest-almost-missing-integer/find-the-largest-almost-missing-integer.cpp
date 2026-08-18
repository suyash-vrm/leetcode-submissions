class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==n){
            return *max_element(nums.begin() , nums.end());
        }

        unordered_map<int,int> freq;
        for(int num:nums){
            freq[num]++;
        }

        if(k==1){
            int max_val = -1;
            for(auto& [num,count] : freq){
                if(count==1){
                    max_val = max(max_val,num);
                }
            }
            return max_val;
        }

        int ans =-1;
        if(freq[nums[0]] == 1){
            ans = max(ans,nums[0]);
        }
        if(freq[nums[n-1]] ==1){
            ans = max(ans, nums[n-1]);
        }

        return ans;
    }
};
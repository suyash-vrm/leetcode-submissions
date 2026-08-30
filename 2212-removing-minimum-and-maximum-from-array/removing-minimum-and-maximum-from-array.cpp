class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minnum = INT_MAX;
        int maxnum = INT_MIN;
        int minind = 0;
        int maxind = 0;

        for(int i =0 ; i< n;i++){
            if(nums[i] >= maxnum){
                maxnum = nums[i];
                maxind = i;
            }
            if(nums[i] <= minnum){
                minnum = nums[i];
                minind = i;
            }
        }
        int left = std::min(minind, maxind);
        int right = std::max(minind, maxind);

        int option1 = right + 1;
        int option2 = n - left;
        int option3 = (left + 1) + (n - right);

        

        return min({option1,option2,option3});
    }
};
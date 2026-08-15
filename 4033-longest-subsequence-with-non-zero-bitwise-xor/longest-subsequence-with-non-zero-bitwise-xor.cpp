class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr=0;
        int n = nums.size();
        int hasnonzero = false ;
        for(int x :nums){
            xr^=x;
            if(x!=0)
                hasnonzero = true;
        }

        if(xr!=0){
            return n;
        }
        
        if(!hasnonzero){
            return 0;
        }

        return n-1;
    }
};
class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size();
        int min_dist = INT_MAX;
        int ans = -1 ;

        for(int i = 0; i<n;i++){
            int dist_x = abs(drones[i][0] - target[0]);
            int dist_y = abs(drones[i][1] - target[1]);
            int totdist = dist_x + dist_y;
            if(totdist <= drones[i][2]){
               if (totdist < min_dist) {
                min_dist = totdist;
                ans = i;
                }

            }
        }


        return ans;
    }
};
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> mp;

        // Store reserved seats as bitmasks
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            mp[row] |= (1 << s);
        }

        // Masks for the three possible groups
        int LEFT = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int MIDDLE = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int RIGHT = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        // Initially every row can accommodate 2 groups
        int ans = 2 * n;

        // Only rows with reservations need adjustment
        for (auto &[row, mask] : mp) {

            bool left = (mask & LEFT) == 0;
            bool middle = (mask & MIDDLE) == 0;
            bool right = (mask & RIGHT) == 0;

            if (left && right) {
                // Still 2 groups
                continue;
            }
            else if (left || middle || right) {
                // This row can accommodate only 1 group
                ans -= 1;
            }
            else {
                // This row can accommodate 0 groups
                ans -= 2;
            }
        }

        return ans;
    }
};
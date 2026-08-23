class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        double sum = 0;

        for (int i = 0; i < n; i++) {
            int sign = (i < n / 2) ? 1 : -1;
            if (num[i] == '?') {
                sum += sign * 4.5;
            } else {
                sum += sign * (num[i] - '0');
            }
        }

        return sum != 0;
    }
};
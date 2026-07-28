class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char ch : s)
            freq[ch - 'a']++;

        string left = "";

        for (int i = 0; i < 26; i++) {
            left.append(freq[i] / 2, char(i + 'a'));
        }

        string right = "";
        for(int i = 0 ;i < 26;i++){
            right.append(freq[i]/2 , char(i + 'a'));
        }
        reverse(right.begin(),right.end());

        string middle = "";

        for(int i = 0 ; i< 26;i++){
            if(freq[i] %2 == 1){
                middle = char(i + 'a');
            }
        }
        return left+middle+right;
    }
};
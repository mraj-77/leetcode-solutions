class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int count1[26] = {0};
        int count2[26] = {0};

        int n = s1.length();
        int m = s2.length();

        if(n > m) {
            return false;
        }

        // Count characters of s1
        for(int i = 0; i < n; i++) {
            count1[s1[i] - 'a']++;
        }

        // First window of s2
        for(int i = 0; i < n; i++) {
            count2[s2[i] - 'a']++;
        }

        // Compare first window
        if(equal(count1, count1 + 26, count2)) {
            return true;
        }

        // Sliding Window
        for(int i = n; i < m; i++) {

            // Remove outgoing character
            count2[s2[i - n] - 'a']--;

            // Add incoming character
            count2[s2[i] - 'a']++;

            // Compare frequencies
            if(equal(count1, count1 + 26, count2)) {
                return true;
            }
        }

        return false;
    }
};
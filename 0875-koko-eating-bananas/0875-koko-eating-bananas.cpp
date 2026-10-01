class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int start = 1;
        int end = 0;
        int ans = 0;

        for(int i = 0; i < piles.size(); i++) {
            end = max(end, piles[i]);
        }

        while(start <= end) {

            int mid = start + (end - start) / 2;
            long long total_time = 0;

            for(int i = 0; i < piles.size(); i++) {

                total_time += piles[i] / mid;

                if(piles[i] % mid != 0) {
                    total_time++;
                }
            }

            if(total_time > h) {
                start = mid + 1;
            }
            else {
                ans = mid;
                end = mid - 1;
            }
        }

        return ans;
    }
};
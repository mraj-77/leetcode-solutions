class Solution {
public:
    int mySqrt(int x) {
        int s = 0;
        int e = x;
        long long int ans = 0;
        while(s <= e) {
            long long int mid = s + (e - s) / 2;
            long long int sqr = mid * mid;
            if(sqr == x) {
                return mid;
            }
            else if(sqr > x) {
                e = mid - 1;
            }
            else {
                ans = mid;
                s = mid + 1;
            }
        }

        return ans;
    }
};

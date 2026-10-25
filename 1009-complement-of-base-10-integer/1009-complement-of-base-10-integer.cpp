class Solution {
public:
    int bitwiseComplement(int n) {
        // Edge case: binary of 0 is "0", complement is "1"
        if (n == 0) return 1;

        // Build mask of all 1s with the same bit length as n
        int mask = 1;
        while (mask <= n) {
            mask <<= 1;
        }
        // mask is now 2^k (one bit above n's highest bit)

        // (mask - 1) = all 1s, XOR flips every bit of n
        return (mask - 1) ^ n;
    }
};
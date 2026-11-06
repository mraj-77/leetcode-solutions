class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;
        
        // Shuru mein maan lete hain ki 2 se n-1 tak saare (n - 2) numbers prime hain
        int count = n - 2;

        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    // Agar yeh number pehle se prime mark tha, toh ise composite karo aur count ghatao
                    if (prime[j]) {
                        prime[j] = false;
                        count--;
                    }
                }
            }
        }

        return count;
    }
};
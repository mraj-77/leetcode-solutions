class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int start = 0;
        int end = 0;

        // Minimum capacity = maximum weight
        // Maximum capacity = sum of all weights
        for(int weight : weights){
            start = max(start, weight);
            end += weight;
        }

        int ans = end;

        while(start <= end){

            int mid = start + (end - start) / 2;

            int currentWeight = 0;
            int requiredDays = 1;

            // Check how many days are needed
            // if ship capacity is 'mid'
            for(int weight : weights){

                if(currentWeight + weight <= mid){
                    currentWeight += weight;
                }
                else{
                    // Current day is full,
                    // so start a new day
                    requiredDays++;
                    currentWeight = weight;
                }
            }

            // If we can ship within given days,
            // try a smaller capacity
            if(requiredDays <= days){
                ans = mid;
                end = mid - 1;
            }
            else{
                // Capacity is too small,
                // so increase it
                start = mid + 1;
            }
        }

        return ans;
    }
};
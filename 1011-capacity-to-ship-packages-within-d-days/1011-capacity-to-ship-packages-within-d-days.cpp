class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int start = 0;
        int end = 0;

        for(int weight : weights){
            start = max(start, weight);
            end += weight;
        }

        while(start <= end){

            int mid = start + (end - start) / 2;

            int currentWeight = 0;
            int requiredDays = 1;

            for(int weight : weights){

                if(currentWeight + weight <= mid){
                    currentWeight += weight;
                }
                else{
                    requiredDays++;
                    currentWeight = weight;
                }
            }

            if(requiredDays <= days){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        return start;
    }
};
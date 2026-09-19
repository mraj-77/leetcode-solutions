class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        int start = 0, end = 0;

        for(int i = 0; i < weights.size(); i++){
            start = max(start, weights[i]);
            end += weights[i];
        }

        int ans = end;

        while(start <= end){

            int mid = start + (end - start) / 2;

            int sum = 0;
            int count = 1;

            for(int i = 0; i < weights.size(); i++){

                if(sum + weights[i] <= mid){
                    sum += weights[i];
                }
                else{
                    count++;
                    sum = weights[i];
                }
            }

            if(count <= days){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }

        return ans;
    }
};
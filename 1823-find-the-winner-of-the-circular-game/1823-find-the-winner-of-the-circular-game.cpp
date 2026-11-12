class Solution {

    int winner(vector<bool>& person, int n, int index, int person_left, int k){

        // Base Case
        if(person_left == 1){
            for(int i = 0; i < n; i++){
                if(person[i] == 0){
                    return i;
                }
            }
        }

        int kill = k;

        while(kill > 1){

            index = (index + 1) % n;

            while(person[index] == 1){
                index = (index + 1) % n;
            }

            kill--;
        }

        // Kill kth person
        person[index] = 1;

        // Find next alive person
        while(person[index] == 1){
            index = (index + 1) % n;
        }

        return winner(person, n, index, person_left - 1, k);
    }

public:
    int findTheWinner(int n, int k) {

        vector<bool> person(n, 0);

        return winner(person, n, 0, n, k) + 1;
    }
};
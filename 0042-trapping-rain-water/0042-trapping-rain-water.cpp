class Solution {
public:
    int trap(vector<int>& height) {
        int maxleft = 0, maxright = 0, water = 0;
        int maxheight = height[0];
        int index = 0;
        int n = height.size();

        // Find the highest building
        for(int i = 0; i < n; i++) {
            if(height[i] > maxheight) {
                maxheight = height[i];
                index = i;
            }
        }

        // Calculate water on left side
        for(int i = 0; i < index; i++) {
            if(maxleft > height[i]) {
                water += maxleft - height[i];
            }
            else {
                maxleft = height[i];
            }
        }

        // Calculate water on right side
        for(int i = n - 1; i > index; i--) {
            if(maxright > height[i]) {
                water += maxright - height[i];
            }
            else {
                maxright = height[i];
            }
        }

        return water;
    }
};
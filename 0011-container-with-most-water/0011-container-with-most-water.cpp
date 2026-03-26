class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxi = INT_MIN;
        while(l < r){
            int a = (r - l) * min(height[l],height[r]);
            maxi = max(maxi,a);
            if(height[l] < height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxi;
    }
};
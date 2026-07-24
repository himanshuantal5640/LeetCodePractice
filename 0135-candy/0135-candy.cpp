class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 1;
        int i = 1;
        while(i < n){
            //flat surface
            if(ratings[i] == ratings[i-1]){
                sum++;
                i++;
                continue;
            }
            //increaing slope
            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1]){
                peak++;
                sum += peak;
                i++;
            }
            //decreasing slope
            int down = 1;
            while(i<n && ratings[i] < ratings[i-1]){
                sum += down;
                down++;
                i++;
            }
            if(down > peak){
                sum += (down - peak);
            }
        }
        return sum;
    }
};
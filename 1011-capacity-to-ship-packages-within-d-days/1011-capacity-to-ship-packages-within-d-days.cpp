class Solution {
public:
    bool canShip(vector<int>& arr,int days,int capacity){
        int curr = 0;
        int req = 1;
        for(int wt : arr){
            if(wt + curr > capacity){
                req++;
                curr = 0;
            }
            curr += wt;
        }
        return req <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low <= high){
            int mid = (low + high)/2;
            if(canShip(weights,days,mid)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
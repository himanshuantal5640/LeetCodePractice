class Solution {
public:
    bool canEat(vector<int> &piles,int h,int k){
        long long hrs = 0;
        for(int p:piles){
            hrs += (p + k -1)/k;
        }
        return hrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int ans = r;
        while(l <= r){
            int m = (l+r)/2;
            if(canEat(piles,h,m)){
                ans = m;
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return ans;
    }
};
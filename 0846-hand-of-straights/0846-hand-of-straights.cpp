class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0){
            return false;
        }
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[hand[i]]++;
        }
        for(auto it : mpp){
            int st = it.first;
            int freq = it.second;
            if(freq > 0){
                for(int i = 0;i<groupSize;i++){
                    int cur = st + i;
                    if(mpp[cur] < freq){
                        return false;
                    }
                    mpp[cur] -= freq;
                }
            }
        }
        return true;
    }
};
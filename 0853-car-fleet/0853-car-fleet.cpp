class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,int>> car;
        for(int i=0;i<n;i++){
            car.push_back({position[i],speed[i]});
        }
        //sort in descending order
        sort(car.rbegin(),car.rend());
        int fleet = 0;
        double ptime = 0;
        for(auto it:car){
            int p = it.first;
            int s = it.second;
            double time = double(target - p)/s;
            if(time > ptime){
                fleet++;
                ptime = time;
            }
        }
        return fleet;
    }
};
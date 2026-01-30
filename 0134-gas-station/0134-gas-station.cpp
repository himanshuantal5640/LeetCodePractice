class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        for(int x:gas){
            totalGas += x;
        }
        for(int x:cost){
            totalCost += x;
        }
        if(totalGas < totalCost){
            return -1;
        }
        int st = 0;
        int currGas = 0;
        int n = gas.size();
        for(int i=0;i<n;i++){
            currGas = currGas + gas[i] - cost[i];
            if(currGas < 0){
                st = i+1;
                currGas = 0;
            }
        }
        return st;
    }
};
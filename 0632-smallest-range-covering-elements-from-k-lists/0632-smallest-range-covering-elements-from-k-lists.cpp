class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int maxVal = INT_MIN; //max val of current window
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minHeap;//{val,row,col}
        int k = nums.size();
        //push first element of all list
        for(int i=0;i<k;i++){
            maxVal = max(maxVal,nums[i][0]);
            minHeap.push({nums[i][0],i,0});
        }
        int min_L = 0;//start of range
        int max_R = INT_MAX; //end of range
        while(1){
            auto curr = minHeap.top();
            minHeap.pop();
            int r = curr[1];
            int c = curr[2];
            int val = curr[0];
            if(max_R - min_L > maxVal - val){
                min_L = val;
                max_R = maxVal;
            }
            //push remianing elemtn
            if(c < nums[r].size()-1){
                minHeap.push({nums[r][c+1],r,c+1});
                maxVal = max(maxVal,nums[r][c+1]);
            }
            else{
                break;
            }
        }
        return {min_L,max_R};

    }
};
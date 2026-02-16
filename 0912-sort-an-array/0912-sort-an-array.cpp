class Solution {
public:
    void heapify(vector<int>&nums,int n,int i){
        int lg = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if(l<n && nums[l]>nums[lg]){
            lg = l;
        }
        if(r<n && nums[r]>nums[lg]){
            lg = r;
        }
        if(lg != i){
            swap(nums[i],nums[lg]);
            heapify(nums,n,lg);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = n/2 -1;i>=0;i--){
            heapify(nums,n,i);
        }
        for(int i=n-1;i>0;i--){
            swap(nums[0],nums[i]);
            heapify(nums,i,0);
        }
        return nums;
    }
};
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // use Duth national flag algo which use 3 pointers low ,mid,high
        // where 0 to low - 1 points to 0 and low to mid - 1 points to 1 and high + 1 to n-1 points to 2 and mid to high points to unsorted elements
        int mid = 0;
        int low = 0;
        int high = nums.size() - 1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                //nums[mid] == 2;

                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
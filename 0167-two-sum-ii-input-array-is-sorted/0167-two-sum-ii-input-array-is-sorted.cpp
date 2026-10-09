class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while(i < j){
            int m = numbers[i] + numbers[j];
            if(m == target){
                return {i+1,j+1};
            }
            else if(m > target){
                j--;
            }
            else{
                i++;
            }
        }
        return {};
    }
};
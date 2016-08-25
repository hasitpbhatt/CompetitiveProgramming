// O(n^2) : 545 ms

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v(2);
        for(int i=0;i<nums.size();i++) {
            int f = target - nums[i];
            for(int j=i+1;j<nums.size();j++) {
                if(f == nums[j]) {
                    v[0] = i;
                    v[1] = j;
                    return v;
                }
            }
        }
        return v;
    }
};
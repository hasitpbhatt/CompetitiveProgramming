// O(n) theoratically : 20ms

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v(2);
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++) {
            // if it is a part of solution, it can not occur twice in array
            // stated in problem
            if(umap.find(target-nums[i]) != umap.end()) {
                v[0] = umap[target-nums[i]];
                v[1] = i;
                return v;
            }
            umap[nums[i]] = i;
        }
        return v;
    }
};
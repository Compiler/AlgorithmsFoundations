class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> complMap;
        for(int i = 0; i < nums.size(); i++) {
            complMap[target - nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++) {
            auto targetIt = complMap.find(nums[i]);
            if(targetIt != complMap.end() && i != targetIt->second) {
                return {i, targetIt->second};
            }
        }
        return {0, 0};
    }
};


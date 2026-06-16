class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> pos;

    for (int i = 0; i < nums.size(); i++) {
      int vj = target - nums[i];

      if (pos.count(vj) > 0) {
        return {pos[vj], i};
      }

      pos.insert({nums[i], i});
    }

    return {};
  }
};
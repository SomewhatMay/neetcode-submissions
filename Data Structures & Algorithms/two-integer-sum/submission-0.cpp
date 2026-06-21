class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> pos;

    for (auto it = nums.begin(); it != nums.end(); it++) {
      pos.insert({*it, it - nums.begin()});
    }

    for (auto it = nums.begin(); it != nums.end(); it++) {
      int i = it - nums.begin();
      int vj = target - *it;

      if (pos.count(vj) != 0) {
        int j = pos.at(vj);

        if (j != i) {
          return {i, j};
        }
      }
    }

    return {};
  }
};
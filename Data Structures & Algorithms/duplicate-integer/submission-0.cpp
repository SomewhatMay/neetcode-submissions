class Solution {
public:
    bool hasDuplicate(vector<int> &nums) {
  unordered_set<int> found;

  for (auto it = nums.begin(); it != nums.end(); it++) {
    if (found.count(*it) > 0) {
      return true;
    }

    found.insert(*it);
  }

  return false;
}
};
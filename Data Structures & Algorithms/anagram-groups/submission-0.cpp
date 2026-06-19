
class Solution {
public:
  bool isAnagram(string a, string b) {
    if (a.length() != b.length())
      return false;

    int count[26] = {0};

    for (auto it = a.begin(); it != a.end(); it++) {
      count[*it - 'a']++;
    }

    for (auto it = b.begin(); it != b.end(); it++) {
      if (count[*it - 'a'] == 0) {
        return false;
      }

      count[*it - 'a']++;
    }

    return true;
  }

  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> res;

    while (!strs.empty()) {
      string top = strs[strs.size() - 1];
      strs.pop_back();

      vector<string> temp;
      temp.push_back(top);

      int index = 0;
      while (index < strs.size()) {
        if (isAnagram(top, strs[index])) {
          temp.push_back(strs[index]);
          strs.erase(strs.begin() + index);
        } else {
          index++;
        }
      }

      res.push_back(temp);
    }

    return res;
  }
};
class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length())
      return false;

    int count[26];

    for (int i = 0; i < 26; i++) {
      count[i] = 0;
    }

    for (auto it = s.begin(); it != s.end(); it++) {
      count[*it - 'a']++;
    }

    for (auto it = t.begin(); it != t.end(); it++) {
      if (count[*it - 'a'] == 0) {
        return false;
      } else {
        count[*it - 'a']--;
      }
    }

    return true;
  }
};
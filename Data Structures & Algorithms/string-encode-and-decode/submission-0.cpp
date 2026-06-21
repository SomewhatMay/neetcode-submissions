class Solution {
public:
  string encode(vector<string> &strs) {
    string meta = to_string(strs.size()) + "_";
    string combined = "";

    for (string str : strs) {
      meta += to_string(str.length()) + "_";
      combined += str;
    }

    return to_string(meta.size()) + "_" + meta + combined;
  }

  pair<int, int> extr_num(string e, int start) {
    int num = 0, und = 0;

    for (int i = start; i <= e.length(); i++) {
      if (e[i] != '_') {
        num *= 10;
        num += e[i] - '0';
      } else {
        und = i;
        break;
      }
    }

    return {num, und};
  }

  vector<string> decode(string s) {
    vector<string> res;
    pair<int, int> meta_size = extr_num(s, 0);
    pair<int, int> n = extr_num(s, meta_size.second + 1);

    int end_num = n.second, end_str = meta_size.second + meta_size.first;

    for (int i = 0; i < n.first; i++) {
      pair<int, int> cur_size = extr_num(s, end_num + 1);
      res.push_back(s.substr(end_str + 1, cur_size.first));
      end_num = cur_size.second;
      end_str = end_str + cur_size.first;
    }

    return res;
  }
};
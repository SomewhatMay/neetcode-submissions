class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> count;

    for (int n : nums) {
      count[n]++;
    }

    auto custom_comp = [](pair<int, int> a, pair<int, int> b) {
      return a.second < b.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   decltype(custom_comp)>
        ordered{custom_comp};

    for (pair<int, int> x : count) {
      ordered.push(x);
    }

    vector<int> res;
    for (int i = 0; i < k; i++) {
      res.push_back(ordered.top().first);
      ordered.pop();
    }

    return res;
  }
};
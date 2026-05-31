class Solution {
public:
    private:
        priority_queue<pair<double, vector<int>>> pq;

    public:
        vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    eucledian_formula(points);
    vector<vector<int>> result;
    for (int i = points.size(); i > k; i--) {
      pq.pop();
    }
    while (!pq.empty()) {
      result.push_back(pq.top().second);
      pq.pop();
    }
    return result;
  };

  void eucledian_formula(vector<vector<int>> &inputs) {
    for (vector<int> &k : inputs) {
      double r = sqrt(pow(k[0], 2) + pow(k[1], 2));
      pq.push({r, k});
    }
  } 
    
};

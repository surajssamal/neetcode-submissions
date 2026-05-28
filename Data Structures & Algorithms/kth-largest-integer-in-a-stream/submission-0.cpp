class KthLargest {
private:
int k;
public:
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
      pq.push(nums[i]);
      if (pq.size() > k) {
            pq.pop();
      }
        }     
    }
    
    int add(int val) {
   pq.push(val);
    if (pq.size() > k) {
      pq.pop();
    }
    return pq.top();     
    }
};

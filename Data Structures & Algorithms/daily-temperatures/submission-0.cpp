class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& data) {
    vector<int> result(data.size(), 0);
    for (int i = 0; i < data.size(); i++) {
        int counter = 0;
        for (int j = i; j < data.size(); j++) {
        if (data[i] < data[j]) {
            break;
        } else {
            counter += 1;
        }
        counter = (j == data.size() - 1) ? 0 : counter;
        }

        result[i] = counter;
    }
    return result;
    }
    };

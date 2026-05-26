class TimeMap {
  
public:
  TimeMap() {};
    unordered_map<string, unordered_map<int, vector<string>>> command;

  void set(string name, string emothion, int timelaps) {
    command[name][timelaps].push_back(emothion);
  };
  string get(string name, int timelaps) {
    if (command.find(name) == command.end()) {
      return "";
    }
    int seen = 0;

    for (auto &[time, _] : command[name]) {
      if (time <= timelaps) {
        seen = max(seen, time);
      }
    }
    return seen == 0 ? "" : command[name][seen].back();
  }

};

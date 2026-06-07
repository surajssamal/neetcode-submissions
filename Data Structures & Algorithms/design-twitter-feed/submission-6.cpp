class Twitter {
public:
  unordered_map<int, unordered_set<int>> follow_map;
  unordered_map<int, vector<pair<int, int>>> tweet_map;
  int time;
  Twitter() : time(0) {}

  void postTweet(int userId, int tweetId) {
    tweet_map[userId].push_back({time++, tweetId});
  };

  vector<int> getNewsFeed(int userId) {
    vector<pair<int, int>> feed = tweet_map[userId];
    for (int follow : follow_map[userId]) {
      feed.insert(feed.end(), tweet_map[follow].begin(),
                  tweet_map[follow].end());
    }
    sort(feed.begin(), feed.end(),
         [](auto &a, auto &b) { return a.first > b.first; });
    vector<int> res;
    for (int i = 0; i < min(10, (int)feed.size()); i++) {
      res.push_back(feed[i].second);
    }
    return res;
  };

  void follow(int followerId, int followeeId) {
    if (followerId != followeeId) {
      follow_map[followerId].insert(followeeId);
    }
  }

  void unfollow(int followerId, int followeeId) {
    follow_map[followerId].erase(followeeId);
  }
        
    
};

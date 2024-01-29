// Time -> O(tweets) for getNewsFeed, O(1) for remaining operations
// Space -> O(tweets + users + followers)

#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Twitter {
public:
    unordered_map<int, unordered_set<int>> followers;
    vector<pair<int, int>> tweets;

    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> newsFeed;

        for (int i = tweets.size() - 1; i >= 0 && newsFeed.size() < 10; i--) {
            int tweetedBy = tweets[i].first;
            bool isFollowing = followers[userId].find(tweetedBy) != followers[userId].end();
            if (isFollowing || userId == tweetedBy) {
                newsFeed.push_back(tweets[i].second);
            }
        }
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it = followers[followerId].find(followeeId);
        if (it != followers[followerId].end()) {
            followers[followerId].erase(it);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
class Twitter {
public:
    unordered_map<int,unordered_set<int>> follower;
    unordered_map<int,vector<pair<int,int>>> tweet;
    int timer;
    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({timer++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        //users tweet
        for(auto& p:tweet[userId]){
            pq.push(p);
        }
        //user follower tweet
        for(auto& f:follower[userId]){
            for(auto& p1: tweet[f]){
                pq.push(p1);
            }
        }
        vector<int> ans;
        while(!pq.empty() && ans.size() < 10){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId){
            return;
        }
        follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
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
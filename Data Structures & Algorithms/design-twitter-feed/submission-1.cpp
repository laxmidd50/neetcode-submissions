struct Tweet {
    int userId;
    int tweetId;
    int time;
};

struct IteratorPair {
    std::list<Tweet>::iterator cur;
    std::list<Tweet>::iterator end;
};

class Twitter {
public:
    Twitter() {
        m_time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        Tweet tweet{userId, tweetId, m_time++};
        m_tweets[userId].push_front(tweet);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> recentTweets;

        list<IteratorPair> m_list;
        m_list.push_back({m_tweets[userId].begin(), m_tweets[userId].end()});
        for (auto it = m_followers[userId].begin(); it != m_followers[userId].end(); it++)
        {
            if (it->second == true)
            {
                m_list.push_back({m_tweets[it->first].begin(), m_tweets[it->first].end()});
            }
        }

        for (int i = 0; i < 10; i++)
        {

            IteratorPair * m_max = nullptr;
            for (auto it = m_list.begin(); it != m_list.end(); it++)
            {
                if (it->cur != it->end)
                {
                    if (m_max == nullptr || it->cur->time > m_max->cur->time)
                    {
                        m_max = &(*it);
                    }
                }
            }

            if (m_max == nullptr)
                return recentTweets;

            recentTweets.push_back(m_max->cur->tweetId);
            m_max->cur++;
        }

        return recentTweets;
    }
    
    void follow(int followerId, int followeeId) {
        m_followers[followerId][followeeId] = true;
    }
    
    void unfollow(int followerId, int followeeId) {
        m_followers[followerId][followeeId] = false;
    }

private:
    int m_time;
    std::unordered_map<int, unordered_map<int, bool>> m_followers; // user_id -> map of followees
    std::unordered_map<int, list<Tweet>> m_tweets; // user_id -> list of tweets
};

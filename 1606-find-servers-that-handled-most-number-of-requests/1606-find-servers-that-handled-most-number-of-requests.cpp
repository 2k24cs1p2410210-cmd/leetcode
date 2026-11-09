class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> busy;

        vector<int> cnt(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            int t = arrival[i];

            // Release servers that have finished
            while (!busy.empty() && busy.top().first <= t) {
                available.insert(busy.top().second);
                busy.pop();
            }

            if (available.empty()) continue;

            int server = i % k;

            auto it = available.lower_bound(server);

            // Circular search
            if (it == available.end()) {
                it = available.begin();
            }

            server = *it;

            available.erase(it);

            cnt[server]++;

            busy.push({t + load[i], server});
        }

        int maxi = *max_element(cnt.begin(), cnt.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (cnt[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
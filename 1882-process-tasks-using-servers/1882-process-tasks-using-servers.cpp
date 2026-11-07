
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        using pii = pair<int,int>;
        using ti = tuple<long long,int,int>;

        priority_queue<pii, vector<pii>, greater<pii>> free;
        priority_queue<ti, vector<ti>, greater<ti>> busy;

        int n = servers.size();
        int m = tasks.size();

        for(int i = 0; i < n; i++) {
            free.push({servers[i], i});
        }

        vector<int> ans(m);

        long long time = 0;

        for(int i = 0; i < m; i++) {

            time = max(time, (long long)i);

            // Release all servers that have finished
            while(!busy.empty() && get<0>(busy.top()) <= time) {
                auto [finish, weight, idx] = busy.top();
                busy.pop();

                free.push({weight, idx});
            }

            // If all servers are busy, jump to earliest finish time
            if(free.empty()) {
                time = get<0>(busy.top());

                while(!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [finish, weight, idx] = busy.top();
                    busy.pop();

                    free.push({weight, idx});
                }
            }

            // Select minimum weight, then minimum index
            auto [weight, idx] = free.top();
            free.pop();

            ans[i] = idx;

            // Assign task
            busy.push({time + tasks[i], weight, idx});
        }

        return ans;
    }
};

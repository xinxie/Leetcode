/*
 * Priority queue with custom comparator function.
 */


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        vector<int>res;
        for(auto num : nums) dict[num]++;
        auto cmp = [](const pair<int,int>& pair1, const pair<int,int>& pair2) {
            return pair1.first < pair2.first;
        };
        priority_queue<pair<int, int>, std::vector<pair<int,int>>, decltype(cmp)>queue(cmp);
        int size = dict.size();
        for(auto pair : dict){
            queue.push(make_pair(pair.second, pair.first));
            if(queue.size() > size - k) {
                res.push_back(queue.top().second);
                queue.pop();
            }
        }
        return res;
    }
};

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(start > destination)swap(start, destination);
        int left = 0, right = 0;
        for(int i = start; i < destination; ++i)
            left += distance[i];
        for(int i = destination; i != start; ++i, i %= distance.size())
            right += distance[i];
        return min(left, right);
    }
};

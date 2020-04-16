class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int nSize = intervals.size();
        if (nSize == 0) return {};
        // 排序
		sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
		vector<vector<int>> result;
		int left = intervals[0][0];
		int right = intervals[0][1];
        intervals.push_back({INT_MAX, INT_MAX});
		for (int i = 1; i <= nSize; ++i) {
			if (intervals[i][0] > right) {
                //区间不重叠，记录区间
				result.push_back({left, right});
				left = intervals[i][0];
				right = intervals[i][1];
			} else {
                //区间重叠，右移
				right = max(right, intervals[i][1]);
			}
		}
		return result;
    }
};

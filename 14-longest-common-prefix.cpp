class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string max_prestr = "";
		int vct_size = strs.size();
		if (vct_size == 0) return max_prestr;
		size_t min_size = strs[0].length();
		std::for_each(strs.cbegin(), strs.cend(), [&min_size](const string& val)->void {min_size = std::min(val.length(), min_size); });
		if (min_size == 0) return max_prestr;
		// int per_length = 0;
		bool equal = true;
		for (int i = 0; i < min_size; ++i) {
			equal = true;
			for (int j = 1; j < vct_size; ++j) {
				if (strs[0][i] != strs[j][i]) {
					// per_length = i;
					equal = false;
					i = min_size;
					break;
				}
			}
			if (equal) {
				max_prestr.push_back(strs[0][i]);
			}
		}
		// if (equal) {
		// 	max_prestr = strs[0].substr(0, min_size);
		// }
		// else if (per_length > 0) {
		//     max_prestr = strs[0].substr(0, per_length);
		// }
		return max_prestr;
    }
};
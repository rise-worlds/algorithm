class Solution {
public:
    string intToRoman(int num) {
        // vector<pair<int, string>> int_roman = {{1000, "M"}, {900, "CM"}, 
        //                                        {500, "D"}, {400, "CD"}, 
        //                                        {100, "C"}, {90,  "XC"}, 
        //                                        {50,  "L"}, {40,  "XL"}, 
        //                                        {10,  "X"}, {9,   "IX"}, 
        //                                        {5,   "V"}, {4,   "IV"}, 
        //                                        {1,   "I"}, };
        // string temp;
        // auto iter = int_roman.begin();
        // while (iter != int_roman.end() && num > 0) {
        //     if (num >= iter->first) {
        //         temp += iter->second;
        //         num -= iter->first;
        //     } else {
        //         ++iter;
        //     }
        // }
        // return temp;
        vector<int> value = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
		vector<string> dic = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
		string str;
		int i = 0;
		while (num > 0 && i < dic.size()) {
			if (num >= value[i]) {
				str += dic[i];
				num -= value[i];
			}
			else
				i++;
		}
		return str;
    }
};
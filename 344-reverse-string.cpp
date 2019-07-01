class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = -1, j = s.size();
        while (++i < --j) 
        {
            s[i] = s[i] ^ s[j];
            s[j] = s[j] ^ s[i];
            s[i] = s[i] ^ s[j];
        }
    }
    
    //void reverseString(vector<char>& s) {
    //    int i = 0, j = s.size() - 1;
    //    while (i < j) 
    //    {
    //        std::swap(s[i++], s[j--]);
    //    }
    //}
};

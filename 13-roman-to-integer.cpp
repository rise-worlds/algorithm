class Solution {
public:
    int romanToInt(string s) {
        int length = s.length();
        int cur = 0;
        int value = 0, temp = 0;
        while (cur < length) {
            temp = 0;
            parseOne(s, length, cur, temp);
            value += temp;
        }
        return value;
    }
    
private:
    inline void parseOne(string& s, int length, int& start, int& value) {
        char character = s.at(start);
        do {
            if (character == 'M') {
                start++;
                value = 1000;
            } else if (character == 'D') {
                start++;
                value = 500;
            } else if (character == 'C') {
                start++;
                value = 100;
                if (start >= length) break;
                character = s.at(start);
                if (character == 'M') {
                    start++;
                    value = 900;
                } else if (character == 'D') {
                    start++;
                    value = 400;
                }
            } else if (character == 'L') {
                start++;
                value = 50;
            } else if (character == 'X') {
                start++;
                value = 10;
                if (start >= length) break;
                character = s.at(start);
                if (character == 'C') {
                    start++;
                    value = 90;
                } else if (character == 'L') {
                    start++;
                    value = 40;
                }
            } else if (character == 'V') {
                start++;
                value = 5;
            } else if (character == 'I') {
                value = 1;
                start++;
                if (start >= length) break;
                character = s.at(start);
                if (character == 'X') {
                    start++;
                    value = 9;
                } else if (character == 'V') {
                    start++;
                    value = 4;
                } else if (character == 'I') {
                    value = 2;
                    start++;
                    if (start >= length) break;
                    character = s.at(start);
                    if (character == 'I') {
                        start++;
                        value = 3;
                    }
                }
            }
        } while(0);
    }
};
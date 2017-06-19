/*
The problem statement itself is unclear for many. Especially for 2-row case. "ABCD", 2 --> "ACBD". The confusion most likely is from the character placement. I would like to extend it a little bit to make ZigZag easy understood.

The example can be written as follow:

P.......A........H.......N
..A..P....L..S....I...I....G
....Y.........I........R
Therefore, <ABCD, 2> can be arranged as:

A....C
...B....D
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1){
            return s;
        }
        const int len = (int) s.length();
        vector<string> v(numRows, "");
        int row = 0, step = 1;
        for(int i = 0; i < s.length(); ++i){
            v[row].push_back(s[i]);
            if(row == 0){
                step = 1;
            }
            else if(row == numRows - 1) {
                step = -1;
            }
            row += step;
        }
        string result;
        for(const auto& str : v){
            result += str;
        }
        return result;
    }
};

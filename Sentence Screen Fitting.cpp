class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string str = "";
        for(auto word:sentence) str += word + " ";
        int s = 0, len = str.length();

        for(int i = 0; i < rows; ++i) {
            s += cols;
            if(str[s%len] == ' ') s++;
            else {
                while(s>0 && str[(s-1)%len] != ' ' ) s--;
            }
        }
        return s / len;
    }
};

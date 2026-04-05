class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0, i = 0;
        
        while (i < chars.size()) {
            char cur = chars[i];
            int count = 0;
            
            while (i < chars.size() && chars[i] == cur) {
                i++; count++;
            }
            
            chars[write++] = cur;
            
            if (count > 1) {
                string cnt = to_string(count);
                for (char c : cnt)
                    chars[write++] = c;
            }
        }
        
        return write;
    }
};
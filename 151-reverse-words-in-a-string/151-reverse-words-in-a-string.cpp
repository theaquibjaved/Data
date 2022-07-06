class Solution {
public:
    string reverseWords(string str) {
        if(str == "" || str == " ")
    {
        return "";
    }

    string ans;

    int start = str.length() - 1;

    while(start >= 0)
    {
        
        // Skip multiple spaces
        if(str[start] == ' ')
        {
            start--;
        }
        else
        {
            
            // Add space between words
            if(ans.length() > 0)
            {
                ans.push_back(' ');
            }

            int j = start;

            while(j >= 0 && str[j] != ' ')
            {
                j--;
            }

            // add current word to ans
            ans.append(str.substr(j+1, start-j));
            start = j;
        }
    }

    return ans;
    }
};
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len_n=needle.size();
        int len_h=haystack.size();
        int i=0;
        while(i<len_h)
        {
            int j=i;
            if(haystack[i]==needle[0])//first ele match
            {
                string temp=haystack.substr(i,len_n);
                if(temp==needle)//match found
                {
                    return i;
                }
            }
            i++;
        }
        return -1;
    }
};
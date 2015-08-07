class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        for(int i=0;i<length;++i) {
            if(string[i] == ' ') {
                length+=2;
                for(int j=length-1;j>i+2;--j)
                    string[j] = string[j-2];
                string[i] = '%';
                string[i+1] = '2';
                string[i+2] = '0';
            }
        }
        if(length>0) string[length] = '\0';
        return length;
    }
};  

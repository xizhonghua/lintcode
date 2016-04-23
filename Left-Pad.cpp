class StringUtils {
public:
    /**
     * @param originalStr the string we want to append to
     * @param size the target length of the string
     * @param padChar the character to pad to the left side of the string
     * @return a string
     */
    static string leftPad(string& originalStr, int size, char padChar=' ') {
        int pads = size - originalStr.length();
        if(pads <= 0) return originalStr;
        
        return string(pads, padChar) + originalStr;
    }
};

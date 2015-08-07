class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        if(&object == this) return *this;
        delete m_pData;
        m_pData = nullptr;
        if(object.m_pData != nullptr) {
            m_pData = new char[strlen(object.m_pData)];
            strcpy(m_pData, object.m_pData);
        }
    }
};

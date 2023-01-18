// #include "MyNode.h"
#include "UserData.h"

class CMyNode;

class CMyList
{
public:
    CMyList(void);
    ~CMyList(void);

protected:
    void ReleaseList(void);
    CMyNode *m_pHead;

public:
    CMyNode* FindNode(const char* pszKey);
    int AddNewNode(CMyNode *pNewNode);
    void PrintAll(void);
    int RemoveNode(const char* pszKey);
};

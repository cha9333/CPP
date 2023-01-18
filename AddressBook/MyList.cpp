#include <iostream>
#include <ncurses>
#include "MyList.h"
using namespace std;

CMyList::CMyList(void)
{

}

CMyList::~CMyList(void)
{

}

int CMyList::AddNewNode(CMyNode *pNewNode)
{
    if(FindNode(pNewNode->GetKey())!=NULL){
        delete pNewNode;
        
        return 0;
    }
    pNewNode->pNext=m_pHead->pNext;
    m_pHead->pNext=pNewNode;

    return 1;
}

void CMyList::PrintAll(void)
{
    CMyNode *pTmp=m_pHead->pNext;

    while(pTmp!=NULL){
        pTmp->PrintNode();
        pTmp=pTmp->pNext;
    }
    cout << "CUserData Counter : " << CUserData::GetUserDataCounter() << endl;
    _getch();
}

CMyNode* CMyList::FindNode(const char* pszKey)
{


}

int CMyList::RemoveNode(const char*pszKey)
{

}

void CMyList::ReleaseList(void)
{

}
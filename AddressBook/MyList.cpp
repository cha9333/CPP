#include <iostream>
#include <ncurses.h>
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
    getch();
}

CMyNode* CMyList::FindNode(const char* pszKey)
{
	CMyNode *mn;

	return mn;

}

int CMyList::RemoveNode(const char*pszKey)
{
	return 1;
}

void CMyList::ReleaseList(void)
{

}

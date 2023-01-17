#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>

#define DATA_FILE_NAME "Address.dat"

void ReleaseList();

typedef struct _USERDATA
{

    char szName[32];
    char szPhone[32];

    struct _USERDATA *pNext;

} USERDATA;

USERDATA g_Head={0};

USERDATA *FindNode(char *pszName)
{
    USERDATA *pTmp=g_Head.pNext;

    while(pTmp!=NULL){
         if(strcmp(pTmp->szName, pszName)==0) return pTmp;

        pTmp=pTmp->pNext;
    }
    return NULL;
}

int AddNewNode(char *pszName, char *pszPhone)
{
    USERDATA *pNewUser=NULL;

    if(FindNode(pszName)!=NULL){
        printf("FindNode(%s)!=NULL\n", pszName);
        return 0;
    }

    pNewUser=(USERDATA *)malloc(sizeof(USERDATA));
    memset(pNewUser, 0, sizeof(USERDATA));

    snprintf(pNewUser->szName, sizeof(pNewUser->szName), "%s", pszName);
    snprintf(pNewUser->szPhone, sizeof(pNewUser->szPhone), "%s", pszPhone);
    pNewUser->pNext=NULL;

    pNewUser->pNext=g_Head.pNext;
    g_Head.pNext=pNewUser;

    return 1;
}

void Add()
{
    char szName[32]={0};
    char szPhone[32]={0};
#if 0
    printf("InPut Name : ");
    fflush(stdin);
    fgets(szName, sizeof(szName), stdin);

    printf("Input phone number : ");
    fflush(stdin);
    fgets(szPhone, sizeof(szPhone), stdin);
#else
    printf("InPut Name : ");
    scanf("%s", szName);

    printf("Input phone number : ");
    scanf("%s", szPhone);
#endif
    
    AddNewNode(szName, szPhone);
}

void Search()
{
    char szName[32]={0};
    USERDATA *pNode=NULL;

    printf("Input name : ");
    fflush(stdin);
    fgets(szName, sizeof(szName), stdin);

    pNode=FindNode(szName);
    if(pNode!=NULL){
        printf("[%p] %s\t%s [%p]\n", pNode, pNode->szName, pNode->szPhone, pNode->pNext);
    }
    else{
        puts("ERROR: Not find data!\n");
    }
    getch();
}

void PrintAll()
{
    USERDATA *pTmp=g_Head.pNext;

    while(pTmp!=NULL){
         printf("[%p] %s\t%s [%p]\n", pTmp, pTmp->szName, pTmp->szPhone, pTmp->pNext);

        pTmp=pTmp->pNext;
    }
    getch();
}

int RemoveNode(char *pszName)
{
    USERDATA *pPrevNode=&g_Head;
    USERDATA *pDelete=NULL;

    while(pPrevNode->pNext!=NULL){
        pDelete=pPrevNode->pNext;

        if(strcmp(pDelete->szName, pszName)==0){
            pPrevNode->pNext=pDelete->pNext;
            free(pDelete);

            return 1;
        }
        pPrevNode=pPrevNode->pNext;
    }
    return 0;
}

void Remove()
{
    char szName[32]={0};

    printf("InputName : ");
    fflush(stdin);
    fgets(szName, sizeof(szName), stdin);

    RemoveNode(szName);
}

int PrintUI()
{
    int nInput=0;

    // system("clear");
    printf("[1] Add\t [2] Search\t [3] Print all\t [4] Remove\t [0] Exit\n:");

    scanf("%d", &nInput);

    return nInput;
}

int LoadList(char *pszFileName)
{
    FILE *fp=NULL;
    USERDATA user={0};

    fp=fopen(pszFileName, "rb");

    if(fp==NULL) return 0;

    ReleaseList();

    while(fread(&user, sizeof(USERDATA), 1, fp)) AddNewNode(user.szName, user.szPhone);
    
    fclose(fp);

    return 0;
}

int SaveList(char *pszFileName)
{
    FILE *fp=NULL;
    USERDATA *pTmp=g_Head.pNext;

    fp=fopen(pszFileName, "wb");

    if(fp==NULL){
        puts("ERROR: file write error!\n");
        getch();
        
        return 0;
    }

    while(pTmp!=NULL){
        if(fwrite(pTmp, sizeof(USERDATA), 1, fp)!=1)
            printf("ERROR: %s save fail\n", pTmp->szName);

        pTmp=pTmp->pNext;
    }
    fclose(fp);

    return 1;
}

void ReleaseList()
{
    USERDATA *pTmp=g_Head.pNext;
    USERDATA *pDelete=NULL;

    while(pTmp!=NULL){
        pDelete=pTmp;
        pTmp=pTmp->pNext;

        free(pDelete);
    }
    memset(&g_Head, 0, sizeof(USERDATA));
}

void main()
{
    int nMenu=0;

    LoadList(DATA_FILE_NAME);

    while((nMenu=PrintUI()) != 0){
        switch(nMenu){
            case 1: Add();
                    break;

            case 2: Search();
                    break;

            case 3: PrintAll();
                    break;

            case 4: Remove();
                    break;
        }
    }
    SaveList(DATA_FILE_NAME);
    ReleaseList();
}

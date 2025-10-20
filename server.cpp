#include <iostream>
#include "server.h"

using std ::cout;
using std ::endl;

CNode ::CNode()
{
    m_pPrev = NULL;
    m_iData = 0;
    m_pNext = NULL;
}

CNode ::~CNode()
{
    m_pPrev = NULL;
    m_iData = 0;
    m_pNext = NULL;
}

CList ::CList()
{
    m_pHead = NULL;
    m_pTail = NULL;
}

CList ::~CList()
{
    if (m_pHead != NULL)
    {
        DeleteAll();
        m_pHead = NULL;
        m_pTail = NULL;
    }
}

void CList ::InsertAtFirst(int iNo)
{   
    CNode *pNewNode = NULL;
    pNewNode = new CNode;
    if(NULL == pNewNode)
    {
        cout << "Memory Allocation Failed\a\n";
        return;
    }

    pNewNode->m_iData = iNo;

    if(NULL == m_pHead)
    {
        m_pTail = pNewNode;
    }
    else
    {
        pNewNode->m_pNext = m_pHead;
        m_pHead->m_pPrev = pNewNode;
    }
    m_pHead = pNewNode;
    m_pHead->m_pPrev = m_pTail;
    m_pTail->m_pNext = m_pHead;
}

void CList ::InsertAtLast(int iNo)
{
    CNode *pNewNode = NULL;
    pNewNode = new CNode;
    if(NULL == pNewNode)
    {
        cout << "Memory Allocation Failed\n";
        return;
    }

    pNewNode->m_iData = iNo;

    if(NULL == m_pHead)
    {
        m_pHead = pNewNode;
        m_pTail = pNewNode;
        m_pTail->m_pNext = m_pHead;
        m_pHead->m_pPrev = m_pTail;
    }

    m_pTail->m_pNext = pNewNode;
    pNewNode->m_pPrev = m_pTail;
    m_pTail = pNewNode;
    m_pTail->m_pNext = m_pHead;
}

int CList ::DeleteFirst()
{
    if(NULL == m_pHead)
        return -1;

    int iDelData = m_pHead->m_iData;
    
    if(m_pHead == m_pTail)
    {
        m_pHead->m_pPrev = NULL;
        m_pHead->m_pNext = NULL;
        delete(m_pHead);
        m_pHead = NULL;
        m_pTail = NULL;
    }
    else
    {
        m_pHead = m_pHead->m_pNext;
        m_pHead->m_pPrev->m_pNext = NULL;
        m_pHead->m_pPrev->m_pPrev = NULL;
        delete(m_pHead->m_pPrev);
        m_pTail->m_pNext = m_pHead;
    }

    return iDelData;
}

int CList ::DeleteLast()
{
    if(NULL == m_pHead)
        return -1;

    int iDelData = m_pTail->m_iData;
    
    if(m_pHead == m_pTail)
    {
        m_pHead->m_pPrev = NULL;
        m_pHead->m_pNext = NULL;
        delete(m_pHead);
        m_pHead = NULL;
        m_pTail = NULL;
    }
    else
    {
        m_pTail = m_pTail->m_pPrev;
        m_pTail->m_pNext->m_pPrev = NULL;
        m_pTail->m_pNext->m_pNext = NULL;
        delete(m_pTail->m_pNext);
        m_pTail->m_pNext = m_pHead;
    }

    return iDelData;
}
void CList ::InsertAtPosition(int iNo, int iPos)
{
    int iCount = CountNodes();

    if(iPos <= 0 || iPos > iCount + 1)
    {
        cout << "Failed to insert " << iNo << ". Invalid position " << iPos << endl;
        return;
    }

    if(iPos == 1)
    {
        InsertAtFirst(iNo);
        return;
    }

    // if(iPos == iCount + 1)
    // {
    //     InsertAtLast(iNo);
    //     return;
    // }

    CNode *pNewNode = NULL;
    pNewNode = new CNode;

    if(NULL == pNewNode)
    {
        cout << "Memory Allocation Failed\a\n";
        return;
    }

    pNewNode->m_iData = iNo;

    iCount = 1;
    CNode *pTemp = m_pHead;

    while(iCount < iPos - 1)
    {
        iCount ++;
        pTemp = pTemp->m_pNext;
    }

    pNewNode->m_pNext = pTemp->m_pNext;
    if(pTemp == m_pTail)
    {    
        m_pTail = pNewNode;
    }
    pTemp->m_pNext->m_pPrev = pNewNode;
    pTemp->m_pNext = pNewNode;
    pNewNode->m_pPrev = pTemp;

    
}

int CList ::DeleteAtPosition(int iPos)
{
    int iCount = CountNodes();

    if(iPos <= 0 || iPos > iCount)
    {
        cout << " Failed to delete. Invalid Position " << iPos << endl;
        return -1;
    }

    if(iPos == 1)
    {
        return DeleteFirst();
    }

    // if(iPos == iCount + 1)
    //     return DeleteLast();

    iCount = 1;
    CNode *pTemp = m_pHead;

    while(iCount < iPos)
    {
        iCount ++;
        pTemp = pTemp->m_pNext;
    }

    iCount = pTemp->m_iData; 

    if(pTemp == m_pTail)
    {
        m_pTail = pTemp->m_pPrev;
    }
    pTemp->m_pPrev->m_pNext = pTemp->m_pNext;
    pTemp->m_pNext->m_pPrev = pTemp->m_pPrev;

    pTemp->m_pNext = NULL;
    pTemp->m_pPrev = NULL;
    delete(pTemp);
    pTemp = NULL;

    return iCount;
}

int CList ::CountNodes()
{
    int iCount = 0;

    if(NULL == m_pHead);
    else
    {
        CNode *pTemp = m_pHead;
        do
        {
            iCount ++;
            pTemp = pTemp->m_pNext;
        } while (pTemp != m_pHead);
        
    }
    
    return iCount;
}

int CList ::SearchFirstOccurance(int iKey)
{
    int iPos = 1;

    if(NULL == m_pHead)
        ;
    else
    {
        CNode *pTemp = m_pHead;
        do
        {
            if(pTemp->m_iData == iKey)
                return iPos;
            pTemp = pTemp->m_pNext;
            iPos ++;
        } while (pTemp != m_pHead);
    }
    cout << iKey << " not found in the list\n";
    return 0;
   
}

int CList ::SearchLastOccurance(int iKey)
{
    int iPos = 1;
    int iLastPos = 0;

    if(NULL == m_pHead)
        ;
    else
    {
        CNode *pTemp = m_pHead;
        do
        {
            if(pTemp->m_iData == iKey)
                iLastPos = iPos;
            pTemp = pTemp->m_pNext;
            iPos ++;
        } while (pTemp != m_pHead);
    }
    return iLastPos;
}

int CList ::SearchAllOccurances(int iKey)
{
    int iCount = 0;

    if(NULL == m_pHead)
        ;
    else
    {
        CNode *pTemp = m_pHead;
        do
        {
            if(pTemp->m_iData == iKey)
                iCount ++;
            pTemp = pTemp->m_pNext;
        } while (pTemp != m_pHead);
    }
    return iCount;
}

void CList ::ConcatLists(CList &ref)
{
    if(NULL == ref.m_pHead)
        return;

    if((NULL == m_pHead))
    {
        m_pHead = ref.m_pHead;
        m_pTail = ref.m_pTail;
        ref.m_pHead = NULL;
        ref.m_pTail = NULL;
        return;
    }

    m_pTail->m_pNext = ref.m_pHead;
    m_pTail = ref.m_pTail;
    m_pTail->m_pNext = m_pHead;
    ref.m_pHead = NULL;
    ref.m_pTail = NULL;
}

void CList ::ConcatAtPosition(CList &ref, int iPos)
{
    int iCount = CountNodes();

    if(iPos <= 0 || iPos > iCount + 1)
    {
        cout << "Falied to join lists. Invalid Position " << iPos << endl;
        return;
    }

    if(NULL == ref.m_pHead)
        return;
    
    if(iPos == 1)
    {
        m_pHead = ref.m_pHead;
        m_pTail = ref.m_pHead;
        ref.m_pHead = NULL;
        ref.m_pTail = NULL;
        return;
    }

    iCount = 1;
    CNode *pTemp = m_pHead;

    while(iCount < iPos - 1)
    {
        iCount ++;
        pTemp = pTemp->m_pNext;
    }


    pTemp->m_pNext->m_pPrev = ref.m_pTail;
    ref.m_pTail->m_pNext = pTemp->m_pNext;
    pTemp->m_pNext = ref.m_pHead;
    ref.m_pHead->m_pPrev = pTemp;
    if(pTemp = m_pTail)
    {
        m_pTail = ref.m_pTail;
    }
    ref.m_pHead = NULL;
    ref.m_pTail = NULL;
}

void CList ::Display()
{
    if(NULL == m_pHead)
    {
        cout << "List is Empty\n";
        return;
    }

    CNode *pTemp = m_pHead;
    do
    {
        cout << "->|" << pTemp->m_iData << "|<-";
        pTemp = pTemp->m_pNext;
    } while (pTemp != m_pHead);
    
    cout << endl;
}

void CList ::ReverseDisplay()
{
    if(NULL == m_pTail)
    {
        cout << "List is Empty\n";
        return;
    }

    CNode *pTemp = m_pTail;
    do
    {
        cout << "->|" << pTemp->m_iData << "|<-";
        pTemp = pTemp->m_pNext;
    } while (pTemp != m_pTail);
    
    cout << endl;
}

void CList ::PhysicalReverse()
{
    if(NULL == m_pHead || m_pHead == m_pTail)
        return;

    CNode *pCurrent = m_pHead;
    CNode *pNext = NULL;
    m_pHead = m_pTail;
    m_pTail = m_pHead->m_pNext;

    do
    {
        pNext = pCurrent->m_pNext;
        pCurrent->m_pNext = m_pHead;
        pCurrent->m_pPrev = pNext;
        m_pHead = pCurrent;
        pCurrent = pNext;
    } while(pCurrent != m_pTail);

    m_pTail = pCurrent;
}

void CList ::DeleteAll()
{
    if(m_pHead == NULL)
        return;

    m_pTail->m_pNext = NULL;
    CNode *pTemp = NULL;

    while (m_pHead != NULL)
    {
        pTemp = m_pHead;
        m_pHead = m_pHead->m_pNext;
        pTemp->m_pPrev = NULL;
        pTemp->m_pNext = NULL;
        delete(pTemp);
    }
    pTemp = NULL;
    cout << "Successfully deleted\n";
}
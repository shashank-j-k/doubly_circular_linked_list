#pragma once
#include <iostream>

class CList;

class CNode
{
    CNode *m_pPrev;
    int m_iData;
    CNode *m_pNext;

public :
    CNode();
    ~CNode();

    friend class CList;
};

class CList
{
    CNode *m_pHead;
    CNode *m_pTail;

public :
    CList();
    ~CList();
    void InsertAtFirst(int);
    void InsertAtLast(int);
    int DeleteFirst();
    int DeleteLast();
    void InsertAtPosition(int, int);
    int DeleteAtPosition(int);
    int CountNodes();
    int SearchFirstOccurance(int);
    int SearchLastOccurance(int);
    int SearchAllOccurances(int);
    void ConcatLists(CList&);
    void ConcatAtPosition(CList&, int);
    void Display();
    void ReverseDisplay();
    void PhysicalReverse();
    void DeleteAll();
};
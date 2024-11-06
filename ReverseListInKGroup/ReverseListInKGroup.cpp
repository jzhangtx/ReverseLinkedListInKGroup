// ReverseListInKGroup.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode(int data)
        : data(data)
        , next(nullptr)
    {}
};

ListNode* GetListFromInput(ListNode** ppHead, int count)
{
    if (count == 0)
        return nullptr;

    std::cout << "Enter " << count << " numbers of the list: ";
    ListNode* pTail = *ppHead;
    for (int i = 0; i < count; ++i)
    {
        int data = 0;
        std::cin >> data;
        if (*ppHead == nullptr)
        {
            *ppHead = new ListNode(data);
            pTail = *ppHead;
        }
        else
        {
            pTail->next = new ListNode(data);
            pTail = pTail->next;
        }
    }

    return pTail;
}

void PrintList(ListNode* pHead)
{
    if (pHead == nullptr)
        return;

    std::cout << pHead->data;
    pHead = pHead->next;

    while (pHead != nullptr)
    {
        std::cout << ", " << pHead->data;
        pHead = pHead->next;
    }
}

void FreeList(ListNode* pNode)
{
    if (pNode == nullptr)
        return;

    FreeList(pNode->next);
    delete pNode;
}

ListNode* ReverseGroup(ListNode** ppHead, ListNode** ppNextHead, int k)
{
    if (*ppHead == nullptr)
        return nullptr;             // The end of the list, only when the count of non-reversed
                                    //  elements is less than k

    if (k == 1)                     // k is not decremented the first round of the recursive
    {                               //  End of a group
        ListNode* pNode = *ppHead;      // need to return the head. the head's next will be replaced
                                        //  after the list is reversed, so we need to store its next
                                        //  for the next group to use
        *ppNextHead = (*ppHead)->next;
        return pNode;
    }

    ListNode* pHead = *ppHead;
    *ppHead = (*ppHead)->next;
    ListNode* pNext = ReverseGroup(ppHead, ppNextHead, --k);
    if (pNext == nullptr)
        return nullptr;                 // the rest of the elements is not as many as k, should
                                        //  not be reversed

    pNext->next = pHead;
    return pHead;
}

ListNode* ReversLinkedListKGroup(ListNode* head, int k)
{
    ListNode* pHead = head;             // Where the pointer goes, in case of there are less
                                        //  than k elements left to reverse
    ListNode* pNewHead = nullptr;       // The head of reversed group
    ListNode* pCurrentTail = nullptr;   // The end of reversed group

    while (pHead != nullptr)
    {
        ListNode* pNextHead = pHead;    // Store the head in case of there are less than k
                                        //  elements left to reverse
        ListNode* pNode = ReverseGroup(&pHead, &pNextHead, k);
        if (pNewHead == nullptr)
        {                               // The first reversed group
            if (pNode == nullptr)
                pNewHead = pNextHead;   // No enough elements to be reversed
            else
                pNewHead = pHead;
        }
        else
        {                               // Not first reversed group
            if (pHead == nullptr)
                pCurrentTail->next = pNextHead;     // No enough elements to be reversed
            else
                pCurrentTail->next = pHead;         // Connect the non-reversed elements to the end of the new list
        }

        if (pNode == nullptr)           // Has done reversing
            break;

        pCurrentTail = pNode;           // Stores the group tail to use for the next reversed group
        if (pCurrentTail != nullptr)
            pCurrentTail->next = nullptr;
        pHead = pNextHead;
    }

    if (pNewHead == nullptr)
        return head;                    // nothing reversed

    return pNewHead;
}

int main()
{
    while (true)
    {
        int count = 0;
        std::cout << "Number of nodes in list: ";
        std::cin >> count;
        if (count <= 0)
            break;

        ListNode* pHead = nullptr;
        ListNode* pTail = GetListFromInput(&pHead, count);

        std::cout << "The number of elements per group to revers: ";
        int numOfGroup = -1;
        std::cin >> numOfGroup;

        pHead = ReversLinkedListKGroup(pHead, numOfGroup);

        std::cout << "The reversed list: ";
        PrintList(pHead);
        std::cout << std::endl;

        FreeList(pHead);
    }
}

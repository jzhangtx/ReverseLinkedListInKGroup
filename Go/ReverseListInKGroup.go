package main

import "fmt"

type ListNode struct {
	data int
	next *ListNode
}

func GetArrayFromInput(count int, prompt string) []int {
	if count == 0 {
		return []int{}
	}

	fmt.Print(prompt)

	v := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scan(&v[i])
	}

	return v
}

func GetListFromArray(v []int) *ListNode {
	if len(v) == 0 {
		return nil
	}

	if len(v) == 1 {
		return &ListNode{v[0], nil}
	}

	pHead := &ListNode{v[0], nil}
	pCur := pHead
	for i := 1; i < len(v); i++ {
		pCur.next = &ListNode{v[i], nil}
		pCur = pCur.next
	}

	return pHead
}

func (pNode *ListNode) Print() {
	fmt.Print(pNode.data)
	if pNode.next != nil {
		fmt.Print(", ")
		pNode.next.Print()
	} else {
		fmt.Println("")
	}
}

func ReverseList(pHead, pCur *ListNode, count int) (*ListNode, *ListNode) {
	if pCur == nil {
		return pHead, nil
	}

	if count == 0 {
		pHead.next = pCur.next
		return pCur, pCur
	}

	pNewHead, pNode := ReverseList(pHead, pCur.next, count-1)
	if pNode == nil {
		return pNewHead, pNode
	}
	pNode.next = pCur
	return pNewHead, pCur
}

func ReverseLinkedListKGroup(head *ListNode, k int) *ListNode {
	var pNewHead *ListNode = nil
	pStart := head
	for pStart != nil {
		if pNewHead == nil {
			pNewHead, head = ReverseList(head, pStart, k-1)
		} else {
			pNode, _ := ReverseList(pStart, pStart, k-1)
			head.next = pNode
			head = pStart
		}
		if head == nil {
			break
		}
		pStart = head.next
	}

	return pNewHead
}

func main() {
	for {
		fmt.Print("Number of nodes: ")
		var count int
		fmt.Scan(&count)
		if count == 0 {
			break
		}

		vec := GetArrayFromInput(count, "Please enter the list: ")
		pHead := GetListFromArray(vec)

		fmt.Print("The size of the group: ")
		var k int
		fmt.Scan(&k)

		pHead = ReverseLinkedListKGroup(pHead, k)
		fmt.Print("The reversed list: ")
		pHead.Print()
	}
}

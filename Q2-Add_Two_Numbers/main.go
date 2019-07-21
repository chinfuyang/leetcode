package main // package github.com/YangChinFu/leetcode-go/Q2-Add_Two_Numbers

// ListNode definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

// addTwoNumbers
// Runtime: 12ms, faster than 73.65%
// Memory Usage: 5.4MB, less than 5.08%
func addTwoNumbers(l1, l2 *ListNode) *ListNode {
	l1Length, l2Length := getListLength(l1), getListLength(l2)
	carry, sum := 0, 0
	var ansNode []int
	var maxLength int
	if l1Length > l2Length {
		maxLength = l1Length
	} else {
		maxLength = l2Length
	}
	for i := 0; i < maxLength; i++ {
		v1, v2 := 0, 0
		if l1Length > i {
			v1 = l1.Val
			l1 = l1.Next
		}
		if l2Length > i {
			v2 = l2.Val
			l2 = l2.Next
		}
		sum = (v1 + v2 + carry) % 10
		carry = (v1 + v2 + carry) / 10
		ansNode = append(ansNode, sum)
	}
	if carry > 0 {
		ansNode = append(ansNode, carry)
	}
	return newList(ansNode)
}

func getListLength(l *ListNode) int {
	cnt := 0
	for curNode := l; curNode != nil; curNode = curNode.Next {
		cnt++
	}
	return cnt
}

func newList(values []int) *ListNode {
	list := &ListNode{}
	headNode := list
	for _, val := range values {
		newNode := &ListNode{
			Val:  val,
			Next: nil,
		}
		list.Next = newNode
		list = list.Next
	}
	headNode = headNode.Next
	return headNode
}
func main() {
}

package q002

import (
	"fmt"
)

type listnode struct {
	val	int
	next *listnode
}

func addTwoNumbers(l1 *listnode, l2 *listnode) *listnode {
	head := &listnode{0, nil}
	curr := head

	p := l1
	q := l2
	carry := 0
	for p != nil || q != nil {
		pVal := 0
		if p != nil {
			pVal = p.val
		}
		qVal := 0
		if q != nil {
			qVal = q.val
		}

		sum := pVal + qVal + carry
		curr.next = &listnode{sum % 10, nil}
		curr = curr.next
		carry = sum / 10

		if p != nil {
			p = p.next
		}
		if q != nil {
			q = q.next
		}
	}

	if carry > 0 {
		curr.next = &listnode{1, nil}
		curr = curr.next
	}

	return head.next
}

// Test ...
func Test() {
	fmt.Println("2_addTwoNumbers begin")
	
	l13 := listnode {3, nil}
	l12 := listnode {4, &l13}
	l11 := listnode {2, &l12}
	l23 := listnode {7, nil}
	l22 := listnode {6, &l23}
	l21 := listnode {5, &l22}

	l := addTwoNumbers(&l11, &l21)
	for iter := l; iter != nil; iter = iter.next {
		fmt.Printf("%d ", iter.val)
	}
	fmt.Println()
	
	fmt.Println("2_addTwoNumbers end")
}

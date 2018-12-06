package q011

import (
	"fmt"
	"LeetCode/Go/common"
)

func maxArea(a []int) int {
	start := 0
	end := len(a) - 1
	res := (end - start) * common.Min(a[start], a[end])
	for i := start + 1; i < end; i++ {
		if i <= start && i <= end {
			continue
		}

		leftArea := (i - start) * common.Min(a[start], a[i])
		rightArea := (end - i) * common.Min(a[i], a[end])
		if res < common.Max(leftArea, rightArea) {
			res = common.Max(leftArea, rightArea)
		}
	}

	return res
}

// Test ...
func Test() {
	fmt.Println("11_maxArea begin")
	a := []int{1, 8, 6, 2, 5, 4, 8, 3, 7}
	fmt.Println(maxArea(a))
	fmt.Println("11_maxArea end")
}

package q015

import (
	"fmt"
)

func threeSum(a []int) [][]int {
	l := len(a)
	if l < 3 {
		return [][]int{}
	}

	var res [][]int
	for i := 0; i < l - 2; i++ {
		for j := i + 1; j < l - 1; j++ {
			for k := j + 1; k < l; k++ {
				if a[i] + a[j] + a[k] == 0 {
					res = append(res, []int{a[i], a[j], a[k]})
				}
			}
		}
	}

	return res
}

// Test ...
func Test() {
	fmt.Println("15_threeSum begin")
	array := []int{-1, 0, 1, 2, -1, -4}
	fmt.Printf("%v\n", threeSum(array))
	fmt.Println("15_threeSum end")
}

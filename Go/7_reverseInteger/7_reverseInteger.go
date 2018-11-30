package q007

import (
	"fmt"
)

func reverseInteger(val int) int {
	neg := 1
	if val < 0 {
		neg = -1
		val *= neg
	}

	dst := 0
	for val != 0 {
		dst = dst * 10 + val % 10
		val = val / 10
	}

	return dst * neg
}

// Test ...
func Test() {
	fmt.Println("7_reverseInteger begin")
	x := 123
	y := -120
	fmt.Printf("%d: %d\n", x, reverseInteger(x))
	fmt.Printf("%d: %d\n", y, reverseInteger(y))
	fmt.Println("7_reverseInteger end")
}

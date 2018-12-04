package q009

import (
	"fmt"
)

func isPalindrome(val int) bool {
	if val < 0 {
		return false
	}

	reverse := 0
	temp := val
	for ; temp != 0; temp = temp / 10 {
		reverse = reverse * 10 + temp % 10
	}

	if reverse != val {
		return false
	}

	return true
}

// Test ...
func Test() {
	fmt.Println("9_isPalindrome begin")
	x := 121
	y := -121
	fmt.Printf("%d: %v\n", x, isPalindrome(x))
	fmt.Printf("%d: %v\n", y, isPalindrome(y))
	fmt.Println("9_isPalindrome end")
}

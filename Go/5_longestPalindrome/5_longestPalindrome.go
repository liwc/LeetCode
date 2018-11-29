package q005

import (
	"fmt"
)

func longestPalindrome(src string) string {
	dst := ""

	for i := 0; i < len(src); i++ {
		l1 := expandAroundCenter(src, i, i)
		l2 := expandAroundCenter(src, i, i + 1)

		l := l1
		if l2 > l {
			l = l2
		}

		if l > 1 && l > len(dst) {
			start := i - (l - 1) / 2
			dst = src[start : start + l]
		}
	}

	return dst
}

func expandAroundCenter(src string, left, right int) int {
	for left >= 0 && right < len(src) {
		if src[left] != src[right] {
			break
		}

		left--
		right++
	}

	return right - left - 1
}

// Test ...
func Test() {
	fmt.Println("5_longestPalindrome begin")
	str := "abcccabbaabcba"
	fmt.Println(longestPalindrome(str))
	fmt.Println("5_longestPalindrome end")
}

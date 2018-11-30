package q006

import (
	"fmt"
)

func zigZagConversion(src string, row int) string {
	if row == 1 {
		return src
	}

	if row > len(src) {
		row = len(src)
	}

	strs := make([]string, row)
	curr := 0
	godown := true
	for i := 0; i < len(src); i++ {
		strs[curr] += string(src[i])

		if godown {
			curr++
		} else {
			curr--
		}

		if curr == 0 || curr == row - 1 {
			godown = !godown
		}
	}

	dst := ""
	for i := 0; i < len(strs); i++ {
		dst += strs[i]
	}
	return dst
}

// Test ...
func Test() {
	fmt.Println("6_zigZagConversion begin")
	str := "PAYPALISHIRING"
	fmt.Println(zigZagConversion(str, 4))
	fmt.Println("6_zigZagConversion end")
}

package q013

import (
	"fmt"
)

var roman = map[byte]int {
	'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000,
}

func romanToInt(str string) int {
	l := len(str)
	if l == 0 {
		return 0
	}

	sum := roman[str[l - 1]]
	for i := l - 2; i >= 0; i-- {
		if roman[str[i]] < roman[str[i + 1]] {
			sum -= roman[str[i]]
		} else {
			sum += roman[str[i]]
		}
	}

	return sum
}

// Test ...
func Test() {
	fmt.Println("13_romanToInt begin")
	fmt.Printf("III: %d\n", romanToInt("III"))
	fmt.Printf("IV: %d\n", romanToInt("IV"))
	fmt.Printf("IX: %d\n", romanToInt("IX"))
	fmt.Printf("LVIII: %d\n", romanToInt("LVIII"))
	fmt.Printf("MCMXCIV: %d\n", romanToInt("MCMXCIV"))
	fmt.Println("13_romanToInt end")
}

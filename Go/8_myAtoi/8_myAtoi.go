package q008

import (
	"fmt"
)

func myAtoi(str string) int {
	res := 0
	sign := 0

	for i := 0; i < len(str); i++ {
		if str[i] == ' ' {
			if sign != 0 || res != 0 {
				break
			} else {
				continue
			}
		} else if str[i] == '+' || str[i] == '-' {
			if sign != 0 || res != 0 {
				break
			} else {
				sign = 1
				if str[i] == '-' {
					sign = -1
				}
			}
		} else if str[i] < '0' || str[i] > '9' {
			break
		} else {
			if sign == 0 {
				sign = 1
			}
			res = res * 10 + int(str[i] - '0')
		}
	}

	return res * sign
}

// Test ...
func Test() {
	fmt.Println("8_myAtoi begin")
	str1 := "42";
	str2 := "   -42";
	str3 := "4193 with words";
	str4 := "words and 987";
	str5 := "-91283472332";
	fmt.Printf("%s: %d\n", str1, myAtoi(str1))
	fmt.Printf("%s: %d\n", str2, myAtoi(str2))
	fmt.Printf("%s: %d\n", str3, myAtoi(str3))
	fmt.Printf("%s: %d\n", str4, myAtoi(str4))
	fmt.Printf("%s: %d\n", str5, myAtoi(str5))
	fmt.Println("8_myAtoi end")
}

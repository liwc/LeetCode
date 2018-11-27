package main

import (
	"fmt"
)

func twoSum(nums []int, target int) []int {
	// indices := make([]int, 2)

	// numsMap := make(map[int]int)
	// for i := 0; i < len(nums); i++ {
	// 	temp := target - nums[i]
	// 	_, ok := numsMap[temp]
	// 	if ok {
	// 		indices[0] = numsMap[temp]
	// 		indices[1] = i
	// 		break
	// 	}
	// 	numsMap[nums[i]] = i
	// }

	// return indices

	numsMap := make(map[int]int, 0)
	for pos, num := range nums {
		if idx, ok := numsMap[target - num]; ok {
			return []int{idx, pos}
		}

		numsMap[num] = pos
	}

	return nums
}

func main() {
	nums := []int{11, 7, 2, 15}
	fmt.Printf("\nindices: %v\n", twoSum(nums, 9))
	fmt.Println()
}
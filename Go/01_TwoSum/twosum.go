package main

import "fmt"

func twoSum(nums []int, target int) []int {

	maps := map[int]int{}

	for i, v := range nums{
		if mi, ok := maps[target - v]; ok {
			return []int{mi, i}
		}
		maps[v] = i
	}

	return nil
}

func main(){

	//num := []int{2, 7, 11, 12}
	num := []int{2, 7, 11, 12}

	data := twoSum(num, 18)

	fmt.Println(data)
}
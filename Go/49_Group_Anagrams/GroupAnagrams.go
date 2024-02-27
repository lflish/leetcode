package main

import (
	"sort"
	"strings"
)

func genKey(v string) string {
	data := strings.Split(v, "")
	sort.Strings(data)
	return strings.Join(data, "")
}

func groupAnagrams(strs []string) [][]string {
	store := map[string][]string{}
	count := 0

	for _, v := range strs {
		key := genKey(v)

		if list, ok := store[key]; ok {
			list = append(list, v)
			store[key] = list
		}else{
			arr := make([]string, 0, 10)
			arr = append(arr, v)
			store[key] = arr
			count++
		}
	}

	total := make([][]string, count)
	for _,v := range store{
		total = append(total, v)
	}

	return total
}
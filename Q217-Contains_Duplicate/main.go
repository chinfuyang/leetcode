package main

func ContainsDuplicate(nums []int) bool {
	hashMap := map[int]bool{}
	for _, num := range nums {
		if hashMap[num] {
			return true;
		}
		hashMap[num] = true
	}
	return false
}

func main() {

}

package main

// MaxProfit use merge algorithm resolve this problem
// RuntimeL 293 ms, faster than 12.11%
// Memory Usage: 9MB, less than 54.11%
func MaxProfit(prices []int) int {
	min := prices[0]
	max := prices[0]
	maxProfit := 0
	for i := 1; i < len(prices); i++ {
		if prices[i] < min {
			if max-min > maxProfit {
				maxProfit = max - min
			}
			min = prices[i]
			max = prices[i]
		}
		if prices[i] > max {
			max = prices[i]
		}
	}
	if max-min > maxProfit {
		maxProfit = max - min
	}
	return maxProfit
}

// MaxProfit use merge algorithm resolve this problem
// RuntimeL 277 ms, faster than 21.85%
// Memory Usage: 8.8 MB, less than 68.86%
func MaxProfit2(prices []int) int {
	low := 10000
	maxProfit := 0
	for _, price := range prices {
		if price < low {
			low = price
		}
		if maxProfit < price-low {
			maxProfit = price - low
		}
	}
	return maxProfit
}

func main() {
}

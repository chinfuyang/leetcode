# Median of Two Sorted Arrays

## 題目敘述

有兩個排序過的陣列 `nums1` `nums2`，找出兩個陣列中的中位數
且 time complexity 應該要是 `O(log(m+n))`
且保證陣列不會為空

- Example 1

    ```go
        nums1 = [1, 3]
        nums2 = [2]
        the median is 2.0
    ```

- Example 2

    ```go
        nums1 = [1, 2]
        nums2 = [3, 4]
        the median is 2.5
    ```

## 解法

- 內建函數暴力解法 (未達 `O(log(m+n))`)
- 使用簡易的 Merge 解法 (未達 `O(log(m+n))`)

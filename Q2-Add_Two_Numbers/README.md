# Add Two Numbers

## 題目敘述

輸入兩個非空的 linked list 代表非負數的整數。數字會以反向的方式存在 linked list 裡 ( EX: 342 會是 (2 -> 4 -> 3) )
每一個 Node 會有一個 0 ~ 9 的數字。

現在要把兩個數字相加之後回傳一個 linked list。

- Example 1

    ```go
        Input:
            l1 = ( 2 -> 4 -> 3)
            l2 = ( 5 -> 6 -> 4)
        Output:
            ans = ( 7 -> 0 -> 8)
        ans: 342 + 465 = 807
    ```

## 解法

- 加法器

    利用電子電路裡的想法，把每一個數字相加後會有 `sum (S)` 和 `carry (C)`，如果兩個 linked list 都走訪過之後，`C` 不為 0 代表說最後一個位元有進位。

# Jewels and Stones

## 題目敘述

有一個字串 `J` 是所有鑽石的種類，字串 `S` 代表你有的所有石頭。
字串 `S` 裡的每一個字元代表著不同的石頭種類，現在要判斷手裡共有幾個石頭是鑽石。

所有在 `J` 和 `S` 是大小寫區別， `a` 與 `A` 是不相同的。

- Example 1

    ```go
        J = "aA"
        S = "aAAbbbb"
        ans: 3
    ```

- Example 2

    ```go
        J = "z"
        S = "ZZ"
        ans: 0
    ```

## 解法

- map 紀錄
    利用一個 `map` 紀錄 `J` 出現過的字元，之後再透過 for-loop，紀錄 `map` 裡的字元在 `S` 出現過的次數。

# Longest Substring Without Repeating Characters

## 題目敘述

在一字串裡找出最長的子字串長度，但是不包含重複的字元，例如

- `abcabcbb` 長度為 `3`，因為子字串為 `abc`
- `bbbbbbbb` 長度為 `1`，因為子字串為 `b`
- `pwwkew` 長度為 `3`，因為子字串為 `wke`
- `dvdf` 長度為 `3`，因為子字串為 `vdf`

## 暴力破解的想法

想說要找連續的子字串，所以就用兩層 for-loop 來暴力 traversal

## 更好的解法

- 使用 sliding window 搭配 hashmap 解法:
    
    透過紀錄起始位址和結束位置，使用 for-loop 來 traversal 字串，並且使用 hash map 紀錄是否出現過，當有重複出現過的字元時，將此字元以前的出現的字元 map 歸零，並將 begin 移到重複字元之後。

- 使用 substring 解法:

    與 sliding windows 相似，只是不紀錄 hash map，而是改用 `strings.Index` 來找重複的字元位置，找到之後將重複字元位置以前的拋棄。

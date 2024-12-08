# leetcode-learning-tour

This is a note for my leetcoding learning tour.
I will add some algorithm to this file.

## KMP algorithm (子串搜索算法) 

**思路**： 当一次比对失败时，利用已经匹配的那部分信息，将模式串尽可能多地移动到一个合适的位置，使得下一次比对可以从上一次匹配失败的那个位置开始继续进行。

**Example**:
*s*: "ABCABCABE" *p*: "ABCABE"
- 从零开始查找，到第六位时匹配失败。
- 如果从第五位再开始第二轮查找，则后续字符串长度不够，无法完成查找，得出错误结果。
- 则需要注意前后缀
- 注意到前五个组成的字符串具有相同的前后缀**"AB""**
- 即求已匹配的部分串中最长的相同前后缀长度为**next**, 第一对不匹配的字符**index**为**i**.
- 下一轮从**i**，开始比对，但将匹配字符串移至**i - next**处。

**Pesudocode**
```#latex
\(\text{Naive_Next}(next, P):\)

    \(next[0]\leftarrow-1\)

    \(k\leftarrow-1\)

    \(j\leftarrow0\)

    \(\text{WHILE }j\lt \text{Len}(P) \text{ DO}\)

        \(\text{IF }k=-1\text{ OR }P[j]=P[k] \text{ THEN}\)

            \(k\leftarrow k+1\)

            \(j\leftarrow j+1\)

            \(next[j]\leftarrow k\)

        \(\text{ELSE}\)

            \(k\leftarrow next[k]\)

```


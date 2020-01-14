# 回答

バグらせてミスって終わり。。
データ構造が弱い。

```
# maspyさんの回答
import sys
#read = sys.stdin.buffer.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines

N, M = map(int, readline().split())
PS = [line.split() for line in readlines()]

AC = [False] * (N+1)
WA_cnt = [0] * (N+1)

penal = 0
for p,s in PS:
  p = int(p)
  if AC[p]:
    continue
  if s == 'WA':
    WA_cnt[p] += 1
  else:
    AC[p] = True
    penal += WA_cnt[p]

ac = sum(AC)
print(ac, penal)
```

入力の取り扱いが勉強になる。  
なるほどなぁ、AC[p]があるかどうかで既にあればcontinue,  
AC[p]がない時にWAが出た回数を数えておいてACが来た時のみpenalを更新。  
書き方が綺麗・・


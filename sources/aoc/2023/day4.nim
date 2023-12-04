import std/[
  math,
  strutils,
  strformat,
  sequtils,
  sets,
]


type ll = int64

var sum = 0.ll
for line in stdin.lines:
  if line.len == 0:
    continue

  let
    cardStartIdx = line.find(":")
    cardNum = line[0..<cardStartIdx].split(" ")[^1].parseInt

  let seg = line[cardStartIdx+2..^1].split(" | ")
  doAssert seg.len == 2
  let 
    winningNums = seg[0]
      .split(" ")
      .filter(proc(x: string): bool = x.len != 0)
      .map(parseInt)
      .toHashSet
    myNums = seg[1]
      .split(" ")
      .filter(proc(x: string): bool = x.len != 0)
      .map(parseInt)
      .toHashSet

  let winning = (myNums * winningNums)
  let numWinning = winning.len
  let score =
    if numWinning > 0:
      2 ^ (numWinning - 1)
    else:
      0
  sum += score
  # echo fmt"{cardNum}: {score}, win={numWinning}, {winning}"
  # echo fmt"{winningNums} | {myNums}"
echo sum

import std/[
  math,
  strutils,
  strformat,
  sequtils,
  sets,
]


let inp = stdin.lines.toSeq
var cardCounts = newSeq[uint64](inp.len)

for i, line in inp:
  if line.len == 0:
    continue

  let
    cardStartIdx = line.find(":")
    cardNum = line[0..<cardStartIdx].split(" ")[^1].parseInt - 1

  doAssert cardNum == i, fmt"{cardNum}, {i}"
  cardCounts[i] += 1

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
  for j in cardNum+1..cardNum+numWinning:
    cardCounts[j] += cardCounts[i]
  # echo fmt"{cardNum}: {score}, win={numWinning}, {winning}"
  # echo fmt"{winningNums} | {myNums}"
echo cardCounts.sum

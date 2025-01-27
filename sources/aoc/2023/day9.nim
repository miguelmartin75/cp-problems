import std/[
  math,
  strscans,
  strutils,
  algorithm,
  strformat,
  sequtils,
  tables,
  sugar,
  sets,
]


var sum = 0.int64
for line in stdin.readAll().split("\n"):
  if line.len == 0:
    continue

  var 
    curr = line.split(" ").map(parseInt)

  var top = curr[^1].int64
  while true:
    var next: seq[int]
    for i in 1..curr.len-1:
      next.add(curr[i] - curr[i - 1])
    top += next[^1]
    curr = next
    if curr.all(proc (x: int): bool = x == 0):
      break

  sum += top

echo sum

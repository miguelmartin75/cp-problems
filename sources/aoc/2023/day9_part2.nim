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
    hist: seq[seq[int]] = @[curr]

  while true:
    var next: seq[int]
    for i in 1..curr.len-1:
      next.add(curr[i] - curr[i - 1])
    curr = next
    hist.add(curr)
    if curr.all(proc (x: int): bool = x == 0):
      break

  var last = 0.int64
  for i in countdown(hist.len-1, 1):
    let curr = hist[i - 1][0] - last
    # dump hist[i]
    # dump curr
    # dump last
    last = curr

  sum += last
  # echo ""

echo sum

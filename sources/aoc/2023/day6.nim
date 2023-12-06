import std/[
  math,
  strutils,
  strformat,
  sequtils,
  tables,
]

proc empty(s: string): bool =
  return s.strip.len != 0

var inp = stdin.readAll().split("\n")
var time: seq[int]
var dist: seq[int]

time = inp[0].split(":")[1].split(" ").filter(empty).map(parseInt)
dist = inp[1].split(":")[1].split(" ").filter(empty).map(parseInt)
# echo time, dist

var res: int64 = 1
for (t, d) in zip(time, dist):
  # x = button hold time
  # dist_reached = r = 
  #    (t - x) * x
  #
  # Q to answer: how many x's are there where
  #    (t - x)*x > d
  var count = 0
  for x in 1..t-1:
    let r = (t - x) * x
    if r > d:
      count += 1
  res *= count

echo res

import std/[
  math,
  strscans,
  strutils,
  algorithm,
  strformat,
  sequtils,
  tables,
  sets,
]

var
  inp = stdin.readAll().split("\n")
  instructions = inp[0]

var mapInp: Table[string, tuple[left: string, right: string]]

for line in inp[1..^1]:
  if line.len == 0:
    continue

  let x = line.split(" = ")
  var left, right: string
  doAssert scanf(x[1].strip, "($+, $+)", left, right), fmt"input={x[1].strip}"
  # echo left, ",", right
  mapInp[x[0]] = (left, right)


var
  curr: seq[string]
  stepsPerNode: seq[int]

for x in mapInp.keys:
  if x[^1] == 'A':
    curr.add(x)

for c in curr:
  var 
    i = 0
    steps = 0
    c = c

  while true:
    let isRight = instructions[i] == 'R'

    c = if isRight:
      mapInp[c].right
    else:
      mapInp[c].left

    steps += 1
    i += 1
    i = i mod instructions.len
    
    if c[^1] == 'Z':
      if steps >= instructions.len:
        break

  stepsPerNode.add(steps)

var l = stepsPerNode[0]
for i in 1..<stepsPerNode.len:
  l = lcm(l, stepsPerNode[i])
echo l

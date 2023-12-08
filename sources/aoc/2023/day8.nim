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
  doAssert scanf(x[1].strip, "($w, $w)", left, right), fmt"input={x[1].strip}"
  # echo left, ",", right
  mapInp[x[0]] = (left, right)


var 
  i = 0
  steps = 0
  curr = "AAA"

while true:
  doAssert curr in mapInp
  curr = if instructions[i] == 'R':
    mapInp[curr].right
  else:
    doAssert instructions[i] == 'L', fmt"{instructions[i]}"
    mapInp[curr].left

  steps += 1
  i += 1
  i = i mod instructions.len
  if curr == "ZZZ":
    break

echo steps

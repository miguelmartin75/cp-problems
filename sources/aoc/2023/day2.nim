import std/[
  tables,
  strutils
]

type ll = uint64

const constraints = {
  "red": 12,
  "green": 13,
  "blue": 14,
}.toTable

var sum = 0.ll
for line in stdin.lines:
  if line.len == 0:
    continue

  let
    gameStartIdx = line.find(":")
    gameNum = line[0..<gameStartIdx].split(" ")[1].parseInt

  var validGame = true
  for draw in line[gameStartIdx+2..^1].split("; "):
    for cubeDesc in draw.split(", "):
      let 
        cubeDescSplit = cubeDesc.split(" ")
      doAssert cubeDescSplit.len == 2, $cubeDescSplit

      let
        (numStr, colour) = (cubeDescSplit[0], cubeDescSplit[1])
        num = numStr.parseInt

      doAssert colour in constraints
      if num > constraints[colour]:
        validGame = false
        break
    if not validGame:
      break
  if validGame:
    sum += gameNum.ll

echo sum

import std/[
  tables,
  strutils
]

type ll = uint64


var sum = 0.ll
for line in stdin.lines:
  if line.len == 0:
    continue


  let
    gameStartIdx = line.find(":")
    gameNum = line[0..<gameStartIdx].split(" ")[1].parseInt

  var
    gameMinCubes = {
      "red": 0,
      "green": 0,
      "blue": 0,
    }.toTable

  var validGame = true
  for draw in line[gameStartIdx+2..^1].split("; "):
    for cubeDesc in draw.split(", "):
      let 
        cubeDescSplit = cubeDesc.split(" ")
      doAssert cubeDescSplit.len == 2, $cubeDescSplit

      let
        (numStr, colour) = (cubeDescSplit[0], cubeDescSplit[1])
        num = numStr.parseInt

      doAssert colour in gameMinCubes
      gameMinCubes[colour] = max(gameMinCubes[colour], num)

  let power = gameMinCubes["red"] * gameMinCubes["green"] * gameMinCubes["blue"]
  # echo gameNum, ": ", power, " (", gameMinCubes, ")"
  sum += power.ll

echo sum

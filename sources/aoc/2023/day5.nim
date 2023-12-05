import std/[
  math,
  strutils,
  strformat,
  sequtils,
  tables,
]

proc empty(s: string): bool =
  return s.len != 0

const mapNamesInOrder = [
  "seed-to-soil",
   "soil-to-fertilizer",
   "fertilizer-to-water",
   "water-to-light",
   "light-to-temperature",
   "temperature-to-humidity",
   "humidity-to-location"
]

type GardenMap = tuple[descStart: int, sourceStart: int, rangeLen: int]

var inp = stdin.readAll().split("\n")

var seeds: seq[int] = @[]
var gardenMaps: Table[string, seq[GardenMap]]

var i = 0
while i < inp.len:
  let line = inp[i]
  if line.len == 0:
    i += 1
    continue

  let
    startIdx = line.find(":")
    desc = line[0..<startIdx].split(" ")[0].strip
    lineRest = line[startIdx+1..^1]

  case desc:
    of "seeds":
      seeds = lineRest.split(" ").filter(empty).map(parseInt)
    of mapNamesInOrder:
      i += 1
      gardenMaps[desc] = @[]
      while i < inp.len:
        if inp[i].len == 0:
          break
        # NOTE: could use scanf
        let lineNums = inp[i].split(" ").filter(empty).map(parseInt)
        doAssert lineNums.len == 3, $lineNums

        let
          descStart: int = lineNums[0]
          sourceStart: int = lineNums[1]
          rangeLen: int = lineNums[2]

        gardenMaps[desc].add((descStart, sourceStart, rangeLen))
        i += 1
    else:
      doAssert false, "invalid"

  i += 1

proc mapGardenThing(src: int, maps: openArray[GardenMap]): int =
  for map in maps:
    if src >= map.sourceStart and src < map.sourceStart + map.rangeLen:
      return map.descStart + (src - map.sourceStart)
  return src


var minRes = int64.high
for seed in seeds:
  var curr = seed
  # echo "seed ", curr
  for mapName in mapNamesInOrder:
    curr = mapGardenThing(curr, gardenMaps[mapName])
    # echo mapName, ": ", curr

  minRes = min(curr, minRes)

echo minRes

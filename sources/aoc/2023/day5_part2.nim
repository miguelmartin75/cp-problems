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

var seeds: seq[int]

var gardenMaps: Table[string, seq[GardenMap]]

var inp = stdin.readAll().split("\n")

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
      let seedRanges = lineRest.split(" ").filter(empty).map(parseInt)
      doAssert seedRanges.len %% 2 == 0
      for i in countup(1, seedRanges.len - 1, 2):
        let
          start = seedRanges[i - 1]
          rangeLen = seedRanges[i]
        for j in 0..<rangeLen:
          seeds.add(start + j)
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

proc mapGardenThing(src: int, maps: openArray[GardenMap]): int {.inline.} =
  for map in maps:
    if src >= map.sourceStart and src < map.sourceStart + map.rangeLen:
      return map.descStart + (src - map.sourceStart)
  return src


echo "seeds.len= ", seeds.len

var mapsInOrder: seq[seq[GardenMap]]
for mapName in mapNamesInOrder:
  mapsInOrder.add(gardenMaps[mapName])


var minRes = int64.high
for i, seed in seeds:
  var curr = seed
  for map in mapsInOrder:
    curr = mapGardenThing(curr, map)
  minRes = min(curr, minRes)
  if i %% 100_000_000 == 0:
    echo 100 * ((i + 1).float64 / seeds.len.float64)

echo minRes

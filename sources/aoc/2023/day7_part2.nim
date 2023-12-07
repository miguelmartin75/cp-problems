import std/[
  math,
  strutils,
  algorithm,
  strformat,
  sequtils,
  tables,
  sets,
]

type HandType = enum 
  FiveKind
  FourKind
  FullHouse
  ThreeKind
  TwoPair
  OnePair
  HighCard

const CardValues = {
  'A': 14,
  'K': 13,
  'Q': 12,
  'J': 1,
  'T': 10,
  '9': 9,
  '8': 8,
  '7': 7,
  '6': 6,
  '5': 5,
  '4': 4,
  '3': 3,
  '2':  2
}.toTable

proc computeHand(s: string): HandType =
  var counts: Table[char, int]
  var maxCount = 0
  for ch in s:
    if ch notin counts:
      counts[ch] = 0

    counts[ch] += 1
    if ch != 'J':
      maxCount = max(maxCount, counts[ch])

  var numUniqCards = counts.len
  if 'J' in counts:
    maxCount += counts['J']
    numUniqCards -= 1
  
  case maxCount:
    of 5:
      return FiveKind
    of 4:
      return FourKind
    of 3:
      if numUniqCards == 2:
        return FullHouse
      else:
        return ThreeKind
    of 2:
      if numUniqCards == 3:
        return TwoPair
      else:
        return OnePair
    of 1:
      return HighCard
    else:
      doAssert false, fmt"counts={counts}, maxCount={maxCount}"


type Hand = tuple
  hand: string
  bid: int
  handType: HandType

var inp = stdin.readAll()

var hands: seq[Hand]
for line in inp.split("\n"):
  if line.len == 0:
    continue

  let 
    handData = line.split(" ")
    hand = handData[0]
    bid = handData[1].parseInt
    handType = computeHand(hand)

  hands.add((hand, bid, handType))

hands.sort(cmp=proc(x: Hand, y: Hand): int =
  if x.handType == y.handType:
    for i in 0..<x.hand.len:
      let 
        v1 = CardValues[x.hand[i]]
        v2 = CardValues[y.hand[i]]
      if v1 == v2:
        continue
      return cmp(v1, v2)
    return 0
  else:
    -cmp(x.handType, y.handType)
)

var res: int64
for i, h in hands:
  let rank = i + 1
  res += rank * h.bid

echo res

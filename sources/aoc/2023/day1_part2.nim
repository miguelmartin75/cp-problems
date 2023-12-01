import std/strutils

type ll = uint64

const digitNames = [
  ('1', "one"),
  ('2', "two"),
  ('3', "three"),
  ('4', "four"),
  ('5', "five"),
  ('6', "six"),
  ('7', "seven"),
  ('8', "eight"),
  ('9', "nine"),
]

var sum = 0.ll
for line in stdin.lines:
  var first: char
  var last: char
  for i, ch in line:
    if ch.isDigit:
      if first == 0.char:
        first = ch
      last = ch
    else:
      # is it a spelled char?
      for (ch, name) in digitNames:
        if i + name.len > line.len:
          continue
        # echo line[i..<i+name.len], " == ", name
        if line[i..<i + name.len] == name:
          if first == 0.char:
            first = ch
          last = ch
          break
  doAssert first != 0.char and last != 0.char
  let num = (first.ll - '0'.ll) * 10 + (last.ll - '0'.ll)
  # echo first, " ", last
  # echo line, ": ", num
  sum += num
echo sum

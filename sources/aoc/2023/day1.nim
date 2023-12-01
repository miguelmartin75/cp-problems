import std/strutils

type ll = uint64

var sum = 0.ll
for line in stdin.lines:
  var first: char
  var last: char
  for ch in line:
    if ch.isDigit:
      if first == 0.char:
        first = ch
      last = ch
  let num = (first.ll - '0'.ll) * 10 + (last.ll - '0'.ll)
  # debugEcho line, ": ", num
  sum += num
echo sum

import std/[
  strutils,
  strformat
]

type Node = tuple[line_i: int, s: int, e: int]

var graph = stdin.readAll().split("\n")
if graph[^1].len == 0:
  graph = graph[0..^2]

iterator numbersInGraph(graph: seq[string]): Node =
  for i, line in graph:
    var j = 0
    while j < line.len:
      var s = j
      while s < line.len:
        if line[s].isDigit:
          break
        s += 1

      var e = s
      while e < line.len:
        if not line[e].isDigit:
          break
        e += 1

      j = e + 1
      if s == e:
        continue
      e -= 1
      # echo fmt"{s}: {e}: {line[s..e]}"
      yield (i, s, e)

iterator kids(n: Node): Node =
  for line_offset in [-1, 0, 1]:
    let line_i = n.line_i + line_offset
    if line_i < 0 or line_i >= graph.len:
      continue

    # above/below
    if line_offset != 0:
      for i in n.s..n.e:
        yield (line_i, i, i)

    # left
    if n.s - 1 >= 0:
      yield (line_i, n.s - 1, n.s - 1)

    # right
    if n.e + 1 < graph[line_i].len:
      yield (line_i, n.e + 1, n.e + 1)

proc text(n: Node): string =
  doAssert n.line_i >= 0 and n.line_i < graph.len, fmt"line idx invalid: {n}, num_lines={graph.len}"
  doAssert n.s >= 0 and n.e < graph[n.line_i].len, fmt"substr invalid: {n}, line len={graph[n.line_i].len}"
  return graph[n.line_i][n.s..n.e]


var sum = 0.int64

for node in numbersInGraph(graph):
  var valid = false
  for kid in node.kids:
    if kid.text != ".":
      valid = true
      break

  if valid:
    let num = node.text.parseInt
    sum += num.int64

echo sum

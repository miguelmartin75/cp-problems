import std/[
  strutils,
  strformat,
  sets,
  sequtils,
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

proc text(n: Node): string =
  doAssert n.line_i >= 0 and n.line_i < graph.len, fmt"line idx invalid: {n}, num_lines={graph.len}"
  doAssert n.s >= 0 and n.e < graph[n.line_i].len, fmt"substr invalid: {n}, line len={graph[n.line_i].len}"
  return graph[n.line_i][n.s..n.e]


var nodes_by_line: seq[seq[Node]] = @[]

for _ in 1..graph.len:
  nodes_by_line.add(@[])
doAssert nodes_by_line.len > 0, fmt"nodes_by_line: {nodes_by_line.len}"

for node in numbersInGraph(graph):
  doAssert node.line_i >= 0 and node.line_i < nodes_by_line.len, fmt"{node}, num lines={nodes_by_line.len}"
  nodes_by_line[node.line_i].add(node)

var sum = 0.int64

for line_i, line in graph:
  for col_j, ch in line:
    if ch != '*':
      continue

    var connected = initHashSet[Node]()
    for kid_i in -1..1:
      for kid_j in -1..1:
        let line = line_i + kid_i
        let col = col_j + kid_j
        if line < 0 or line >= nodes_by_line.len or 
           col < 0 or col >= graph[line].len:
          continue

        for node in nodes_by_line[line]:
          if col >= node.s and col <= node.e:
            connected.incl(node)
    
    if len(connected) != 2:
      continue

    let conn = connected.items.toSeq
    let ratio = conn[0].text.parseInt * conn[1].text.parseInt
    sum += ratio

echo sum

import std/[
  math,
  strscans,
  strutils,
  algorithm,
  strformat,
  sequtils,
  tables,
  sugar,
  sets,
]


proc empty(s: string): bool =
  return s.strip.len != 0

var inp = stdin.readAll().split("\n")
for i in 0..<inp.len:
  echo i

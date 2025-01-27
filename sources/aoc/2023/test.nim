import std/[
  math,
  strscans,
  strutils,
  algorithm,
  strformat,
  sequtils,
  tables,
  sets,
  sugar,
]



# macro foo = 

var curr = collect:
  for i in 1..100:
    i

var myMap = collect:
  for i in 1..100:
    {i: 10000*i}

for c in curr.mitems:
  c = if c mod 2 == 0:
    myMap[c] * 2
  else:
    (myMap[c] div 3) - 1

template myTemp(): untyped =
  type Result  = object
    x: int
    y: int
  Result

# macro myMacro(arg: static[typedesc]): untyped =
#   echo arg
  # echo arg # just an int (7), not `NimNode`

# type x = Foo

type Foo = myTemp()

let x = Foo(x:10)
echo x
# myMacro(1 + 2 * 3)

# bug in Nim?
# for c in curr.mitems:
#   # doAssert c in mapInp
#   echo "hi"
#   echo "c=", c, " -> "
#   let temp = if isRight:
#     mapInp[c].right
#   else:
#     mapInp[c].left
#   # c = if isRight:
#   #   mapInp[temp].right
#   # else:
#   #   mapInp[temp].left
#   c = temp

# iterator myIter(x: int): int {.closure.} =
#   for i in 1..x:
#     yield i
# 
# type 
#   Vector2 = object
#     x: int
#     y: int
# 
# # let x = 30
# # 
# # let vec = (x: 100, y: 500)
# # dump x * 50
# # dump vec
# 
# let x = myIter
# dump x

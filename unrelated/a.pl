f x
= (x + 1) * (x - 1)

###
$ pl about f
f x
x:
x + 1 -> T1
x - 1 -> T2
constraints:
T1 * T2 -> T3
returns T3
###

prefsum a ps
sum := a 1
for i : 1..a.size:
    ps i = sum
    sum += a i


###
$ pl about prefsum
prefsum a ps
a:
.size -> Int; > 1
1 -> T1
i:Int; 1 >= i >= a.size -> T1
ps:
i:Int; 1 >= i >= a.size -> mutable T1
constraints:
T1 + T1 -> T1
returns nothing
###

###
$ pl about prefsum Int[] Int[]
prefsum a ps
a: Int[]
ps: Int[]
returns nothing
###

###
$ pl about prefsum . Int[]
prefsum a ps
a:
.size -> Int; > 1
1 -> Int
i:Int; 1 >= i >= a.size -> Int
ps: Int[]
returns nothing
###


###
$ pl about prefsum Int[] .
prefsum a ps
a: Int[]
ps:
i:Int; 1 >= i >= a.size -> mutable Int
returns nothing
###

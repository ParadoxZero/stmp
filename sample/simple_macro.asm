
first MACRO arg1 arg2
add(arg1,arg2)
cmd(arg2,arg1)
MEND

sum MACRO a b
a=a+b
MEND

START

first one two
lol code
first three four
nice try
sum 13 4
END

add_and_check MACRO arg1 arg2
add(arg1,arg2)
check(arg2,arg1)
MEND

sum MACRO a b
a=a+b
MEND

test_function(a,b){
    add_and_check a b
    sum a b
}
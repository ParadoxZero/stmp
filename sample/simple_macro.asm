
add_and_check MACRO arg1 arg2
add(arg1,arg2);
check(arg2,arg1);
MEND

sum MACRO a b
a=a+b;
MEND

void test_function(int a, int b){
    int c=5;
    add_and_check a b
    sum c b
    return c;
}
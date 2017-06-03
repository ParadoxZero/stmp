
create_size_function MACRO name type
type name () {
    return sizeof(type);
}
MEND

create_print_function MACRO name format_str type
void name ( type x ) {
    printf( format_str , x );
}
MEND

create_size_function getDoubleSize double
create_size_function getIntSize int
create_print_function printDouble "%lf" double
create_print_function printInt "%d" int
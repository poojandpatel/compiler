/* token types */
#define UNDEF 0
#define T_INT 1
#define T_BOOL 2
#define T_FUNCTION 3

int typeChecking(int type1, int type2);
void type_error();

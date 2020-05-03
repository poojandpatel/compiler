#include <stdbool.h>
/* max_size of hashtable to store vars identified by the parser */
#define SIZE 199

/* max_size of token identifiers. we will use 31 as thats what C uses */
#define MAX_TOKEN_LEN 31

/* token types */
#define TYPE_UNDEF 0
#define TYPE_INT 1
#define TYPE_BOOL 2
#define TYPE_FUNCTION 3

/* this is for functions and thier parameters*/

#define BY_VALUE 1
#define BY_REFER_2

typedef struct Param {
  int type;
  char name[MAX_TOKEN_LEN];
  int int_val; // param could be an int
  bool bool_val; // param could be a bool
  int passing; // pass by value or reference
}Param;

/* we will use a linkedlist of references for each variable */

typedef struct RefList {
  int lineno;
  struct RefList* next;
  int type;
}RefList;

typedef struct list_t {
  char st_name[MAX_TOKEN_LEN];
  int st_size;
  int scope;
  RefList *lines;
  int st_ival;
  bool st_bval;
  int st_type;
  int inf_type;
  // function parameter
  Param *params;
  int num_params;
  struct list_t* next;
}list_t;

static list_t **hash_table;

//function declarations for hashtable
void init_hashtable();
unsigned int hash(char* key); // hash function
void insert(char* name, int len, int type, int lineno);
list_t *lookup(char *name);
list_t *lookup_scope(char *name, int scope);
void hide_scope();
void dump(FILE* of);

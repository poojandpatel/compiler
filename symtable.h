#include <stdbool.h>
/* max_size of hashtable to store vars identified by the parser */
#define SIZE 199

/* max_size of token identifiers. we will use 31 as thats what C uses */
#define MAX_TOKEN_LEN 31

/* this is for functions and thier parameters*/

typedef union Value {
  int int_val;
  int bool_val;
} Value;

typedef struct Param {
  int type;
  char name[MAX_TOKEN_LEN];
  Value val;
}Param;

/* we will use a linkedlist of references for each variable */

typedef struct RefList {
  int lineno;
  struct RefList* next;
  int type;
}RefList;

typedef struct list_t {
  char st_name[MAX_TOKEN_LEN]; // name
  int st_size; //size
  int scope; // is it main or function var
  RefList *lines; //lines where the variable shows up
  Value val;
  int st_type;
  int inf_type;
  // function parameter
  Param *params; // not using yet
  int num_params; // not using yet
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

void set_type(char *name, int type, int inf_type);
int get_type(char* name);

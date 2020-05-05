typedef enum NodeType {
  ROOT_N, //root
  DECL_N, // declare new var
  CONST_N, // const vals: int or bools
  ASSIGN_N,
  IF_N,
  WHILE_N,
  FOR_N,
  KEYWORD_N, // "main" "end" "do" "else"
  MATH_N,
  BOOLOP_N,
  COMPARE_N,
  FUNCTION_N,
}NodeType;

typedef enum Math_op {
  ADD_OP, SUB_OP, MULT_OP, DIV_OP
} Math_op;

typedef enum Bool_op {
  AND_OP, OR_OP, XOR_OP
} Bool_op;

typedef enum Cmp_op {
  EQ_OP, NOTEQ_OP, GT_OP, LT_OP, GEQ_OP, LEQ_OP
} Cmp_op;


/* AST NODE */
typedef struct AST_NODE {
  enum NodeType type;     // type
  struct AST_NODE *l;  // l
  struct AST_NODE *r; // r
} AST_NODE;

/* Declaration Node */
typedef struct AST_NODE_DECL {
  enum NodeType type;
  int dataType;
  list_t* name;
} AST_NODE_DECL;

/* Constant Node */
typedef struct AST_NODE_CONST {
  enum NodeType type;
  int constType;
  Value val;
} AST_NODE_CONST;

/* Assign Node */
typedef struct AST_NODE_ASSIGN {
  enum NodeType type;
  list_t* entry;
  struct AST_NODE *assignment;
} AST_NODE_ASSIGN;

typedef struct AST_NODE_IF {
  enum NodeType type;
  // if condition
  struct AST_NODE* condition;

  //if branch
    struct AST_NODE* if_stmts;
  // else branch: optional
    struct AST_NODE* else_stmts;
}AST_NODE_IF;

typedef struct AST_NODE_WHILE {
  enum NodeType type;
  // if condition
  struct AST_NODE* condition;

  //if branch
    struct AST_NODE* while_stmts;
}AST_NODE_WHILE;

typedef struct AST_NODE_FOR {
  enum NodeType type;
  // condition
  struct AST_NODE* initialize;
  struct AST_NODE* condition;
  struct AST_NODE* increment;

  //for branch
  struct AST_NODE* for_stmts;

}AST_NODE_FOR;

/* Keyword Node */
typedef struct AST_NODE_KEYWORD{
  enum NodeType type;
  int keyword;
} AST_NODE_KEYWORD;

typedef struct AST_NODE_MATH{
  enum NodeType type;
  enum Math_op op;
  struct AST_NODE *l;  // l
  struct AST_NODE *r; // r
} AST_NODE_MATH;

typedef struct AST_NODE_BOOLOP{
  enum NodeType type;
  enum Bool_op op;
  struct AST_NODE *l;  // l
  struct AST_NODE *r; // r
} AST_NODE_BOOLOP;

typedef struct AST_NODE_COMPARE{
  enum NodeType type;
  enum Cmp_op op;
  struct AST_NODE *l;  // l
  struct AST_NODE *r; // r
} AST_NODE_COMPARE;

/* node functions */
AST_NODE *new_ast_node(NodeType type, AST_NODE *l, AST_NODE *r);

// new vardecls
AST_NODE *new_ast_decl(int dataType, list_t** names, int names_count);
AST_NODE *new_cnst_decl(int constType, Value val);

// statments
AST_NODE *new_ast_assign(list_t* entry, AST_NODE *assignVal);
AST_NODE *new_ast_if(AST_NODE* condition, AST_NODE* if_stmts, AST_NODE* else_stmts);
AST_NODE *new_ast_for(AST_NODE* init, AST_NODE* condition, AST_NODE* incr, AST_NODE* for_stmts);
AST_NODE *new_ast_while(AST_NODE* conditon, AST_NODE* while_stmts);
AST_NODE *new_ast_keyword(int keyword_type);

AST_NODE *new_ast_math(enum Math_op op, AST_NODE *l, AST_NODE *r);
AST_NODE *new_ast_bool(enum Bool_op op, AST_NODE *l, AST_NODE *r);
AST_NODE *new_ast_cmp(enum Cmp_op op, AST_NODE *l, AST_NODE *r);

void printTree(AST_NODE *root);
void traverse(AST_NODE *root);

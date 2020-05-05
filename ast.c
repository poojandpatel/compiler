#include <stdio.h>
#include <stdlib.h>
#include <string.h>

AST_NODE *new_ast_node(NodeType type, AST_NODE *l, AST_NODE *r){
  AST_NODE *n = malloc(sizeof(AST_NODE));
  n->type = type;
  n->l = l;
  n->r = r;
  return n;
}

AST_NODE *new_ast_decl(int dataType, list_t* name){
  AST_NODE_DECL * n = malloc(sizeof(AST_NODE_DECL));
  n->type = DECL_N;
  n->dataType = dataType;
  n->name = name;
  return (struct AST_NODE*) n;
}

AST_NODE *new_cnst_decl(int constType, Value val){
  AST_NODE_CONST *n = malloc(sizeof(AST_NODE_CONST));
  n->type = CONST_N;
  n->constType = constType;
  n->val = val;

  return (struct AST_NODE*) n;
}

AST_NODE *new_ast_assign(list_t* entry, AST_NODE *assignVal){
  AST_NODE_ASSIGN *n = malloc(sizeof(AST_NODE_ASSIGN));

  n->type = ASSIGN_N;
  n->entry = entry;
  n->assignment = assignVal;

  return (struct AST_NODE*) n;
}

AST_NODE *new_ast_if(AST_NODE* condition, AST_NODE* if_stmts, AST_NODE* else_stmts){
  AST_NODE_IF *n = malloc(sizeof(AST_NODE_IF));
  n->type = IF_N;
  n->condition = condition;
  n->if_stmts = if_stmts;
  n->else_stmts = else_stmts;

  return (struct AST_NODE*) n;
}

AST_NODE *new_ast_for(AST_NODE* init, AST_NODE* condition, AST_NODE* incr, AST_NODE* for_stmts){
  AST_NODE_FOR *n = malloc(sizeof(AST_NODE_FOR));
  n->type = FOR_N;
  n->initialize = init;
  n->condition = condition;
  n->increment = incr;
  n->for_stmts = for_stmts;

  return (struct AST_NODE*) n;
}

AST_NODE *new_ast_while(AST_NODE* conditon, AST_NODE* while_stmts){
  AST_NODE_WHILE *n = malloc(sizeof(AST_NODE_WHILE));
  n->type = WHILE_N;
  n->condition = conditon;
  n->while_stmts = while_stmts;

  return (struct AST_NODE*) n;
}

AST_NODE *new_ast_keyword(int keyword_type){
  AST_NODE_KEYWORD *n = malloc(sizeof(AST_NODE_KEYWORD));
  n->type = KEYWORD_N;
  n->keyword = keyword_type;

  return (struct AST_NODE*) n;
}

AST_NODE *new_ast_math(enum Math_op op, AST_NODE *l, AST_NODE *r){
  AST_NODE_MATH *n = malloc(sizeof(AST_NODE_MATH));
  n->type = MATH_N;
  n->op = op;
  n->l = l;
  n->r = r;
  return (struct AST_NODE*) n;
}
AST_NODE *new_ast_bool(enum Bool_op op, AST_NODE *l, AST_NODE *r){
  AST_NODE_BOOLOP *n = malloc(sizeof(AST_NODE_BOOLOP));
  n->type = BOOLOP_N;
  n->op = op;
  n->l = l;
  n->r = r;
  return (struct AST_NODE*) n;

}
AST_NODE *new_ast_cmp(enum Cmp_op op, AST_NODE *l, AST_NODE *r){
  AST_NODE_COMPARE *n = malloc(sizeof(AST_NODE_COMPARE));
  n->type = COMPARE_N;
  n->op = op;
  n->l = l;
  n->r = r;
  return (struct AST_NODE*) n;
}

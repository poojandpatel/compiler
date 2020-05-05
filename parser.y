%{
  #include <stdio.h>
  #include "symtable.c"
  #include "semantics.c"
  #include "ast.h"
  #include "ast.c"
  #include <stdlib.h>
  #include <string.h>
  #include <stdbool.h>
  extern FILE *yyin;
  extern FILE *yyout;
  extern int lineno;
  extern int yylex();
  void yyerror();

  void add_vars(list_t* v);
  list_t* var;
  int size = 0;
%}

/* union */
%union {
  Value val;
  list_t* symboltab_item;
  AST_NODE* node;
  int data_type;
  int const_type;
  char other;
}

/* token definitions */
%token <symboltab_item> ID
%token <val> ICONST
%token <val> BCONST
%token <other> INT BOOL MAIN
%token <other> NOTOP ADDOP SUBOP MULOP DIVOP
%token <other> LPAREN RPAREN ASSIGN SEMI COLON
%token <other> FUNC_DECL END PRINT COMMA RETURN
%token <other> FOR WHILE IF ELSE DO
%token <other> AND OR XOR LT GT EQ NOT_EQ LEQ GEQ

/* precedencies and associativities */
%left LPAREN
%right NOTOP
%left MULOP DIVOP
%left ADDOP SUBOP
%left LT GT LEQ GEQ
%left NOT_EQ EQ
%left AND
%left OR XOR
%right ASSIGN

%type <node> vardecls vardecl
%type <data_type> type
%type <symboltab_item> id assign
%type <const_type> const

%start program

%%

program: main;

main: FUNC_DECL MAIN vardecls stmts END;

vardecls: vardecl SEMI vardecls
        | /* nothing */
        ;

vardecl: type id {
  int i;
  $$ = new_ast_decl($1, var);
  size = 0;
  AST_NODE_DECL *temp = (AST_NODE_DECL*) $$;
  if(var->st_type == T_UNDEF)
  {
    set_type(var->st_name, var->data_type, T_UNDEF);
  }
};

type: INT   {$$ = T_INT;}
    | BOOL  {$$ = T_BOOL;}
    ;

stmts: stmt SEMI stmts
     | stmt SEMI
     ;

stmt: assign
    | print
    | while
    | if
    | for
    | return
    ;

assign: id ASSIGN expr
{
  AST_NODE_CONST *n = (AST_NODE_CONST* ) $$;
  $1->val = n->val;
  $1->constType = n->constType;
  $$ = $1;
};

print: PRINT LPAREN id RPAREN ;

while: WHILE LPAREN expr RPAREN DO stmts END;

if: IF LPAREN expr RPAREN DO stmts END
  | IF LPAREN expr RPAREN DO stmts ELSE stmts END
  ;

for: FOR LPAREN stmt SEMI expr SEMI stmt RPAREN DO stmts END;

expr: expr binop expr
    | NOTOP expr
    | id LPAREN args RPAREN
    | id
    | const
    | LPAREN expr RPAREN
    ;

args: someArgs
    |
    ;

someArgs: expr moreArgs;

moreArgs: COMMA someArgs
        |
        ;

return: RETURN expr;

id: ID {$$=$1;};

const: ICONST {$$ = new_cnst_decl(T_INT, $1);}
     | BCONST {$$ = new_cnst_decl(T_BOOL, $1);}
     ;

binop: ADDOP
     | SUBOP
     | MULOP
     | DIVOP
     | AND
     | OR
     | XOR
     | NOT_EQ
     | EQ
     | LT
     | GT
     | LEQ
     | GEQ
     ;
%%

void yyerror(){
  fprintf(stderr, "syntax error\n");
}

void add_vars(list_t* v){
  if(size == 0){
    size++;
    var = v;
  }
}

int main(int argc, char *argv[]){
  init_hashtable(); //symbol table
  int flag;
  yyin = fopen(argv[1], "r");
  flag = yyparse();
  fclose(yyin);

  yyout = fopen("dump.out", "w");
  symtab_dump(yyout);
  fclose(yyout);

  return flag;
}

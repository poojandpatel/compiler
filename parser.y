%{
  #include <stdio.h>
  #include "symtable.c"
  #include <stdlib.h>
  #include <string.h>
  #include <stdbool.h>
  extern FILE *yyin;
  extern FILE *yyout;
  extern int lineno;
  extern int yylex();
  void yyerror();
%}

/* union */
%union {
  int int_val;
  int bool_val;
  list_t* symboltab_item;
  char other;
}

/* token definitions */
%token <symboltab_item> ID
%token <int_val> ICONST
%token <bool_val> BCONST
%token <other> INT BOOL MAIN
%token <other> NOTOP ADDOP SUBOP MULOP DIVOP
%token <other> LPAREN RPAREN ASSIGN SEMI COLON
%token <other> FUNC_DECL END PRINT COMMA RETURN
%token <other> FOR WHILE IF ELSE DO
%token <other> AND OR XOR NOT_EQ EQ LT GT LEQ GEQ

%start program

%%

program: main;

main: FUNC_DECL MAIN vardecls stmts END;

vardecls: vardecl SEMI vardecls
        | /* nothing */
        ;

vardecl: type id ;

type: INT
    | BOOL
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

assign: id ASSIGN expr ;

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

id: ID {printf("label found: %s\n", yylval.symboltab_item->st_name);};

const: ICONST {printf("int found: %d\n", yylval.int_val);}
     | BCONST {printf("bool found: %d\n", yylval.bool_val);}
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


int main(int argc, char *argv[]){
  init_hashtable();
  //parsing
  int flag;
  yyin = fopen(argv[1], "r");
  flag = yyparse();
  fclose(yyin);

  yyout = fopen("dump.out", "w");
  symtab_dump(yyout);
  fclose(yyout);

  return flag;
}

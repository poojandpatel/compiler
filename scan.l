%option noyywrap

%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "symtable.h"
  #include "semantics.h"
  #include "ast.h"
  #include "parser.tab.h"
  int lineno = 1;
  extern FILE *yyin;
  extern FILE *yyout;
  void ret_print(char* token_type) {printf("found: %s\n", token_type);};
  void yyerror();
%}

alpha [a-zA-Z]
digit [0-9]
alnum {alpha}|{digit}
print [ -~]

ID      {alpha}+{alnum}*
ICONST  {digit}+


%%
"def"     { return FUNC_DECL; }
"main"    { ret_print("found main"); return MAIN; }
"return"  { return RETURN; }
","       { return COMMA; }
"int"     { return INT; }
"bool"    { return BOOL; }
"print"   { return PRINT; }
"end"     { return END; }

"for"     { return FOR; }
"while"   { return WHILE;}
"if"      { return IF; }
"else"    { return ELSE; }
"do"      { return DO; }

"("       { return LPAREN; }
")"       { return RPAREN; }
"="       { return ASSIGN; }
";"       { return SEMI; }
":"       { return COLON; }

"+"       { return ADDOP; }
"-"       { return SUBOP; }
"*"       { return MULOP; }
"/"       { return DIVOP; }
"!"       { return NOTOP; }

"&&"     { return AND; }
"|"      { return OR; }
"^"      { return XOR; }
"!="     { return NOT_EQ; }
"=="     { return EQ; }
"<"      { return LT; }
">"      { return GT; }
"<="     { return LEQ; }
">="     { return GEQ; }



{ICONST}   { yylval.val.int_val = atoi(yytext); return ICONST; }

"true"    {
            yylval.val.bool_val = 1;
             return BCONST;
          }

"false"    {
            yylval.val.bool_val = 0;
            return BCONST;
          }

{ID}      {
              insert(yytext, strlen(yytext), UNDEF, lineno);
              yylval.symboltab_item = lookup(yytext);
              return ID;
          }


"\n"       { lineno += 1; }

[ \t\r\f]+     /* delete whitespace */

.         { yyerror("unrecognized character\n"); }
%%

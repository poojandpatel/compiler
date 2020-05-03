/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     ICONST = 259,
     BCONST = 260,
     INT = 261,
     BOOL = 262,
     MAIN = 263,
     NOTOP = 264,
     ADDOP = 265,
     SUBOP = 266,
     MULOP = 267,
     DIVOP = 268,
     LPAREN = 269,
     RPAREN = 270,
     ASSIGN = 271,
     SEMI = 272,
     COLON = 273,
     FUNC_DECL = 274,
     END = 275,
     PRINT = 276,
     COMMA = 277,
     RETURN = 278,
     FOR = 279,
     WHILE = 280,
     IF = 281,
     ELSE = 282,
     DO = 283,
     AND = 284,
     OR = 285,
     XOR = 286,
     NOT_EQ = 287,
     EQ = 288,
     LT = 289,
     GT = 290,
     LEQ = 291,
     GEQ = 292
   };
#endif
/* Tokens.  */
#define ID 258
#define ICONST 259
#define BCONST 260
#define INT 261
#define BOOL 262
#define MAIN 263
#define NOTOP 264
#define ADDOP 265
#define SUBOP 266
#define MULOP 267
#define DIVOP 268
#define LPAREN 269
#define RPAREN 270
#define ASSIGN 271
#define SEMI 272
#define COLON 273
#define FUNC_DECL 274
#define END 275
#define PRINT 276
#define COMMA 277
#define RETURN 278
#define FOR 279
#define WHILE 280
#define IF 281
#define ELSE 282
#define DO 283
#define AND 284
#define OR 285
#define XOR 286
#define NOT_EQ 287
#define EQ 288
#define LT 289
#define GT 290
#define LEQ 291
#define GEQ 292




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 15 "parser.y"
{
  int int_val;
  int bool_val;
  list_t* symboltab_item;
  char other;
}
/* Line 1529 of yacc.c.  */
#line 130 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


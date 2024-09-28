%{
#include<stdio.h>

#include"symbolTable.h"
symbolTable table;
symbolInfo info;
extern int linenum;
extern FILE *yyin, *yyout;

int yylex();

void yyerror (const char *str)
{
    fprintf(yyout,"error : %s\n",str);
}

%}

%union{
double dvar;
char *cvar;
}

%token CONST_INT CONST_FLOAT CONST_CHAR <cvar>ID <cvar>KEYWORD INCOP RELOP NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD SEMICOLON  
%left  COMMA LOGICOP ADDOP MULOP
%right ASSIGNOP 

%%

mul_stmt: mul_stmt func_decl                        
| func_decl                                         
;

func_decl: type_spec term LPAREN RPAREN LCURL stmt RCURL                { fprintf(yyout,"Line Number: %d\n func_decl: type_spec term LPAREN RPAREN LCURL stmt RCURL\n",linenum); }
;

stmt: stmt unit                                                         { fprintf(yyout,"Line Number: %d\n stmt: stmt unit\n",linenum); }
| unit                                                                  { fprintf(yyout,"Line Number: %d\n stmt: unit\n",linenum); } 
;

unit: var_decl                                                          { fprintf(yyout,"Line Number: %d\n unit: var_decl\n",linenum); }
| expr_decl                                                             { fprintf(yyout,"Line Number: %d\n unit: expr_decl\n",linenum);}
| error         	                                                    { yyerrok;}
;

var_decl: type_spec decl_list SEMICOLON                                 { fprintf(yyout,"Line Number: %d\n var_decl: type_spec decl_list SEMICOLON\n",linenum); }
;

type_spec: KEYWORD                                                      { fprintf(yyout,"Line Number: %d\n type_spec: %s\n",linenum,$1);}
;

decl_list: decl_list COMMA term                                         { fprintf(yyout,"Line Number: %d\n decl_list: decl_list COMMA term\n",linenum); }
| decl_list COMMA term LTHIRD CONST_INT RTHIRD                          { fprintf(yyout,"Line Number: %d\n decl_list: decl_list COMMA term LTHIRD CONST_INT RTHIRD\n",linenum); }
| term                                                                  { fprintf(yyout,"Line Number: %d\n decl_list: term\n",linenum); }
| term LTHIRD CONST_INT RTHIRD                                          { fprintf(yyout,"Line Number: %d\n decl_list: term LTHIRD CONST_INT RTHIRD\n",linenum); }
| ass_list                                                              { fprintf(yyout,"Line Number: %d\n decl_list: ass_list\n",linenum); }
;

ass_list: term ASSIGNOP expr                                            { fprintf(yyout,"Line Number: %d\n ass_list: term ASSIGNOP expr\n",linenum); }
;

expr: CONST_INT                                                         { fprintf(yyout,"Line Number: %d\n expr: CONST_INT\n",linenum); }
| CONST_FLOAT                                                           { fprintf(yyout,"Line Number: %d\n expr: CONST_FLOAT\n",linenum); }
| CONST_CHAR                                                            { fprintf(yyout,"Line Number: %d\n expr: CONST_CHAR\n",linenum); }
| expr ADDOP expr                                                       { fprintf(yyout,"Line Number: %d\n expr: expr ADDOP expr\n",linenum); }
| expr MULOP expr                                                       { fprintf(yyout,"Line Number: %d\n expr: expr MULOP expr\n",linenum); }
| LPAREN expr RPAREN	                                                { fprintf(yyout,"Line Number: %d\n expr: LPAREN expr RPAREN\n",linenum); }
| expr LOGICOP expr	                                                    { fprintf(yyout,"Line Number: %d\n expr: expr LOGICOP expr\n",linenum);}
| term                                                                  { fprintf(yyout,"Line Number: %d\n expr: term\n",linenum); }
;

term: ID                                                                { 
					                                                    if(table.looksymbol($1)!=1){fprintf(yyout,"Line Number: %d\n term: ID\n",linenum);info.setsymbolName($1); info.setsymbolType("identifier"); table.insertsymbol(info);}
                                  	                                    else{fprintf(yyout,"%s is already declared.\n",$1);}
                                                                         }
;

expr_decl: term ASSIGNOP expr SEMICOLON                                 { fprintf(yyout,"Line Number: %d\n expr_decl: term ASSIGNOP expr SEMICOLON\n",linenum); }
;


%%

int main()
{
    yyin=fopen("sample_input.txt","r");
    yyout=fopen("log_error.txt","w");
    yyparse();
    table.printsymbol();
}
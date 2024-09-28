
%option noyywrap
%{
    #include "parser.tab.h"
    int linenum=1; 
%}

keyword      "return"|"int"|"char"|"float"|"double"|"void"
digit        [0-9]
identifier   [a-zA-Z_]+
ADDOP         "+"|"-"
const_int    {digit}+
const_float  {digit}*["."]?{digit}+([eE][-+]?{digit}+)?
const_char   '[^\\0]'
MULOP         "*"|"/"|"%"
INCOP         "++"|"--"
RELOP         "<"|"<="|">"|">="|"=="|"!="
ASSIGNOP      "="
LOGICOP       "&&"|"||"
NOT           "!"
LPAREN        "("
RPAREN        ")"
LCURL         "{"
RCURL         "}"
LTHIRD        "["
RTHIRD        "]"
COMMA         ","
SEMICOLON     ";"
WS            [ \t]+


%%

{keyword}       {  yylval.cvar=yytext; return KEYWORD; }
{const_int}     {  return CONST_INT; }
{const_float}   {  return CONST_FLOAT; }
{const_char}    {  return CONST_CHAR; }
{identifier}    {  yylval.cvar=yytext; return ID; }
{ADDOP}         {  return ADDOP; }
{MULOP}         {  return MULOP; }
{INCOP}         {  return INCOP; }
{RELOP}         {  return RELOP; }
{ASSIGNOP}      {  return ASSIGNOP; }
{LOGICOP}       {  return LOGICOP; }
{NOT}           {  return NOT; }
{LPAREN}        {  return LPAREN; }
{RPAREN}        {  return RPAREN; }
{LCURL}         {  return LCURL; }
{RCURL}         {  return RCURL; }
{LTHIRD}        {  return LTHIRD; }
{RTHIRD}        {  return RTHIRD; }
{COMMA}         {  return COMMA; }
{SEMICOLON}     {  return SEMICOLON; }
{WS}            {  }
[\n]            { linenum++;}
.               {}

%%

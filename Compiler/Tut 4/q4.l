%{
#include <stdlib.h>
void yyerror(char *);
#include "y.tab.h"
%}
%%
[0-9]+      {
                yylval = atoi(yytext);
                return digit;
            }
[+*()\n]      return *yytext;
[ \t]       ; /* skip whitespace */
.           yyerror("invalid character");
%%
int yywrap(void) {
    return 1;
}


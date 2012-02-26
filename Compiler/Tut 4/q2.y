%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(char *);
%}
%token bool or and not
%%
program	:
        program E '\n'       {  if ($2) {printf("true\n");}
				else {printf("false\n");}}
	|
        ;
E	:	
	not E 	 	{ $$ = (int)(1- $2); }
	|E or T	{ $$ = (int)($1||$3);}
	|T
	;
T	:
	T and F		{ $$ = (int)($1 && $3); }
	| F
	;
F	:
	'(' E ')' 		{ $$ = $2;}
	| bool               	{ $$ = $1; }
        ;
%%
void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}
int main(void) {
    yyparse();
    return 0;
}


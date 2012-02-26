%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(char *);
%}
%token digit
%%
program	:
        program E '\n'       { printf("%d\n", $2); }
        |
        ;
E	:	
	E '+' T   	{ $$ = $1 + $3; }
	|T
	;
T	:
	T '*' F		{ $$ = $1 * $3; }
	| F
	;
F	:
	'(' E ')' 		{ $$ = $2;}
	| digit               { $$ = $1; }
        ;
%%
void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}
int main(void) {
    yyparse();
    return 0;
}


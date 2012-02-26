%{
    #include <stdio.h>
    int yylex(void);
    void yyerror(char *);
%}
%token digit
%%
program	:
        program E '\n'       { printf("\n"); }
        |
        ;
E	:	
	E '+' T   	{ printf("E -> E + T\n"); }
	|T		{ printf("E -> T\n"); }
	;
T	:
	T '*' F		{ printf("T -> T * F\n"); }
	| F		{ printf("T -> F\n"); }
	;
F	:
	'(' E ')' 	{ printf("F -> (E)\n"); }
	| digit         { printf("F -> %d\n",$1); }
        ;
%%
void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}
int main(void) {
    yyparse();
    return 0;
}


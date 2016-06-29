#include "vwsl_token.h"
#include "vwsl_ast.h"
#include "y.tab.h"
#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <string.h>
#include <stdio.h>
#include <time.h>

extern int column;
extern FILE *yyin;
extern int yyparse();
extern void yyerror(const char* s);
extern SegmentAST* ProgramHead;

using namespace std;

int main(int argc, char *argv[]) {
	char terminal[80] = "cat ";
	yyin = fopen(argv[1], "r");
	printf("------------------------------------------\n");
	printf("INPUT FILE: \"%s\"\n", argv[1]);
	printf("------------------------------------------\n");
	strcat(terminal, argv[1]);
	system(terminal);
	printf("------------------------------------------\n");
	printf("THROUGH yyparse():\n");
	printf("------------------------------------------\n");
	if(!yyparse())
		printf("====> %s compile completely!\n", argv[1]);
	printf("------------------------------------------\n");
	printf("========AST Begin========\n");
    ProgramHead->print(0);        
    printf("========AST End========\n");
	return 0;
}

void yyerror(const char* s){
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

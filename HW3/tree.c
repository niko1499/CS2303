//tree.c Niko Gamarra
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include "tree.h"

//global variables that keep records during recursive calls
int distinctWords = 0;
int totalWords = 0;

//local to tree.c helper functions
int isWhitespace(char ch);
int isPunctuation(char ch);

treeItem *TreeAdd(treeItem *p, char *w) {
	if (p == NULL) {
		p = malloc(sizeof(treeItem));
		char *c = malloc(strlen(w) + 1);
		p->word = strcpy(c, w);
		p->count = 1;
		p->left = p->right = NULL;
		return p;
	};
	int c = strcmp(w, p->word);

	if (c == 0)
		p->count++;
	else if (c < 0)
		p->left = TreeAdd(p->left, w);
	else
		p->right = TreeAdd(p->right, w);
	return p;
}
//k&r tree print
void TreePrint(treeItem *p) {
	if (p != NULL) {
		TreePrint(p->left);
		printf("%4d %s\n", p->count, p->word);
		TreePrint(p->right);
	}
} //end TreePrint
void TreePrintFile(FILE *fp, treeItem *p) {
	if (fp == NULL) {
		exit(-1);
	}
	if (p != NULL) {
		TreePrintFile(fp, p->left);
		fprintf(fp, "%4d %s\n", p->count, p->word);
		TreePrintFile(fp, p->right);
	}
} //end TreePrintFile
int TreeDistinctWords(treeItem *p) {
	if (p != NULL) {
		TreeDistinctWords(p->left);
		distinctWords++;
		TreeDistinctWords(p->right);
	}
	return distinctWords;
}
int TreeTotalWords(treeItem *p) {
	if (p != NULL) {
		TreeDistinctWords(p->left);
		totalWords += p->count;
		TreeDistinctWords(p->right);
	}
	return distinctWords;
}
void resetGlobalVariables(void) {
	totalWords = 0;
	distinctWords = 0;
}
treeItem *FileToTree(FILE *input, treeItem *tree, int i, char* argv[]) {
	printf("Pulling words from %s\n", argv[i]);
	const int buff_size = 1024;
	char buff[buff_size];

	while (fscanf(input, " %1023s", buff) == 1) {
		char* word = buff;
		int size = strlen(word); //Note does not include null term

		//Have word start a char later if begins with punct
		if (isPunctuation(word[0])) {
			word++;
			size--;
		}

		//Replace last char with null term if punct
		if (isPunctuation(word[size - 1])) {
			word[size - 1] = '\0';
			size--;
		}

		//Copy to new buff as lowercase
		char finalWord[size + 1];
		for (int x = 0; x < size; x++) {
			finalWord[x] = tolower(word[x]);
			//Loop invariant: at this point the x letters in finalWord are guarenteeded to be lower case
		}
		finalWord[size] = '\0';
		if (!isWhitespace(finalWord[0]) && !isPunctuation(finalWord[0])) {
			tree = TreeAdd(tree, finalWord);
			totalWords++;
		}
	}
	printf("Done\n");
	return tree;
}

void TreeToFile(treeItem *tree, FILE *output, int argc, char *argv[]) {
	printf("Creating %s\n", argv[1]);
	fprintf(output, "PA3 Output File\n");
	fprintf(output, "Output File: %s\n", argv[1]);
	for (int i = 2; i < argc; i++) {
		fprintf(output, "Input File %d: %s\n", i - 1, argv[i]);
		//Loop invariant: at this point the current tree item will have been added to the file as a new line
	}
	fprintf(output, "----------------------------------\n");
	fprintf(output, "Unique Words and their frequencies: \n");
	TreePrintFile(output, tree);
	fprintf(output, "----------------------------------\n");
	int words = TreeDistinctWords(tree);
	fprintf(output, "Distinct Words: %d\n", words);
	words = totalWords;
	fprintf(output, "Total Words: %d\n", words);
	printf("Done\n");
}		//end of TreeToFile
int isWhitespace(char ch) {
	const int types = 5;
	const char white[5] = { ' ', '\n', '\t', '\v', '\r' };
	for (int i = 0; i < types; i++) {
		if (ch == white[i])
			return 1;
		//Loop invariant: at this point the ch character will not have been the character that is currently being checked
	}
	return 0;
}		//end of isWhitespace
int isPunctuation(char ch) {
	const int types = 16;
	const char punct[16] = { '.', ',', '?', '-', ';', ':', '(', ')', '[', ']',
			'!', '\"', '\'' };
	for (int i = 0; i < types; i++) {
		if (ch == punct[i])
			return 1;
		//Loop invariant: at this point the ch character will no have been the character that is currently being checked
	}
	return 0;
}		//end of isPunctuation


//seed.c -- Niko Gamarra
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "tree.h"

int main(int argc, char * argv[]) {
	treeItem *tree = NULL;
	if (argc < 3) { //make sure there are an ok amount of arguements
		printf(
				"ERROR: Too few args.\nExpected./PA3 outputFile inputFile1 inputFile2 ...\n");
		return 1;
	} else if (argc > 7) {
		printf(
				"ERROR: Too many args.\nExpected./PA3 outputFile inputFile1 inputFile2 ...\n");
		return 1;
	} else { //Here all arguments have been accepted: Proceed

		char *outName = argv[1];
		FILE *input;
		for (int i = 2; i < argc; i++) { //loop inputs
			char *inName = argv[i];
			input = fopen(inName, "r");
			if (!input) {
				printf("ERROR: File not found.\ncd CS2303"
						"");
				return 1;
			} else {
				tree = FileToTree(input, tree, i, argv); //put file in tree
			}
			//Loop invariant: At this point the file of index i in the arguments has been added to the tree.
		}
		fclose(input);

		FILE *output;
		output = fopen(outName, "w");
		TreeToFile(tree, output, argc, argv); //put tree into output file
		fclose(output);
	}
	return 0;
} //end of main


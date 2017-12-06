//tree.h -- Niko Gamarra

#ifndef TREE_H
#define TREE_H


//our tree struct data structure allows us to makea binary tree
struct TreeItem {
	char *word;
// part of payload
	int count;
// part of payload
	struct TreeItem *left, *right;
};

typedef struct TreeItem treeItem;

// functions of tree.c that need to be called by main.
treeItem *TreeFind(treeItem *p, char *w);
treeItem *TreeAdd(treeItem *p, char *w);
void TreePrint(treeItem *p);
void TreePrintFile(FILE *fp, treeItem *p);
int TreeDistinctWords(treeItem *p);
int TreeTotalWords(treeItem *p);
treeItem *FileToTree(FILE *input, treeItem *tree,int i, char* argv[]);
void TreeToFile(treeItem *tree, FILE *output, int argc, char *argv[]);


#endif

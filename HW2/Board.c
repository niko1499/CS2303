//Board.c Niko Gamarra
#include <stdio.h>

void PrintBoard(int width, int height, char **Board) {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			printf("%c", Board[x][y]);
		}
		printf("\n");
	}
}
void PrintGenHeader(int width,int gen) {
	int printed=printf("--- Generation %d ",gen);

	 for (int i = 0; i < (width - printed); i++) {
	 printf("-");
	 }
	printf("\n");
}
int BoardsEqual(int width, int height, char **BoardA, char **BoardB) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (BoardA[i][j] != BoardB[i][j])
				return 0;
		}
	}
	return 1;
}
int allDead(int x, int y, char **array) {
	for (int i; i < x; i++) {
		for (int j; j < y; j++) {
			if (array[i][j] == 'x') {
				return 1;
			}
		}
	}
	return 0;
}
void ZeroBoard(int x, int y, char **Board) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			Board[i][j] = '*';
		}
	}
}
void CopyBoard(int width,int height,char **Cloned,char **Copy){
	for (int x=0; x<width;x++){
		for(int y =0; y<height;y++){
			Copy[x][y]=Cloned[x][y];
		}
	}
}
int EmptyCell(int x, int y,char **Array){
	char temp = Array[x][y];
	if(temp=='0'||temp=='o'||temp=='*')
		return 1;

	return 0;
}

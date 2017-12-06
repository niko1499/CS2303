//triangle.c -- Niko Gamarra
#include <stdio.h>
#include <math.h>
int main(void){
	//set up variables
	int aX=0, aY=0;
	int bX=0, bY=0;
	int cX=0, cY=0;
	double ab;
	double bc;
	double ca;
	double cir;
	double s;
	double area;
	int square(int);

	//prompt user for input
	printf("Welcome to triangle program!\n");
	printf("Enter the x and y coordinates of pt A: ");
	scanf("%d %d", &aX, &aY);
	printf("Enter the x and y coordinates of pt B: ");
	scanf("%d %d", &bX, &bY);
	printf("Enter the x and y coordinates of pt C: ");
	scanf("%d %d", &cX, &cY);

	//calculate result
	ab=sqrt(square(aX-bX)+square(aY-bY));
	bc=sqrt(square(bX-cX)+square(bY-cY));
	ca=sqrt(square(cX-aX)+square(cY-aY));
	cir=ab+bc+ca;
	s=cir/2;
	area=sqrt(s*(s-ab)*(s-bc)*(s-ca));

	//display result
	printf("Length of AB = %0.2f\n",ab);
	printf("Length of BC = %0.2f\n",bc);
	printf("Length of CA = %0.2f\n",ca);
	printf("Circumference = %0.2f\n",cir);
	printf("Area = %0.2f\n",area);
	return 0;
}//int main(void)

int square(int b){
	int z;
	z=b*b;
	return(z);
}//float square(float)


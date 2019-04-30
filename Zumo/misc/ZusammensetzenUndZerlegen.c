#include <stdio.h>
#include <math.h>

int main(void)
{
    int l, r, w;
    float u, v, x;
    
    printf("What is l?\n");
    scanf("%d", &l);
    printf("And what is r?\n");
    scanf("%d", &r);
    printf("\nSo you have l = %d and r = %d!\n", l, r);

	u = 10 * l + r;
	printf("\nThat's %.f if putted together.\n", u);

	v = u / 10;
	printf("\nFirst step of taking apart: %1.1f\n", v);

	w = abs(v);
	printf("\nSecond step of taking apart: %d\n", w);

	x = (v - abs(v)) * 10;
	printf("\nLast step of taking apart: %1.f\n", x);
	
    return 0;
}

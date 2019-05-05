/*-----------------------------------------------------------------------------
Um die beiden ProxySens-Werte, von 1 - 5, in einem Parameter übertragen zu
können, shifte und ver"oder" ich sie, um sie zusammenfassen. Dann shifte und
ver"unde" sie, um sie wieder zerlegen zu können.
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
	int l, r, y;	// left, right distance and signal parameter

    printf("What is l?\n");
    scanf("%d", &l);
    y = l;
    
    y = y << 8;
    printf("SHIFT 8 bit LEFT to get place for the next value = %d\n", y);
    
    printf("\nAnd what is r?\n");
    scanf("%d", &r);
	y = y | r;
    printf("Integrate r via OR = %d\n", y);

	printf("\n\nAnd now, bring the boys back home!\n\n");

   l = y >> 8;
    printf("\nGet l with SHIFT 8 bit RIGHT = %d\n", l);
	
	r = y & 255;
    printf("And now r with AND 255 = %d\n\n\n", r);
    
 	system("PAUSE");
    return 0;
}

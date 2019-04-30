/*-----------------------------------------------------------------------------
Um die beiden ProxySens-Werte, von 1 - 5, in einem Parameter übertragen zu
können, wandele ich sie in Hex-Zahlen um, um sie per Shift-Befehl zusammen-
fassen und zerlegen zu können.
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
	int l, r, y;	// left, right distance and signal parameter

    printf("What is l?\n");
    scanf("%d", &l);
    
    y = l;
    printf("Save l as hex in y = %#x\n", y);
    
    y = y << 8;
    printf("\nSHIFT y 8 bit LEFT to get place for the next value = %#x\n", y);
    
    printf("\nAnd what is r?\n");
    scanf("%d", &r);
    printf("That is in hex = %#x\n", r);

	y = y | r;
    printf("\nIntegrate r via OR in y = %#x\n", y);

	printf("By the way! What's this in decimal = %d\n", y);
	printf("Okay! That looks wrong!\n");

	printf("\nAnd now, bring the boys back home!\n");
	
    return 0;
}

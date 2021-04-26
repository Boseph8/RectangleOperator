#include <stdio.h>

int main(){

    struct point{
        int x, y;
    };

    struct rectangle{
        struct point upperLeft, lowerRight;
    };

    struct point centerR(struct rectangle R1){
        struct point c;
        c.x = (R1.lowerRight.x - R1.upperLeft.x)/2;
        c.y = (R1.lowerRight.y - R1.upperLeft.y)/2;

        return c;
    };

    struct rectangle moveR(struct rectangle R1, int x, int y){
        R1.upperLeft.x += x;
        R1.upperLeft.y += y;
        R1.lowerRight.x += x;
        R1.lowerRight.y += y;

        return R1;
    };

    struct rectangle R1 = {{6,6}, {10,12}};
    struct point center = centerR(R1);

    printf("Display center of R1\n");
	printf("Value of R1 center x is: %d\n", center.x);
    printf("Value of R1 center y is: %d\n", center.y);

    struct rectangle *R2 = &R1;

    R2->upperLeft.x = 15;
    R2->upperLeft.y = 15;
    R2->lowerRight.x = 25;
    R2->lowerRight.y = 25;

    *R2 = moveR(*R2, 3, 4);

    printf("\nDisplay R2 position after moved: \n");
    printf("Value of R2 upperLeft x is: %d\n", R2->upperLeft.x);
    printf("Value of R2 upperLeft y is: %d\n", R2->upperLeft.y);
    printf("Value of R2 lowerRight x is: %d\n", R2->lowerRight.x);
    printf("Value of R2 lowerRight y is %d\n", R2->lowerRight.y);

    return 0;
}
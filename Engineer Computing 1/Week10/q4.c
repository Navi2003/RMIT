#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct { double x; double y; } point;

point pointshow(point thing){
    printf("%lf %lf\n",thing.x, thing.y);
}

double sq(int x){
    return x*x;
}

double pointdist(point thing1, point thing2){
    return sqrt(sq(thing1.x-thing2.x)+sq(thing1.y-thing2.y));
}

int pointequal(point thing1, point thing2){
    if(pointdist(thing1, thing2)<0.000001){
        return 1;
    } else return 0;
}

int main(void){
    point test = {1, 1}, test2 = {1, 2};
    pointshow(test);
    printf("Euclidean distance: %d\n",pointdist(test, test2));
    printf("The points are %sequal", (pointequal(test, test2)?"":"not "));
    return 0; 
}
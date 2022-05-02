#include <stdio.h>

typedef struct {
    int x; 
    int y;
} point;
typedef struct {
    point ll;
    point ur;
} rect;

int isinrect(rect rec, point find){
    if (rec.ll.x <= find.x && rec.ur.x >= find.x && rec.ll.y <= find.y && rec.ur.y >= find.y){
        return 1;
    } else return 0;
}

int isrect2inrect1(rect rec1, rect rec2){
    if (isinrect(rec1, rec2.ll) == 1 && isinrect(rec1, rec2.ur) == 1){
        return 1;
    } else return 0;
}

//d:


int main(){
    point a = {0 ,0}, b = {5, 5}, c={1, 1}, d={4, 4}, find;
    rect recab = {a, b}, reccd = {c, d};
    printf("Enter a point: ");
    scanf("%d %d",&find.x, &find.y);
    printf("Is %sin the rectangle\n",(isinrect(recab, find)?"":"not "));
    printf("Rect 2 is %sin rect 1\n", ((isrect2inrect1(recab, reccd))?"":"not "));
    return 0;
}
#include <stdio.h>
#define Height 100
#define Width 100
int move(int count, int Xpos, int Ypos, int P[Height][Width], int rw, int rh, int Space){
    P[Xpos][Ypos] = count;
    if(Space != count) {
        if ((Xpos >= 2) && (Ypos >= 1) && P[Xpos - 2][Ypos - 1] == 0 &&
            (move(count + 1, Xpos - 2, Ypos - 1, P, rw, rh, Space))) {
            {
                return 1;
            }
        } else if ((Xpos >= 1) && (Ypos >= 2) && P[Xpos - 1][Ypos - 2] == 0 &&
                   (move(count + 1, Xpos - 1, Ypos - 2, P, rw, rh, Space))) {
            {
                return 1;
            }
        } else if ((Xpos + 1 < rw) && (Ypos >= 2) && P[Xpos + 1][Ypos - 2] == 0 &&
                   (move(count + 1, Xpos + 1, Ypos - 2, P, rw, rh, Space))) {
            {
                return 1;
            }
        } else if ((Xpos + 2 < rw) && (Ypos >= 1) && P[Xpos + 2][Ypos - 1] == 0 &&
                   (move(count + 1, Xpos + 2, Ypos - 1, P, rw, rh, Space))) {
            {
                return 1;
            }
        } else if ((Xpos + 2 < rw) && (Ypos + 1 < rh) && P[Xpos + 2][Ypos + 1] == 0 &&
                   (move(count + 1, Xpos + 2, Ypos + 1, P, rw, rh, Space))) {
            {
                return 1;
            }
        } else if ((Xpos + 1 < rw) && (Ypos + 2 < rh) && P[Xpos + 1][Ypos + 2] == 0 &&
                   (move(count + 1, Xpos + 1, Ypos + 2, P, rw, rh, Space))) {
            {
                return 1;
            }
        } else if ((Xpos >= 1) && (Ypos + 2 < rh) && P[Xpos - 1][Ypos + 2] == 0 &&
                   (move(count + 1, Xpos - 1, Ypos + 2, P, rw, rh, Space))) {
            {
                return 1;
            }
        } else if ((Xpos >= 2) && (Ypos + 1 < rh) && P[Xpos - 2][Ypos + 1] == 0 &&
                   (move(count + 1, Xpos - 2, Ypos + 1, P, rw, rh, Space))) {
            {
                return 1;
            }
        }
        P[Xpos][Ypos] = 0;
        return 0;
        /* откат на шаг назад */
    }
    else {
        return 1;
    }
}


int main() {
    int i, j, count, rh, rw, Xpos, Ypos, Space;
    int P[Height][Width];

    printf("Enter height: ");
    scanf("%d",&rh);
    printf("Enter width: ");
    scanf("%d",&rw);
    if(((0 < rw) && (Width >= rw)) && ((0 < rh) && (Height >= rh))){
        for(i = 0; i < rw; ++i){
            for(j = 0; j < rh; ++j){
                P[i][j] = 0;
            }
        }
        Space = rw*rh;
        printf("Enter X: ");
        scanf("%d",&Xpos);
        printf("Enter Y: ");
        scanf("%d",&Ypos);
        count = 1;



        if(1 ==  move(count, Xpos, Ypos, P,  rw, rh, Space)){
            for(i = 0; i < rw; ++i){
                for(j = 0; j < rh; ++j){
                    if(rh-1 == j) {
                        printf("%3d\n", P[i][j]);
                    }
                    else{
                        printf("%3d ", P[i][j]);
                    }

                }
            }
        }
        else{
            printf("Sorry, I`ve not found the right way");
        }
    }
    else{
        return -1;
    }
    return 0;
}
       /* 1) if((Xpos > 2) && (Ypos > 1))
        * 2) if((Xpos > 1) && (Ypos > 2))
        * 3) if((Xpos + 1 < rw) && (Ypos > 2))
        * 4) if((Xpos + 2 < rw) && (Ypos > 1))
        * 5) if((Xpos + 2 < rw) && (Ypos + 1 < rh))
        * 6) if((Xpos + 1 < rw) && (Ypos + 2 < rh))
        * 7) if((Xpos > 1) && (Ypos + 2 < rh))
        * 8) if((Xpos > 2) && (Ypos + 1 < rh))
        * */
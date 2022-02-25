/****************************************************
 * Author: Cristian Capraro     September 2021
 * School: ITIS. G. Fauser - Novara
 * Class: 4CIN
 * 
 * Creare in linguaggio c un programma in grado di
 * trovare le soluzioni di un'equazione di 2° grado.
 * (Variante 2)
 ****************************************************/

//LIB
#include <stdio.h>
#include <math.h>

//Functions
void Welcome(double *a, double *b, double *c){ //User input
    printf("[Equation Solver ax^2 + bx + c = 0]\n[User Input]\nA: ");
    scanf("%lf", a);
    printf("B: ");
    scanf("%lf", b);
    printf("C: ");
    scanf("%lf", c);
}

void print2sol(double * solutions){ //Print solutions
    printf("Sol 1: %lf \nSol 2: %lf\n", solutions[0], solutions[1]);
}

double ax2Zero(double b, double c){ //bx + c = 0
    return (-c/b);
}

double * cZero(double a, double b){ //ax^2 + bx = 0
    static double res[2];
    res[0] = 0;
    res[1] = -(b/a);
    return res;
}

double * bZero(double a, double c){ //ax^2 + c = 0
    if(-c/a >= 0){
        static double res[2];
        res[0] = -(sqrt((-c/a)));
        res[1] = sqrt((-c/a));
        return res;
    }else{
        printf("Impossible\n");
        return NULL;
    }
}

double * complete(double a, double b, double c){ //Standard ax^2+bx+c = 0
    double delta = 0;
    if((delta = pow(b, 2)-(4*a*c)) >= 0){
        static double res[2];
        res[0] = ((-b-sqrt(delta))/(2*a));
        res[1] = ((-b+sqrt(delta))/(2*a));
        return res;
    }else{
        printf("Impossible\n");
        return NULL;
    }
}

//Main
int main(){
    double c = 0, b = c, a = b; //Decl. and Init.
    double * results; //To Array pointer
    Welcome(&a, &b, &c); //Get data from user
    
    //All Cases
    if(a == 0 && b != 0 && c != 0){ // bx + c = 0
        printf("Solution: %lf\n", ax2Zero(b, c));
    }else if(a != 0 && b == 0 && c != 0){ //ax^2 + c = 0
        if((results = bZero(a, c)) != NULL) print2sol(results);
    }else if(a != 0 && b != 0 && c == 0){ //ax^2 + bx = 0
        if((results = cZero(a, b)) != NULL) print2sol(results);
    }else if((a != 0 && b == 0 && c == 0) || (a == 0 && b != 0 && c == 0)){ //ax^2 = 0 and x = 0
        printf("Solution: 0\n");
    }else if((c >= 0 && a == 0 && b == 0)){ // c = 0
        printf("Verify %lf = 0 --> %s", c, (c == 0)? "True" : "False");
    }else{ // ax^2 + bx + c
        if((results = complete(a, b, c)) != NULL) print2sol(results);
    }
    return 0;
}
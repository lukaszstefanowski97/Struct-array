//SDIZO I1 223A LAB01
//Łukasz Stefanowski
//sl39439@zut.edu.pl

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct A{
    int i;
    char c;
    float f;
};

struct A ** losowanie(int N){

    struct A ** tab=(struct A **)malloc(N*sizeof(struct A *));

    for(int j=0; j<N; j++)
    {
        tab[j]=(struct A *)malloc(sizeof(struct A));
        tab[j]->i=(rand() % 10000+1)-1000;
        tab[j]->c=(char)((rand() % (88 - 66) ) + 66);
        tab[j]->f=1000+j+1;
    }
    return tab;
}

void kasowanie(struct A ** tab, int  N){

    for (int k=0; k<N; k++)
    {
        free(tab[k]);
    }
    free(tab);
}

//void sortowanie(struct A ** tab, int  N) {
//    int zmienione;
//
//    do {
//        zmienione = 0;
//        int i = N - 1;
//        do {
//            if (tab[i]->i < tab[i - 1]->i) {
//                struct A *b;
//                b = tab[i];
//                tab[i] = tab[i - 1];
//                tab[i - 1] = b;
//                zmienione = 1;
//            }
//            --i;
//        } while (i > 0);
//    } while (zmienione == 1);
//}
  void sortowanie(struct A ** tab, int  N) {
    int zmienione = 0;

    for (int j = N - 1; j > 0; j--) {
        for (int i = N - 1; i > 0; i--) {
            if (tab[i]->i < tab[i - 1]->i) {
                struct A *b;
                b = tab[i];
                tab[i] = tab[i - 1];
                tab[i - 1] = b;
                zmienione = 1;
            }
        }
        if (zmienione == 0)
            break;
    }
}

int zliczanie(struct A ** tab, int  N, char X){
    int licznik=0;

    for (int i=0; i<N; i++)
    {
        if (tab[i]->c == X)
            licznik++;
    }
    return licznik;
}


int main(int argc, char**argv)
{
    int N;
    char X;
    FILE* fp = fopen("inlab01.txt", "r");
    if (fp == NULL)
        return -1;
    fscanf (fp, "%d %c", &N, &X);
    fclose(fp);

    clock_t begin, end;
    double time_spent;
    begin = clock();

    struct A** tab= losowanie (N);
    sortowanie(tab, N);

    if (N<20)
    {
        for (int i=0; i<N; i++)
        {
            printf("%d, %c, %d\n", tab[i]->i, tab[i]->c, (int)tab[i]->f);
        }
    }

    else {

        for (int i = 0; i < 20; i++) {
            printf("%d, %c, %d\n", tab[i]->i, tab[i]->c, (int) tab[i]->f);
        }
    }

    int z=zliczanie(tab, N, X);
    printf("%d", z);

    kasowanie(tab, N);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%lf", time_spent);

    return 0;
}
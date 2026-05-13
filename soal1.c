  /** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 5
 *   Hari dan Tanggal    : 13 MEI 2026
 *   Nama (NIM)          : NAJWA GHAYSANI ATHAYA ARDYANTO (13224023)
 *   Nama File           : soal1.c
 *   Deskripsi           : membuat program dimana print semua kemungkinan kombinasi simbol () yang sesuai dan benar. dimana user masukan input
 * berupa n pasang () lalu outputnya akan menunjukkan semua kombinasi yang memungkinkan dan totalnya ada berapa kombinasi.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** cekkombinasi(int x, int* returnSize){
    if(x==0){
        return 0;
    }
    int left, right, cap = 500, ctr = 0;
    char *stack = malloc(2 * x + 1);  //pake stack
    char **parentheses = malloc(cap * sizeof(char *));

    char *p = stack;
    left = right = 0;
    stack[2 * x] = '\0';

    while (p != stack || ctr == 0){
        if (left == x && right == x){
            parentheses[ctr] = malloc(2 * x + 1);
            strcpy(parentheses[ctr], stack);
            ctr++;

            while (--p != stack){
                if (*p == '(') {
                    if (--left > right){
                        *p++ = ')';
                        right++;
                        break;
                    }
                } else{
                    right--;
                }
            }
        } 
        else{
            // forward
            while (left < x){
                *p++ = '(';
                left++;
            }
            while (right < x){
                *p++ = ')';
                right++;
            }
        }
    }

    *returnSize = ctr;
    return parentheses;
}

int catalan(int n) {
  if (n == 0) {
    return 1;
  } else {
    return ((2.0 * ((2 * n) - 1)) / (n + 1)) * (catalan(n - 1));
  }
}

void printparenthese(int n, int ctr){
    char **list = cekkombinasi(n, &ctr);
    for (n = 0; n < ctr; n++) {
        printf("%s\n", list[n]);
    }
}

int main(){
    int n, ctr;
    scanf("%d", &n);
    printparenthese(n, ctr);
    printf("TOTAL %d\n", catalan(n));
    return 0;
}

//perhitungan pake hitung nilai permutasi catalan pake rekursif

//https://www.w3resource.com/c-programming-exercises/practice/c-programming-practice-exercises-11.php
//https://stackoverflow.com/questions/69353272/calculating-a-catalan-number-in-c
//https://www.geeksforgeeks.org/c/c-program-for-program-for-nth-catalan-number/

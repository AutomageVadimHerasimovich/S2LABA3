#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BRAND_LEN 50

    int input(int min, int max) {
        int x;
        while (scanf("%d", &x) != 1 || x < min || x > max || x % 1 != 0 || getchar() != '\n') {
            printf("Error. Try again: ");
            rewind(stdin);
        }
        return x;
    }

struct car_body {
    char* type[20];
    int engine_volume;
};

struct car {
    int price;
    char *brand;
    struct car_body body;
};
typedef struct {
    unsigned int b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1;
} byte;
void task1(){
    printf("Enter a char: ");
    char num= input(-9,9);
    byte *bits = (byte *)&num;
    printf("Исходное число: %d\n", num);
    printf("Дополнительный код: %d%d%d%d%d%d%d%d\n", bits->b7, bits->b6, bits->b5, bits->b4, bits->b3, bits->b2, bits->b1, bits->b0);
}
void task2() {
    int n, i, min_price;
    char *buffer[MAX_BRAND_LEN], brand[MAX_BRAND_LEN];
        printf("\nВведите количество: ");
        n=input(1,999);
        struct car *cars = (struct car *) malloc(n * sizeof(struct car));
        for (int i = 0; i < n; ++i) {
            printf("\nPrice: ");
            cars[i].price = input(-999999, 999999);
            printf("\nBrand: ");
            scanf("%s", buffer);
            cars[i].brand = (char *) malloc(strlen(buffer) + 1);
            strcpy(cars[i].brand, buffer);
            printf("\nType of body(positive): ");
            scanf("%s", cars[i].body.type);
            printf("\nEngine: : ");
            cars[i].body.engine_volume = input(-9999999, 999999);
        }
        printf("Enter minimum price: ");
        scanf("%d", &min_price);
        printf("Cars with price greater than %d:\n", min_price);
        for (i = 0; i < n; i++) {
            if (cars[i].price > min_price) {
                printf("Price: %d, Brand: %s, Type: %s, Engine Volume: %d\n",
                       cars[i].price, cars[i].brand, cars[i].body.type, cars[i].body.engine_volume);
            }
        }
        printf("Enter brand to remove: ");
        scanf("%s", brand);
        for (i = 0; i < n; i++) {
            if (strcmp(cars[i].brand, brand) == 0) {
                for (int j = i; j < n - 1; j++) {
                    cars[j] = cars[j + 1];} n--;
                cars=(struct cars*)realloc(cars, n*sizeof(struct car)); i--;
            }
        }
        printf("Cars after removing %s:\n", brand);
        for (i = 0; i < n; i++) {
            if (strcmp(cars[i].brand, " ") != 0) {
                printf("Price: %d, Brand: %s, Type: %s, Engine Volume: %d\n",
                       cars[i].price, cars[i].brand, cars[i].body.type, cars[i].body.engine_volume);
            }
        }
    free(cars);
    }

int main() {
    int ch;
    do {
        printf("\nВведите номер задания : \n");
        ch = input(1, 2);
        if (ch == 1) {
            task1();
        } else task2();
        printf("\nХотите выбрать ещё одно задание?\n1-Да 2-Нет\n");
        ch = input(1, 2);
    } while (ch!=2);
    return 0;
}
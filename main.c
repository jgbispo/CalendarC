#include <stdio.h>
#include <time.h>
#include <stdbool.h>

struct Data {
    int day;
    int month;
    int year;
};


void dayAndYear(struct Data d);

bool verifyMonth(int month);

int main(void) {
    struct Data d;
    d.day = 23;
    d.month = 7;
    d.year = 2020;
    int userDay;
    printf("Days: ");
    scanf("%d", &userDay);
    d.day += userDay;
    dayAndYear(d);
    return 0;
}

void dayAndYear(struct Data d) {
    if (d.day > 28 ) {
       do{
           if(d.month == 2){
               d.day -= 28;
           }

           if(verifyMonth(d.month)){
                d.day -= 31;
                d.month++;
                if(d.month >= 12){
                    d.month = 1;
                    d.year++;
                }
           }else if(!verifyMonth(d.month)){
               d.day -= 30;
               d.month++;
               if(d.month >= 12){
                   d.month = 1;
                   d.year++;
               }
           }

           if(d.day == 0){
               d.day = 1;
           }

       }while(d.day > 30);
    }

    printf("%d/%d/%d\n", d.day, d.month, d.year);
}

bool verifyMonth(int month) {
    int month31[] = {1, 3, 5, 7, 8, 10, 12};
    int month30[] = {4, 6, 9, 11};

    size_t n31 = sizeof(month31) / sizeof(month31[0]);
    size_t n30 = sizeof(month30) / sizeof(month30[0]);

    for (int i = 0; i < n31; ++i) {
        if (month == month31[i]) {
            return true;
        }
    }
    for (int i = 0; i < n30; ++i) {
        if (month == month30[i]) {
            return false;
        }
    }
}

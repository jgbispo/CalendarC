#include <stdio.h>

struct Data {
  int day;
  int month;
  int year;
};

void dayAndYear(struct Data d);

int main(void) {
  struct Data d;

  d.day = 14;
  d.month = 1;
  d.year = 2020;
  int userDay;
  printf("Days: ");
  scanf("%d", &userDay);
  d.day += userDay;
  dayAndYear(d);
  return 0;
}

void dayAndYear(struct Data d) {
  do {
    d.month++;
    if (d.month > 12) {
      d.year++;
			d.day -= 5;
      d.month -= 12;
    }
		d.day -= 30;
  } while (d.day > 30);
  printf("%d/%d/%d\n", d.day, d.month, d.year);
}

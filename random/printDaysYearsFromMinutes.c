#include <stdio.h>
#include <stdlib.h>

int main()
{

  int minutesEntered = 0;
  double years = 0.0;
  double days = 0.0;

  printf("Please enter the number of minutes: ");

  scanf("%d", &minutesEntered);
  // printf("%d", minutesEntered);

  years = minutesEntered / (double)(60 * 24 * 365);
  days = minutesEntered / 60.0 / 24.0;

  /* ideally we should print and throw an error if user entered a
    number bigger than an int and use other types eg unsigned */

  printf("%d minutes is approximately %f years or %f days\n", minutesEntered, years, days);

  return 0;
}
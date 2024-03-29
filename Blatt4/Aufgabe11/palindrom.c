#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int palindrom_check1(const char *st1)
{
  int st1_len = strlen(st1), i;

  for(i = 0; i < st1_len / 2; i++)
  {
    if (toupper(st1[i]) != toupper(st1[st1_len -i-1])) return 0;
  }
  return 1;
}

int main(void) {
  char *st1, *st2;
  int st1_len, i;
  char *exit = "exit";

  st1 = (char*)malloc(100);
  st2 = (char*)malloc(100);

  printf("Zum Beenden exit als Eingabe angeben. \n");
  while (1) {
    printf("Eingabe: ");
    scanf("%s", st1);
    if (strcmp(st1, exit) == 0) return 0;

    st1_len = strlen(st1);

    for (i=0; i<(st1_len); i++) {
      st2[i] = st1[i];
    }

    if (palindrom_check1(st1)) printf("1. Test: Palindrom \n");
    else printf("1. Test: Kein Palindrom \n");

    if (st1 == st2) printf("2. Test: Palindrom\n");
    else printf("2. Test: Kein Palindrom\n");
 }
 return 0;
}

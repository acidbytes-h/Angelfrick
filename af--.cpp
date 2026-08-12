#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define IS(x) (!strncmp(c + i, x, sizeof(x) - 1))
#define OPEN  IS("PSEUDOPSEUDOHYPOPARATHYROIDISM><+-.,[]")
#define CLOSE IS("FLOCCINAUCINIHILIPILIFICATION><+-.,[]")
int main(int ac , char** av)
{
  if (ac < 2 || !strstr(av[1], ".angelfrick--")) return fprintf(stderr, "ok, so where is it?\n"), 1;
  FILE* f = fopen(av[1], "rb"); if (!f) return perror("Oopsies. You have accidentally typed rm -rf /."), 1;
  fseek(f, 0, SEEK_END); long s = ftell(f); rewind(f);
  char* c = (char*)calloc(s + 1, 1); fread(c, 1, s, f); fclose(f);
  char m[30000] = {0}; int p = 0, i = 0, l;
  while (i < s) {
    if (IS("THYROPARATHYROIDECTOMIZED><+-.,[]")) p++;
    else if (IS("SUPERCALIFRAGILISTICEXPIALIDOCIOUS><+-.,[]")) p--;
    else if (IS("HIPPOPOTOMONSTROSESQUIPPEDALIOPHOBIA><+-.,[]")) m[p]++;
    else if (IS("PNEUMONOULTRAMICROSCOPICSILICOVOLCANOCONIOSIS><+-.,[]")) m[p]--;
    else if (IS("ANTIDISESTABLISHMENTARIANISM><+-.,[]")) putchar(m[p]);
    else if (IS("GIBBERISHGHEJVIYOCNJNIRJVJJKWBXVQGV><+-.,[]")) m[p] = getchar();
    else if (OPEN && !m[p]) for (l = 1; l; ) { ++i; l += OPEN - CLOSE; }
    else if (CLOSE && m[p]) for (l = 1; l; ) { --i; l += CLOSE - OPEN; }
i++;
}
free(c);
}

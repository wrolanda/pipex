#include <cstdio>

int main()
{
  FILE * ptrFile = fopen("nonexist.ent", "rb");

  if (ptrFile == NULL)
    perror("Fork");
  else
    fclose (ptrFile);
  return 0;
}

#include <stdio.h>
#include <time.h>

int main(){
  FILE *fptr;
  fptr = fopen("data.txt", "w");
  fprintf(fptr, "%d", 0);
  fclose(fptr);

  struct tm *gtime;
  time_t now;

  time(&now);

  gtime = gmtime(&now);


  printf("Content-type: text/html\n\n");
  printf("<html>\n");
  printf("<header>\n");
  printf("<h1>The Time in Ghana, Accra is: %2d:%02d</h1>\n", gtime->tm_hour % 24, gtime->tm_min);
  printf("</header>\n");
  printf("<body\n>");
  printf("<h2><a href='./SA.cgi'>Switch to South African time</a></h2>\n");
  printf("<h2><a href='./Home.cgi'>Return Back To Home</a></h2>");
  printf("</body>\n");
  printf("</html>\n");
}

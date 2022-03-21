#include <stdio.h>
#include <time.h>

#define SAST (2)

int main(){
  FILE *fptr;
  fptr = fopen("data.txt", "w");
  fprintf(fptr, "%d", SAST);
  fclose(fptr);
  //printf("Location: http://localhost/cgi-bin/Home.cgi\n\n");

  struct tm *gtime;
  time_t now;

  time(&now);

  gtime = gmtime(&now);


  printf("Content-type: text/html\n\n");
  printf("<html>\n");
  printf("<header>\n");
  printf("<h1>The Time in South Africa, Johannesburg is: %2d:%02d</h1>\n", (gtime->tm_hour + SAST) % 24, gtime->tm_min);
  printf("</header>\n");
  printf("<body\n>");
  printf("<h2><a href='./Ghana.cgi'>Switch to Ghanian time</a></h2>\n");
  printf("<h2><a href='./Home.cgi'>Return Back To Home</a></h2>");
  printf("</body>\n");
  printf("</html>\n");
}

#include <stdio.h>
#include <time.h>

#define SAST (+2)

int main(){
  struct tm *gtime;
  time_t now;

  time(&now);

  gtime = gmtime(&now);

  char *filename = "data.txt";
  FILE *fp = fopen(filename, "r");

  printf("Content-type: text/html\n\n");
  printf("<html>\n");
  printf("<header>\n");

  char ch;
  char b;

  if(fp == NULL){
    printf("Error: could not open file %s", filename);
  }

  while((ch = fgetc(fp)) != EOF){
    b = ch;
    break;
  }


  char a = '0';

  if(b == a){
    printf("<h1>The Time in Ghana is: %2d:%02d</h1>\n", gtime->tm_hour % 24, gtime->tm_min);
  }else{
    printf("<h1>The Time in South Africa is: %2d:%02d</h1>\n", (gtime->tm_hour + SAST) % 24, gtime->tm_min);
  }

  printf("</header>\n");
  printf("<body\n>");
  printf("<h2><a href='./SA.cgi'>Switch to South African time</a></h2>\n");
  printf("<h2><a href='./Ghana.cgi'>Switch to Ghanaian Time</a></h2>");
  printf("</body>\n");
  printf("</html>\n");

  fclose(fp);
}

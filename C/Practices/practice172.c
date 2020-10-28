#include <stdio.h>
#include <string.h>

//構造体型宣言
typedef struct {
  int number;
  char name[256];
  int score;
} People;

int main(void)
{
  People data[4];
  int i;

  data[0].number = 1;
  strcpy(data[0].name,"野比のび太");
  data[0].score = 0;

  data[1].number = 2;
  strcpy(data[1].name,"源静香");
  data[1].score = 90;

  data[2].number = 3;
  strcpy(data[2].name,"剛田武");
  data[2].score = 40;

  data[3].number = 4;
  strcpy(data[3].name,"骨川スネ夫");
  data[3].score = 70;

  FILE *file;
  file = fopen("list.csv","w");
  fprintf(file,"番号,名前,テストの平均点\n");

	for (i = 0;i < 4;i++) {
	  fprintf(file,"%4d,%10s,%14d\n",data[i].number,data[i].name,data[i].score);
	}

  fclose(file);

  return 0;
}

#include <stdio.h>
#include <string.h>

typedef struct {
  //学年
  int year;
  //クラス
  int group;
  //学生番号
  int number;
  //名前
  char name[64];
  //身長
  double stature;
  //体重
  double weight;
} student;

void student_print(student data);

int main(void)
{
  student data;
  student *pdata;

  /*data.year = 3;
  data.group = 4;
  data.number = 18;
  strcpy(data.name,"MARIO");
  data.stature = 172.5;
  data.weight = 55.2;

  student_print(data);*/

  //初期化
  pdata = &data;
  //通常変数モードへ切り替え
  //(*pdata).year = 10;
  pdata->year = 10;
  //通常変数モードへ切り替え
  //strcpy((*pdata).name,"MARIO");
  strcpy(pdata->name,"MARIO");

  return 0;
}

/*void student_print(student data)
{
  printf("[学年]:%d\n",data.year);
  printf("[クラス]:%d\n",data.group);
  printf("[学生番号]:%d\n",data.number);
  printf("[名前]:%s\n",data.name);
  printf("[身長]:%f\n",data.stature);
  printf("[体重]:%f\n",data.weight);

  return;
}*/

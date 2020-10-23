#include <stdio.h>

//構造体型宣言
typedef struct {
  char name[64];
  int age;
  int sex;
} person;

//プロトタイプ宣言
void person_input(person data[],int count);
void person_output(person data[],int count);

//指定された数だけperson型の構造体配列にデータを入力
void person_input(person data[],int count)
{
  int i;
  for (i = 0;i < count;i++){
    printf("[%d 人目]名前を入力してください:",i + 1);
    //&data[i].name[0]でもいける(配列の最初の要素のアドレスを示す)
    //%16sでoverflowを防止
    scanf("%16s",data[i].name);
    printf("[%d 人目]年齢を入力してください:",i + 1);
    scanf("%d",&data[i].age);
    printf("[%d 人目]性別を入力してください 1.男性 2.女性:",i + 1);
    scanf("%d",&data[i].sex);
  }
  return;
}

//指定された数だけperson型の中身を表示
void person_output(person data[],int count)
{
  int i;
  for (i = 0;i < count;i++){
    printf("[名前]:%s\n",data[i].name);
    printf("[年齢]:%d\n",data[i].age);
    printf("[性別]1.男性 2.女性:%d\n",data[i].sex);
  }
  return;
}

int main(void)
{
  //person型で3つの要素を持つ構造体変数の配列の宣言
  person data[3];

  person_input(data,3);
  person_output(data,3);

  return 0;
}

//practice20.h
#ifndef _PEOPLE_H_
#define _PEOPLE_H_

#include <stdio.h>
#include <string.h>

typedef struct {
  char name[256];
  int age;
  int sex;
} People;

//個人の名前、年齢、性別のデータを入力し、保存する関数
extern void InputPeople(People *data);

//個人の名前、年齢、性別のデータを出力する関数
extern void ShowPeople(People data);

#endif

#include <stdio.h>
#include <string.h>

//構造体型宣言
typedef struct {
	char name[256];
	int age;
	int sex;
} People;

//プロトタイプ宣言
void InputPeople(People *data);
void ShowPeople(People data);

int main(void)
{
	People data[3];
	int i;
	
  //main関数内で繰り返しを指示
	for (i = 0;i < 3;i++) {
		InputPeople(&data[i]);
	}
	
	for (i = 0;i < 3;i++) {
		ShowPeople(data[i]);
	}
	
	return 0;
}

//構造体型へのポインタ引数を使用
void InputPeople(People *data)
{
	printf("名前:");
  //->を用いて各要素にアクセス
	scanf("%s",data->name);
	printf("年齢:");
	scanf("%d",&data->age);
	printf("性別(1-男性、2-女性):");
	scanf("%d",&data->sex);
	printf("\n");
}

//構造体型の引数を使用
void ShowPeople(People data)
{
	char sex[16];
	
	printf("名前:%s\n",data.name);
	printf("年齢:%d\n",data.age);
	
  //sexの中身に応じて性別を表示
	if (data.sex == 1) {
		strcpy(sex,"男性");
	} else {
		strcpy(sex,"女性");
	}
	
	printf("性別:%s\n",sex);
	printf("\n");
}

//
// Created by ��˶ on 2021/4/2.
//

//����

#include "menu.h"

// ����
void start(void) {
  FILE* sfrp = fopen("../stu.txt", "r");

  for (i = 0; i < 100; i++)
  {
    int num = 0;
    num = fscanf(sfrp, "%s %c %s %s  %hd %hd %hd %s", STU[i].name, &STU[i].sex, STU[i].id, STU[i].passwd, &STU[i].time, &STU[i].birth, &STU[i].exist, &STU[i].course);
  }
  fclose(sfrp);

  FILE* tfrp = fopen("../tea.txt", "r");
  for (i = 0; i < 50; i++)
  {
    int num = 0;
    num = fscanf(tfrp, "%s %c %s %s %hd %hd ", TEA[i].name, &TEA[i].sex, TEA[i].id, TEA[i].passwd, &TEA[i].time, &TEA[i].birth);
  }
  fclose(tfrp);
}

//��������
void sams_exit(void)
{
  FILE* sfwp = fopen("../stu.txt", "w");
  for (i = 0; i < 100; i++)
  {
    int num = 0;
    if (STU[i].sex != 0)
    {
      num = fprintf(sfwp, "%s %c %s %s %hd  %hd %hd %s\n", STU[i].name, STU[i].sex, STU[i].id, STU[i].passwd, STU[i].time, STU[i].birth, STU[i].exist, STU[i].course);
    }
  }
  fclose(sfwp);

  FILE* tfwp = fopen("../tea.txt", "w");
  for (i = 0; i < 50; i++)
  {
    int num = 0;
    if (TEA[i].sex != 0)
    {
      num = fprintf(tfwp, "%s %c %s %s %hd %hd \n", TEA[i].name, TEA[i].sex, TEA[i].id, TEA[i].passwd, TEA[i].time, TEA[i].birth);
    }
  }
  fclose(tfwp);
  // �ͷ��ڴ桢��������
  free(STU);
  free(TEA);

  cout << "ϵͳ�˳�...\n";
}
//��ȡ�ַ���
char* get_str(char* str, size_t len)//��ȡ�ַ���
{
  if (NULL == str)
  {
    cout << "empty ptr��" << endl;
    ;    return NULL;
  }

  char* in = fgets(str, len, stdin);

  size_t cnt = strlen(str);
  if ('\n' == str[cnt - 1])
  {
    str[cnt - 1] = '\0';
  }
  return str;
}
//��ȡ�Ա�
char get_sex(void)
{
  cout << "��m�У�wŮ����";
  ;  while (true)
  {
    char sex = _getch();
    if ('w' == sex || 'm' == sex)
    {
      cout << ('w' == sex ? "Ů" : "��");
      return sex;
    }
  }
}
//��ȡ����ָ��
char get_cmd(char start, char end)
{

  cout<<"������ָ��:";
  char val = cin.get();
  return val;

}
//���뱣��
char* get_pw(char* passwd, bool is_show, size_t size)
{
  if (NULL == passwd) return NULL;

  int count = 0;
  do {
    char val = _getch();
    if (8 == val)     //�˸�
    {
      if (count > 0)
      {
        if (is_show)cout << "\b \b";
        count--;
      }
      continue;
    }
    else if (13 == val)
    {
      break;
    }
    passwd[count++] = val;
    if (is_show) cout << "*";
  } while (count < size - 1);

  passwd[count] = '\0';
  return passwd;
}

//
// Created by 程硕 on 2021/4/2.
//

//操作

#include "menu.h"

// 缓存
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

//结束程序
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
  // 释放内存、保存数据
  free(STU);
  free(TEA);

  cout << "系统退出...\n";
}
//获取字符串
char* get_str(char* str, size_t len)//获取字符串
{
  if (NULL == str)
  {
    cout << "empty ptr！" << endl;
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
//获取性别
char get_sex(void)
{
  cout << "（m男，w女）：";
  ;  while (true)
  {
    char sex = _getch();
    if ('w' == sex || 'm' == sex)
    {
      cout << ('w' == sex ? "女" : "男");
      return sex;
    }
  }
}
//获取键盘指令
char get_cmd(char start, char end)
{

  cout<<"请输入指令:";
  char val = cin.get();
  return val;

}
//密码保护
char* get_pw(char* passwd, bool is_show, size_t size)
{
  if (NULL == passwd) return NULL;

  int count = 0;
  do {
    char val = _getch();
    if (8 == val)     //退格
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

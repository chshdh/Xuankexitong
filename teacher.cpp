//
// Created by 程硕 on 2021/4/2.
//


//老师操作

#include "menu.h"
// 运行老师子系统
void teacher_start(void)
{

  pos = teacher_login();
  if (pos == -1)
  {
    cout << "登录失败!\n";
    return;
  }
  while (true)
  {
    teacher_menu();
    switch (get_cmd('0', '8'))
    {
      case '1': teacher_add_stu(); break;
      case '2': teacher_del_stu(); break;
      case '3': teacher_find_stu(); break;
      case '4': teacher_ch_stu_info(); break;
      case '5': teacher_reset_stu_pw(); break;
      case '6': teacher_list_stu(); break;
      case '7': teacher_list_ubstu(); break;
      case '8': teacher_ch_pw(); break;
      case '0': return;
    }
  }
}
//添加老师
void _add_tea(void)
{
  cin.ignore();
  cout << "添加教师\n";
  char Cteacher_name[20];
  char Cteacher_sex;
  char Cteacher_id[20];
  char Cteacher_pw[20];
  cout << "请输入教师姓名：";
  get_str(Cteacher_name, 20);
  cout << "请输入教师性别：";
  Cteacher_sex = get_sex();
  cin.ignore();
  cout << "请输入教师工号：";
  get_str(Cteacher_id, 20);
  cout << "请输入教师密码：";
  get_str(Cteacher_pw, 20);
  int pos = -1; //插入的位置
  cout << TEA[0].id << endl;
  for (i = 0; i < 50; i++)
  {
    if (TEA[i].sex == '\0' && pos == -1)
    {
      cout << "pos已定位\n";
      pos = i;
    }
    if (strcmp(TEA[i].id, Cteacher_id) == 0)
    {
      cout << "工号重复，请重新输入！\n";
      break;
    }
    if (i == 49)
    {
      strcpy_s(TEA[pos].name, Cteacher_name);
      TEA[pos].sex = Cteacher_sex;
      strcpy_s(TEA[pos].id, Cteacher_id);
      strcpy_s(TEA[pos].passwd, Cteacher_pw);
      cout << "添加成功。\n";
    }
  }
  cout << TEA[0].id << endl;
}
// 老师登录
int teacher_login(void)
{
  cin.ignore();

  char Cteacher_id[20] = {};
  char Cteacher_pw[20] = {};
  cout << "请输入用户名:";
  get_str(Cteacher_id, 20);
  if (Cteacher_id[0] == '\0')
  {
    cout << "用户名不能为空！\n";
    return -1;
  }
  cout << "用户: " << Cteacher_id << endl;
  cout << "请输入密码:";
  get_pw(Cteacher_pw, true, 20);
  cout << endl;
  for (i = 0; i < 50; i++)
  {
    if (strcmp(Cteacher_id, TEA[i].id) == 0)
    {
      if (TEA[i].time == 3)
      {
        cout << "此工号已被锁定，\n";
        return -1;
      }

      if (strcmp(Cteacher_pw, TEA[i].passwd) == 0)
      {
        return i;
      }
      else
      {
        TEA[i].time++;
        cout << "密码错误.\n";
        return -1;
      }
    }
  }
  cout << "不存在此教师。\n";
  return -1;
}
// 老师修改密码
void teacher_ch_pw(void)
{
  cin.ignore();
  char old_pw[20] = {};
  char new_pw[20] = {};
  char new_two_pw[20] = {};
  cout << "请输入原密码：";
  get_pw(old_pw, true, 20);
  cout << endl;
  cout << "请输入新密码：";
  get_pw(new_pw, true, 20);
  cout << endl;
  cout << "请再次输入新密码：";
  get_pw(new_two_pw, true, 20);
  cout << endl;
  if (strcmp(old_pw, TEA[pos].passwd) == 0)
  {
    if (strcmp(new_pw, new_two_pw) == 0)
    {
      cout << "修改密码成功\n";
      if (TEA[pos].birth == 0)
      {
        TEA[pos].birth = 1;
      }
      strcpy_s(TEA[pos].passwd, new_pw);
    }
    else
    {
      cout << "两次密码不一致\n";
    }
  }
  else
  {
    cout << "原密码错误。\n";
  }
}
// 老师添加学生
void teacher_add_stu(void)
{
  cin.ignore();
  cout << "添加学生\n";
  char Cstudent_name[20];
  char Cstudent_sex;
  char Cstudent_id[20];
  char Cstudent_pw[20];
  cout << "请输入学生姓名：";
  get_str(Cstudent_name, 20);
  cout << "请输入学生性别：";
  Cstudent_sex = get_sex();
  cout << "请输入学号：";
  get_str(Cstudent_id, 20);
  cout << "请输入学生密码：";
  get_str(Cstudent_pw, 20);
  int pos = -1; //插入的位置
  cout << STU[0].id << endl;
  for (i = 0; i < 100; i++)
  {
    if (STU[i].sex == '\0' && pos == -1)
    {
      cout << "pos已定位\n";
      pos = i;
    }
    if (strcmp(STU[i].id, Cstudent_id) == 1)
    {
      cout << "学号重复，请重新输入！\n";
      break;
    }
    if (i == 99)
    {
      strcpy_s(STU[pos].name, Cstudent_name);
      STU[pos].sex = Cstudent_sex;
      strcpy_s(STU[pos].id, Cstudent_id);
      strcpy_s(STU[pos].passwd, Cstudent_pw);
      cout << "添加成功。\n";
    }
  }
  cout << STU[0].id << endl;
}
// 老师删除学生
void teacher_del_stu(void)
{
  cin.ignore();
  cout << "删除学生\n";
  cout << "请输入学生学号:";
  char Cstudent_id[20] = {};
  get_str(Cstudent_id, 20);
  for (i = 0; i < 100; i++)
  {
    if (strcmp(Cstudent_id, STU[i].id) == 0)
    {
      STU[i].exist = 1;
      cout << "删除成功！\n";
      break;
    }
    if (i == 99)
    {
      cout << "无此学号！\n";
    }
  }

}
// 老师查询学生
void teacher_find_stu(void)
{
  cin.ignore();
  cout << "请输入学生学号：";
  char Cstudent_id[20] = {};
  get_str(Cstudent_id, 20);
  for (i = 0; i < 100; i++)
  {
    if (strcmp(Cstudent_id, STU[i].id) == 0)
    {
      cout << "姓名：" << STU[i].name << endl << "性别：" << STU[i].sex << endl << "学号: " << STU[i].id << endl;
      if (STU[i].exist == 0) {
        cout << "该学生还未选课！" << endl;


      }
      else {
        for (int q = 0; q <= STU[i].exist; q++) {
          cout << "该同学选课的课序号为";
          cout << STU[i].course[q] << "  ";
        }
      }
      break;
    }
    else if (i == 99)
    {
      cout << "无此学号。\n";
    }
  }
}
// 老师修改学生信息
void teacher_ch_stu_info(void)
{
  cin.ignore();
  cout << "请输入学生学号：";
  char Cstudent_id[20] = {};
  get_str(Cstudent_id, 20);
  for (i = 0; i < 100; i++)
  {
    if (strcmp(Cstudent_id, STU[i].id) == 0)
    {
      char ch_name[20];
      char ch_sex;
      char ch_id[20];
      cout << STU[i].name << STU[i].sex << STU[i].id << endl;
      cout << "请输入新姓名：";
      get_str(ch_name, 20);
      cout << "请输入新性别：";
      cin >> ch_sex;
      cout << "请输入新学号：";
      get_str(ch_id, 20);

      strcpy_s(STU[i].name, ch_name);
      STU[i].sex = ch_sex;
      strcpy_s(STU[i].id, ch_id);

      cout << "信息修改成功。\n";
      break;
    }
    else if (i == 99)
    {
      cout << "无此学号。\n";
    }
  }
}
// 老师重置学生密码
void teacher_reset_stu_pw(void)
{
  cin.ignore();
  cout << "重置密码\n";
  cout << "请输入学生学号：";
  char Cstudent_id[20] = {};
  get_str(Cstudent_id, 20);
  char Cstudent_pw[20] = "123";
  for (i = 0; i < 100; i++)
  {
    if (strcmp(STU[i].id, Cstudent_id) == 0)
    {
      STU[i].time = 0;
      STU[i].birth = 0;
      strcpy_s(STU[i].passwd, Cstudent_pw);
      cout << "重置成功！\n";
      break;
    }
    if (i == 99)
    {
      cout << "无此学号.\n";
    }
  }
}
// 老师显示选课学生列表
void teacher_list_stu(void)
{
  cin.ignore();
  cout << "显示选课学生";
  for (i = 0; i < 100; i++)
  {
    if (STU[i].sex != '\0')
    {
      if (STU[i].exist != 0)
      {
        cout << STU[i].name << STU[i].sex << STU[i].id;
      }
    }
    else
    {
      break;
    }
  }
}
// 老师显示未选课学生列表
void teacher_list_ubstu(void)
{
  cin.ignore();
  cout << "显示未选课学生";
  for (i = 0; i < 100; i++)
  {
    if (STU[i].sex != '\0')
    {
      if (STU[i].exist == 0)
      {
        cout << STU[i].name << STU[i].sex << STU[i].id;
      }
    }
    else
    {
      break;
    }
  }
}

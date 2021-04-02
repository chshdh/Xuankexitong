//
// Created by 程硕 on 2021/4/2.
//
#include "menu.h"
//学生操作

//学生开始系统
void student_start(void)
{
  temp = student_login();
  if (temp == -1)
  {
    cout << "登录失败!\n";
    return;
  }
  while (true)
  {
    student_menu();
    switch (get_cmd('1', '4'))
    {
      case '1': student_find_(); break;
      case '2': student_ch_pw(); break;
      case '3': student_find_info(); break;
      case '4': return;


    }
  }
}
//学生登陆
int student_login(void)
{
  cin.ignore();
  char Cstudent_id[20] = {};
  char Cstudent_pw[20] = {};
  cout << ("请输入用户名:");
  get_str(Cstudent_id, 20);
  if (Cstudent_id[0] == '\0')
  {
    cout << ("用户名不能为空！\n");
    return -1;
  }
  cout << "用户: " << Cstudent_id << endl;
  cout << ("请输入密码:");
  get_pw(Cstudent_pw, true, 20);
  cout << ("\n");
  for (i = 0; i < 100; i++)
  {
    if (strcmp(Cstudent_id, STU[i].id) == 0)
    {
      if (STU[i].time == 3)
      {
        cout << "此学号已被锁定，\n";
        return -1;
      }

      if (strcmp(Cstudent_pw, STU[i].passwd) == 0)
      {
        return i;
      }
      else
      {
        STU[i].time++;
        cout << "密码错误.\n";
        return -1;
      }
    }
  }
  cout << "不存在此学生。\n";
  return -1;
}
//学生修改密码
void student_ch_pw(void)
{
  char old_stu_pw[20] = {};
  char new_stu_pw[20] = {};
  char new_stu_two_pw[20] = {};
  cout << ("请输入原密码：");
  get_pw(old_stu_pw, true, 20);
  cout << "\n";
  cout << ("请输入新密码：");
  get_pw(new_stu_pw, true, 20);
  cout << "\n";
  cout << ("请再次输入新密码：");
  get_pw(new_stu_two_pw, true, 20);
  cout << endl;
  if (strcmp(old_stu_pw, STU[temp].passwd) == 0)
  {
    if (strcmp(new_stu_pw, new_stu_two_pw) == 0)
    {
      cout << ("修改密码成功\n");
      if (STU[temp].birth == 0)
      {
        STU[temp].birth = 1;
      }
      strcpy_s(STU[temp].passwd, new_stu_pw);
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
//学生选课
void  input() {
  cout << "输入选择的课程序号(1,2,3,4,5,6,7,8,9)" << endl;
  int a;
  cin >> a;
  for (int i = 0; i < 10; i++)
  {
    if (STU[temp].course[i] == a) {
      cout << "您已经选过该课程" << endl; break;
    }
    else
    {
      STU[temp].exist++;
      a = STU[temp].course[STU[temp].exist];

      cout << "选课成功！"; break;
    }
  }
}//学生选课
//学生删除课程
void  getCourseInfo() {
  cout << "请输入删除的课程序号" << endl;
  int a;
  cin >> a;
  for (int i = 0; i < 10; i++)
  {
    if (STU[temp].course[i] == a) {
      STU[temp].course[i] = 0;
      for (int j = 0; j < STU[temp].exist - i; j++) {
        STU[temp].course[i + j + 1] = STU[temp].course[i + j];
        STU[temp].exist--;

      }
    }
    else {
      cout << "您未选过此课程" << endl;

    }
  }
}
//选课查询
void student_find_info(void)
{
  cout << ("个人信息\n");
  cout << "姓名：" << STU[temp].name << endl << "性别：" << STU[temp].sex << endl << STU[temp].id << endl;
  if (STU[i].exist == 0) {
    cout << "你还未选课！" << endl;


  }
  else {
    for (int q = 0; q <= STU[i].exist; q++) {
      cout << "你选课的课序号为";
      cout << STU[i].course[q] << "  ";
    }
  }
}
//学生查询个人信息
void student_find_(void)//学生选课查询
{
  student_class();
  switch (get_cmd('1', '4'))
  {
    case '1': input(); break;
    case '2': getCourseInfo(); break;
    case'0':return;
  }
}


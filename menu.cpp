//主菜单
#include <iostream>
using  namespace std;
void sams_menu(void)
{
  cout << ("***欢迎使用指针学生成绩管理系统***\n");
  cout << ("1、教师子系统\n");
  cout << ("2、学生子系统\n");
  cout << ("3、添加老师账号\n");
  cout << ("4、退出系统\n");
  cout << ("-----------------------------\n");
}
//学生菜单
void student_menu(void)
{
  cout << ("进入学生子系统...\n");
  cout << ("1、课程管理\n");
  cout << ("2、修改密码\n");
  cout << ("3、查看个人信息\n");
  cout << ("4、返回上一级\n");
  cout << ("---------------\n");
}
// 老师子系统菜单
void teacher_menu(void)
{

  cout << "\n进入教师子系统...\n";
  cout << "1、添加学生\n";
  cout << "2、删除学生\n";
  cout << "3、查找学生\n";
  cout << "4、修改学生信息\n";
  cout << "5、重置学生密码\n";
  cout << "6、显示已经选课学生\n";
  cout << "7、显示所有未选课学生\n";
  cout << "8、修改自己密码\n";
  cout << "0、返回上一级\n";
  cout << "-----------------\n";
}
//学生选课菜单
void student_class() {

  cout << endl;
  cout << " 学生选课系统 " << endl;
  cout << " 1. 选择课程 " << endl;
  cout << " 2. 删除信息 " << endl;
  cout << " 0. 退出程序 " << endl;
}
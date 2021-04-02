#include <iostream>
#include "menu.h"


//全局变量
Student* STU;
Teacher* TEA;
int temp = 0;
int pos = 0;
int i = 0;


//主函数
int main()
{
  STU = (Student*)calloc(MAX_STU, sizeof(Student));
  TEA = (Teacher*)calloc(MAX_TEA, sizeof(Teacher));
  cout << "系统开始运行...\n";

  start();

  while (true){
    sams_menu();
    switch (get_cmd('1', '4'))
    {

      case '1': teacher_start();
        break;
      case '2': student_start();
        ; break;
      case '3':_add_tea(); break;
      case '4':sams_exit();   return 0;
    }
  }


}






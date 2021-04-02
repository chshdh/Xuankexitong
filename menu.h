//
// Created by 程硕 on 2021/4/2.
//

#ifndef DAIMA__MENU_H_
#define DAIMA__MENU_H_


typedef struct Student
{
  char name[20];
  char sex;
  char id[20];
  char passwd[20];
  short time;// 验证密码错误次数
  short birth;// 判断密码是否一致
  short  exist = -1;//判断是否选课
  int course[10] = { 0 };

}Student;
typedef struct Teacher
{
  char name[20];
  char sex;
  char id[20];
  char passwd[20];
  short time;
  short birth;
}Teacher;




#define MAX_STU 100
#define MAX_TEA 50
#include <iostream>
using  namespace std;
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>


extern Student;
extern   Teacher;
extern Student* STU;
extern Teacher* TEA;
extern int temp ;
extern int pos ;
extern int i ;




//函数声明






// 菜单
void sams_menu(void);
void student_menu(void);
void teacher_menu(void);
void student_class() ;


void start(void);
void sams_exit(void);
char* get_str(char* str, size_t len);//获取字符串;
char get_sex(void);
char get_cmd(char start, char end);
char* get_pw(char* passwd, bool is_show, size_t size);

//teacher
void teacher_start(void);
void _add_tea(void);
int teacher_login(void);
void teacher_ch_pw(void);
void teacher_add_stu(void);
void teacher_del_stu(void);
void teacher_find_stu(void);
void teacher_ch_stu_info(void);
void teacher_reset_stu_pw(void);
void teacher_list_stu(void);
void teacher_list_ubstu(void);

//student
void student_start(void);
int student_login(void);
void student_ch_pw(void);
void  input();
void  getCourseInfo();
void student_find_info(void);
void student_find_(void);
#endif //DAIMA__MENU_H_

#include <iostream>
#include <fstream>

using  namespace std;
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <stddef.h>

#include <stdio.h>
#define MAX_STU 100
#define MAX_TEA 50
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
//全局变量
Student* STU;
Teacher* TEA;
int temp = 0;
int pos = 0;
int i = 0;
//函数声明
void sams_menu(void);  //主菜单
void student_menu(void); // 学生菜单
void student_ch_pw(void);//  学生修改密码
char* get_pw(char* passwd, bool is_show, size_t size);//获取密码
void student_find_info(void);//查询选课
int student_login(void);//学生查询
void student_start(void);//学生登陆
void student_find_(void);//学生选课查询
void teacher_menu(void);// 老师子系统菜单
char get_sex(void);//获取性别
void teacher_add_stu(void);// 老师添加学生
void teacher_ch_stu_info(void);// 老师修改学生信息
void teacher_find_stu(void);// 老师查询学生
void teacher_reset_stu_pw(void);//老师重制密码
void teacher_list_stu(void);//显示选课
void teacher_list_ubstu(void);//未选课
void teacher_ch_pw(void);//老师修改密码
int teacher_login(void);//老师登陆
void _add_tea(void);//教师添加
char get_cmd(char start, char end);// 获取键盘指令
void teacher_start(void);// 运行老师子系统
void student_class();
void  input();//选课
void  getCourseInfo();
void clear_stdin(void);
void sams_exit(void);
void start(void);
void teacher_del_stu(void);


//主函数
int main()
{
    STU = (Student*)calloc(MAX_STU, sizeof(Student));
    TEA = (Teacher*)calloc(MAX_TEA, sizeof(Teacher));
    cout << "系统开始运行...\n";

   // start();

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


//主菜单
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


//void clear_stdin(void)






//操作


// 缓存
void start(void) {
    FILE* sfrp = fopen("stu.txt", "r");

    for (i = 0; i < 100; i++)
    {
        int num = 0;
        num = fscanf(sfrp, "%s %c %s %s  %hd %hd %hd %s", STU[i].name, &STU[i].sex, STU[i].id, STU[i].passwd, &STU[i].time, &STU[i].birth, &STU[i].exist, &STU[i].course);
    }
    fclose(sfrp);

    FILE* tfrp = fopen("tea.txt", "r");
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
    FILE* sfwp = fopen("stu.txt", "w");
    for (i = 0; i < 100; i++)
    {
        int num = 0;
        if (STU[i].sex != 0)
        {
            num = fprintf(sfwp, "%s %c %s %s %hd  %hd %hd %s\n", STU[i].name, STU[i].sex, STU[i].id, STU[i].passwd, STU[i].time, STU[i].birth, STU[i].exist, STU[i].course);
        }
    }
    fclose(sfwp);

    FILE* tfwp = fopen("tea.txt", "w");
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
        return NULL;
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
    while (true)
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


//老师操作


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
            cout << "姓名：" << STU[temp].name << endl << "性别：" << STU[temp].sex << endl << "学号: " << STU[temp].id << endl;
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
            // getchar();

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


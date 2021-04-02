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
    short time;// ��֤����������
    short birth;// �ж������Ƿ�һ��
    short  exist = -1;//�ж��Ƿ�ѡ��
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
//ȫ�ֱ���
Student* STU;
Teacher* TEA;
int temp = 0;
int pos = 0;
int i = 0;
//��������
void sams_menu(void);  //���˵�
void student_menu(void); // ѧ���˵�
void student_ch_pw(void);//  ѧ���޸�����
char* get_pw(char* passwd, bool is_show, size_t size);//��ȡ����
void student_find_info(void);//��ѯѡ��
int student_login(void);//ѧ����ѯ
void student_start(void);//ѧ����½
void student_find_(void);//ѧ��ѡ�β�ѯ
void teacher_menu(void);// ��ʦ��ϵͳ�˵�
char get_sex(void);//��ȡ�Ա�
void teacher_add_stu(void);// ��ʦ���ѧ��
void teacher_ch_stu_info(void);// ��ʦ�޸�ѧ����Ϣ
void teacher_find_stu(void);// ��ʦ��ѯѧ��
void teacher_reset_stu_pw(void);//��ʦ��������
void teacher_list_stu(void);//��ʾѡ��
void teacher_list_ubstu(void);//δѡ��
void teacher_ch_pw(void);//��ʦ�޸�����
int teacher_login(void);//��ʦ��½
void _add_tea(void);//��ʦ���
char get_cmd(char start, char end);// ��ȡ����ָ��
void teacher_start(void);// ������ʦ��ϵͳ
void student_class();
void  input();//ѡ��
void  getCourseInfo();
void clear_stdin(void);
void sams_exit(void);
void start(void);
void teacher_del_stu(void);


//������
int main()
{
    STU = (Student*)calloc(MAX_STU, sizeof(Student));
    TEA = (Teacher*)calloc(MAX_TEA, sizeof(Teacher));
    cout << "ϵͳ��ʼ����...\n";

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


//���˵�
void sams_menu(void)
{
    cout << ("***��ӭʹ��ָ��ѧ���ɼ�����ϵͳ***\n");
    cout << ("1����ʦ��ϵͳ\n");
    cout << ("2��ѧ����ϵͳ\n");
    cout << ("3�������ʦ�˺�\n");
    cout << ("4���˳�ϵͳ\n");
    cout << ("-----------------------------\n");
}
//ѧ���˵�
void student_menu(void)
{
    cout << ("����ѧ����ϵͳ...\n");
    cout << ("1���γ̹���\n");
    cout << ("2���޸�����\n");
    cout << ("3���鿴������Ϣ\n");
    cout << ("4��������һ��\n");
    cout << ("---------------\n");
}
// ��ʦ��ϵͳ�˵�
void teacher_menu(void)
{

    cout << "\n�����ʦ��ϵͳ...\n";
    cout << "1�����ѧ��\n";
    cout << "2��ɾ��ѧ��\n";
    cout << "3������ѧ��\n";
    cout << "4���޸�ѧ����Ϣ\n";
    cout << "5������ѧ������\n";
    cout << "6����ʾ�Ѿ�ѡ��ѧ��\n";
    cout << "7����ʾ����δѡ��ѧ��\n";
    cout << "8���޸��Լ�����\n";
    cout << "0��������һ��\n";
    cout << "-----------------\n";
}
//ѧ��ѡ�β˵�
void student_class() {

    cout << endl;
    cout << " ѧ��ѡ��ϵͳ " << endl;
    cout << " 1. ѡ��γ� " << endl;
    cout << " 2. ɾ����Ϣ " << endl;
    cout << " 0. �˳����� " << endl;
}


//void clear_stdin(void)






//����


// ����
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

//��������
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
//��ȡ�Ա�
char get_sex(void)
{
    cout << "��m�У�wŮ����";
    while (true)
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


//��ʦ����


// ������ʦ��ϵͳ
void teacher_start(void)
{

    pos = teacher_login();
    if (pos == -1)
    {
        cout << "��¼ʧ��!\n";
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
//�����ʦ
void _add_tea(void)
{
    cin.ignore();
    cout << "��ӽ�ʦ\n";
    char Cteacher_name[20];
    char Cteacher_sex;
    char Cteacher_id[20];
    char Cteacher_pw[20];
    cout << "�������ʦ������";
    get_str(Cteacher_name, 20);
    cout << "�������ʦ�Ա�";
    Cteacher_sex = get_sex();
    cout << "�������ʦ���ţ�";
    get_str(Cteacher_id, 20);
    cout << "�������ʦ���룺";
    get_str(Cteacher_pw, 20);
    int pos = -1; //�����λ��
    cout << TEA[0].id << endl;
    for (i = 0; i < 50; i++)
    {
        if (TEA[i].sex == '\0' && pos == -1)
        {
            cout << "pos�Ѷ�λ\n";
            pos = i;
        }
        if (strcmp(TEA[i].id, Cteacher_id) == 0)
        {
            cout << "�����ظ������������룡\n";
            break;
        }
        if (i == 49)
        {
            strcpy_s(TEA[pos].name, Cteacher_name);
            TEA[pos].sex = Cteacher_sex;
            strcpy_s(TEA[pos].id, Cteacher_id);
            strcpy_s(TEA[pos].passwd, Cteacher_pw);
            cout << "��ӳɹ���\n";
        }
    }
    cout << TEA[0].id << endl;
}
// ��ʦ��¼
int teacher_login(void)
{
    cin.ignore();

    char Cteacher_id[20] = {};
    char Cteacher_pw[20] = {};
    cout << "�������û���:";
    get_str(Cteacher_id, 20);
    if (Cteacher_id[0] == '\0')
    {
        cout << "�û�������Ϊ�գ�\n";
        return -1;
    }
    cout << "�û�: " << Cteacher_id << endl;
    cout << "����������:";
    get_pw(Cteacher_pw, true, 20);
    cout << endl;
    for (i = 0; i < 50; i++)
    {
        if (strcmp(Cteacher_id, TEA[i].id) == 0)
        {
            if (TEA[i].time == 3)
            {
                cout << "�˹����ѱ�������\n";
                return -1;
            }

            if (strcmp(Cteacher_pw, TEA[i].passwd) == 0)
            {
                return i;
            }
            else
            {
                TEA[i].time++;
                cout << "�������.\n";
                return -1;
            }
        }
    }
    cout << "�����ڴ˽�ʦ��\n";
    return -1;
}
// ��ʦ�޸�����
void teacher_ch_pw(void)
{
    cin.ignore();
    char old_pw[20] = {};
    char new_pw[20] = {};
    char new_two_pw[20] = {};
    cout << "������ԭ���룺";
    get_pw(old_pw, true, 20);
    cout << endl;
    cout << "�����������룺";
    get_pw(new_pw, true, 20);
    cout << endl;
    cout << "���ٴ����������룺";
    get_pw(new_two_pw, true, 20);
    cout << endl;
    if (strcmp(old_pw, TEA[pos].passwd) == 0)
    {
        if (strcmp(new_pw, new_two_pw) == 0)
        {
            cout << "�޸�����ɹ�\n";
            if (TEA[pos].birth == 0)
            {
                TEA[pos].birth = 1;
            }
            strcpy_s(TEA[pos].passwd, new_pw);
        }
        else
        {
            cout << "�������벻һ��\n";
        }
    }
    else
    {
        cout << "ԭ�������\n";
    }
}
// ��ʦ���ѧ��
void teacher_add_stu(void)
{
    cin.ignore();
    cout << "���ѧ��\n";
    char Cstudent_name[20];
    char Cstudent_sex;
    char Cstudent_id[20];
    char Cstudent_pw[20];
    cout << "������ѧ��������";
    get_str(Cstudent_name, 20);
    cout << "������ѧ���Ա�";
    Cstudent_sex = get_sex();
    cout << "������ѧ�ţ�";
    get_str(Cstudent_id, 20);
    cout << "������ѧ�����룺";
    get_str(Cstudent_pw, 20);
    int pos = -1; //�����λ��
    cout << STU[0].id << endl;
    for (i = 0; i < 100; i++)
    {
        if (STU[i].sex == '\0' && pos == -1)
        {
            cout << "pos�Ѷ�λ\n";
            pos = i;
        }
        if (strcmp(STU[i].id, Cstudent_id) == 1)
        {
            cout << "ѧ���ظ������������룡\n";
            break;
        }
        if (i == 99)
        {
            strcpy_s(STU[pos].name, Cstudent_name);
            STU[pos].sex = Cstudent_sex;
            strcpy_s(STU[pos].id, Cstudent_id);
            strcpy_s(STU[pos].passwd, Cstudent_pw);
            cout << "��ӳɹ���\n";
        }
    }
    cout << STU[0].id << endl;
}
// ��ʦɾ��ѧ��
void teacher_del_stu(void)
{
    cin.ignore();
    cout << "ɾ��ѧ��\n";
    cout << "������ѧ��ѧ��:";
    char Cstudent_id[20] = {};
    get_str(Cstudent_id, 20);
    for (i = 0; i < 100; i++)
    {
        if (strcmp(Cstudent_id, STU[i].id) == 0)
        {
            STU[i].exist = 1;
            cout << "ɾ���ɹ���\n";
            break;
        }
        if (i == 99)
        {
            cout << "�޴�ѧ�ţ�\n";
        }
    }

}
// ��ʦ��ѯѧ��
void teacher_find_stu(void)
{
    cin.ignore();
    cout << "������ѧ��ѧ�ţ�";
    char Cstudent_id[20] = {};
    get_str(Cstudent_id, 20);
    for (i = 0; i < 100; i++)
    {
        if (strcmp(Cstudent_id, STU[i].id) == 0)
        {
            cout << "������" << STU[temp].name << endl << "�Ա�" << STU[temp].sex << endl << "ѧ��: " << STU[temp].id << endl;
            if (STU[i].exist == 0) {
                cout << "��ѧ����δѡ�Σ�" << endl;


            }
            else {
                for (int q = 0; q <= STU[i].exist; q++) {
                    cout << "��ͬѧѡ�εĿ����Ϊ";
                    cout << STU[i].course[q] << "  ";
                }
            }
            break;
        }
        else if (i == 99)
        {
            cout << "�޴�ѧ�š�\n";
        }
    }
}
// ��ʦ�޸�ѧ����Ϣ
void teacher_ch_stu_info(void)
{
    cin.ignore();
    cout << "������ѧ��ѧ�ţ�";
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
            cout << "��������������";
            get_str(ch_name, 20);
            cout << "���������Ա�";
            cin >> ch_sex;
            // getchar();

            cout << "��������ѧ�ţ�";
            get_str(ch_id, 20);

            strcpy_s(STU[i].name, ch_name);
            STU[i].sex = ch_sex;
            strcpy_s(STU[i].id, ch_id);

            cout << "��Ϣ�޸ĳɹ���\n";
            break;
        }
        else if (i == 99)
        {
            cout << "�޴�ѧ�š�\n";
        }
    }
}
// ��ʦ����ѧ������
void teacher_reset_stu_pw(void)
{
    cin.ignore();
    cout << "��������\n";
    cout << "������ѧ��ѧ�ţ�";
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
            cout << "���óɹ���\n";
            break;
        }
        if (i == 99)
        {
            cout << "�޴�ѧ��.\n";
        }
    }
}
// ��ʦ��ʾѡ��ѧ���б�
void teacher_list_stu(void)
{
    cin.ignore();
    cout << "��ʾѡ��ѧ��";
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
// ��ʦ��ʾδѡ��ѧ���б�
void teacher_list_ubstu(void)
{
    cin.ignore();
    cout << "��ʾδѡ��ѧ��";
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


//ѧ������

//ѧ����ʼϵͳ
void student_start(void)
{
    temp = student_login();
    if (temp == -1)
    {
        cout << "��¼ʧ��!\n";
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
//ѧ����½
int student_login(void)
{
    cin.ignore();
    char Cstudent_id[20] = {};
    char Cstudent_pw[20] = {};
    cout << ("�������û���:");
    get_str(Cstudent_id, 20);
    if (Cstudent_id[0] == '\0')
    {
        cout << ("�û�������Ϊ�գ�\n");
        return -1;
    }
    cout << "�û�: " << Cstudent_id << endl;
    cout << ("����������:");
    get_pw(Cstudent_pw, true, 20);
    cout << ("\n");
    for (i = 0; i < 100; i++)
    {
        if (strcmp(Cstudent_id, STU[i].id) == 0)
        {
            if (STU[i].time == 3)
            {
                cout << "��ѧ���ѱ�������\n";
                return -1;
            }

            if (strcmp(Cstudent_pw, STU[i].passwd) == 0)
            {
                return i;
            }
            else
            {
                STU[i].time++;
                cout << "�������.\n";
                return -1;
            }
        }
    }
    cout << "�����ڴ�ѧ����\n";
    return -1;
}
//ѧ���޸�����
void student_ch_pw(void)
{
    char old_stu_pw[20] = {};
    char new_stu_pw[20] = {};
    char new_stu_two_pw[20] = {};
    cout << ("������ԭ���룺");
    get_pw(old_stu_pw, true, 20);
    cout << "\n";
    cout << ("�����������룺");
    get_pw(new_stu_pw, true, 20);
    cout << "\n";
    cout << ("���ٴ����������룺");
    get_pw(new_stu_two_pw, true, 20);
    cout << endl;
    if (strcmp(old_stu_pw, STU[temp].passwd) == 0)
    {
        if (strcmp(new_stu_pw, new_stu_two_pw) == 0)
        {
            cout << ("�޸�����ɹ�\n");
            if (STU[temp].birth == 0)
            {
                STU[temp].birth = 1;
            }
            strcpy_s(STU[temp].passwd, new_stu_pw);
        }
        else
        {
            cout << "�������벻һ��\n";
        }
    }
    else
    {
        cout << "ԭ�������\n";
    }
}
//ѧ��ѡ��
void  input() {
    cout << "����ѡ��Ŀγ����(1,2,3,4,5,6,7,8,9)" << endl;
    int a;
    cin >> a;
    for (int i = 0; i < 10; i++)
    {
        if (STU[temp].course[i] == a) {
            cout << "���Ѿ�ѡ���ÿγ�" << endl; break;
        }
        else
        {
            STU[temp].exist++;
            a = STU[temp].course[STU[temp].exist];

            cout << "ѡ�γɹ���"; break;
        }
    }
}//ѧ��ѡ��
//ѧ��ɾ���γ�
void  getCourseInfo() {
    cout << "������ɾ���Ŀγ����" << endl;
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
            cout << "��δѡ���˿γ�" << endl;

        }
    }
}
//ѡ�β�ѯ
void student_find_info(void)
{
    cout << ("������Ϣ\n");
    cout << "������" << STU[temp].name << endl << "�Ա�" << STU[temp].sex << endl << STU[temp].id << endl;
    if (STU[i].exist == 0) {
        cout << "�㻹δѡ�Σ�" << endl;


    }
    else {
        for (int q = 0; q <= STU[i].exist; q++) {
            cout << "��ѡ�εĿ����Ϊ";
            cout << STU[i].course[q] << "  ";
        }
    }
}
//ѧ����ѯ������Ϣ
void student_find_(void)//ѧ��ѡ�β�ѯ
{
    student_class();
    switch (get_cmd('1', '4'))
    {
        case '1': input(); break;
        case '2': getCourseInfo(); break;
        case'0':return;
    }
}


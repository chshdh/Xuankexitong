//
// Created by ��˶ on 2021/4/2.
//
#include "menu.h"
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


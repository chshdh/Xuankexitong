//
// Created by ��˶ on 2021/4/2.
//


//��ʦ����

#include "menu.h"
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
  cin.ignore();
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
      cout << "������" << STU[i].name << endl << "�Ա�" << STU[i].sex << endl << "ѧ��: " << STU[i].id << endl;
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

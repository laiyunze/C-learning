#include <iostream>
#include <string>
using namespace std;
const int MAX = 1000;
struct contact
{
	string name; //����
	int gender; //�Ա� 1.�� 2.Ů
	int age; //����
	string phone_number; //�绰
	string address; //סַ
};
struct addressBook
{
	contact arrperson[MAX]; //��ϵ������
	int size; //��ǰ�����С
};
void addPerson(addressBook* adb);
void showMenu();
void showPerson(const addressBook* adb);
void delPerson(addressBook* adb);
void findPerson(const addressBook* adb);
void modPerson(addressBook* adb);
void clsPerson(addressBook* adb);
int main()
{
	//�û�ѡ��
	int select = 0; 
	//����ͨѶ¼����
	addressBook adb;
	adb.size = 0;
	//�˵�����
	while (1)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
			case 1: //1.�����ϵ��
				addPerson(&adb);
				break;
			case 2: //2.��ʾ��ϵ��
				showPerson(&adb);
				break;
			case 3: //3.ɾ����ϵ��
				delPerson(&adb);
				break;
			case 4: //4.������ϵ��
				findPerson(&adb);
				break;
			case 5: //5.�޸���ϵ��
				modPerson(&adb);
				break;
			case 6: //6.�����ϵ��
				clsPerson(&adb);
				break;
			case 0: //0.�˳�ͨѶ¼
				cout << "��ӭ�´�ʹ�ã�\n";
				system("pause");
				return 0;
				break;
			default:
				break;
		}
	}
		

	system("pause");
	return 0;
}
//�˵�����
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** 1.�����ϵ�� *****" << endl;
	cout << "***** 2.��ʾ��ϵ�� *****" << endl;
	cout << "***** 3.ɾ����ϵ�� *****" << endl;
	cout << "***** 4.������ϵ�� *****" << endl;
	cout << "***** 5.�޸���ϵ�� *****" << endl;
	cout << "***** 6.�����ϵ�� *****" << endl;
	cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
	cout << "************************" << endl;
}
//�����ϵ��
void addPerson(addressBook* adb)
{
	//�ж�ͨѶ¼�Ƿ���
	if (adb->size == MAX)
	{
		cout << "ͨѶ¼����,�޷���ӣ�\n";
		return;
	} 
	else
	{
		//����
		string name;
		cout << "����������: \n";
		cin >> name;
		adb->arrperson[adb->size].name = name;
		//�Ա�
		cout << "�������Ա�: \n";
		cout << "1---��: \n";
		cout << "2---Ů: \n";
		cout << "�������Ա�: \n";
		int sex = 0;
		while (1)
		{
			cin >> sex;
			if (1 == sex || 2 == sex)
			{
				adb->arrperson[adb->size].gender = sex;
				break;
			}
			else
			{
				cout << "�����������������룡\n";
			}
		}
		//����
		cout << "����������: \n";
		int age = 0;
		while (1)
		{
			cin >> age;
			if (age > 0 && age < 110)
			{
				adb->arrperson[adb->size].age = age;
				break;
			}
			else
			{
				cout << "�����������������룡\n";
			}
		}
		//�绰
		cout << "������绰: \n";
		string num;
		while (1)
		{
			cin >> num;
			//�жϵ绰��ʽ�Ƿ���ȷ,��ȷ������ѭ����
			if (size(num) == 11)
			{
				adb->arrperson[adb->size].phone_number = num;
				break;
			}
			else
			{
				cout << "�����������������룡\n";
			}
		}
		//סַ
		cout << "������סַ: \n";
		string add;
		/*cin.get();
		getline(cin, add);*/
		cin >> add;
		adb->arrperson[adb->size].address = add;
	}
	cout << "��ӳɹ�����\n";
	adb->size++;
	system("pause");
	system("cls");
}
void showPerson(const addressBook* adb)
{
	if (adb->size == 0)
	{
		cout << "�ܱ�Ǹ��������ϵ�ˣ�" << endl;
	}
	else
	{
		for (int i = 0; i < adb->size; i++)
		{
			cout << "��ϵ��#" << i + 1 << endl;
			cout << "����: " << adb->arrperson[i].name << "   ";
			if (adb->arrperson[i].gender == 1)
				cout << "�Ա�: ��" << "   ";
			else
				cout << "�Ա�: Ů" << "   ";
			cout << "����: " << adb->arrperson[i].age << "   ";
			cout << "�绰: " << adb->arrperson[i].phone_number << "   ";
			cout << "��ַ: " << adb->arrperson[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}
void delPerson(addressBook* adb)
{
	if (adb->size == 0)
	{
		cout << "�ܱ�Ǹ��������ϵ�ˣ�" << endl;
	}
	else
	{
		cout << "��������Ҫɾ������ϵ��: ";
		string name;
		int i;
		cin >> name;
		for (i = 0; i < adb->size; i++)
		{
			if (adb->arrperson[i].name == name)
			{
				for (int x = i; x < adb->size; x++)
				{
					//����ɾ������ϵ�˸�����һ����ϵ�˵�ֵ
					adb->arrperson[x] = adb->arrperson[x + 1];
					
				}
				//ɾ�����ȥͨѶ¼�е�����
				adb->size--;
			}
		}
		cout << "ɾ���ɹ���\n";
	}
	system("pause");
	system("cls");
}
void findPerson(const addressBook* adb)
{
	if (adb->size == 0)
	{
		cout << "�ܱ�Ǹ��������ϵ�ˣ�" << endl;
	}
	else
	{
		cout << "��������Ҫ��ѯ����ϵ��: ";
		string name;
		int i;
		cin >> name;
		for (i = 0; i < adb->size; i++)
		{
			if (adb->arrperson[i].name == name)
			{
				cout << "��ϵ��#" << i + 1 << endl;
				cout << "����: " << adb->arrperson[i].name << "   ";
				if (adb->arrperson[i].gender == 1)
					cout << "�Ա�: ��" << "   ";
				else
					cout << "�Ա�: Ů" << "   ";
				cout << "����: " << adb->arrperson[i].age << "   ";
				cout << "�绰: " << adb->arrperson[i].phone_number << "   ";
				cout << "��ַ: " << adb->arrperson[i].address << endl;
			}
		}
		cout << "��ѯ��ϣ�\n";
	}
	system("pause");
	system("cls");
}
void modPerson(addressBook* adb)
{
	if (adb->size == 0)
	{
		cout << "�ܱ�Ǹ��������ϵ�ˣ�" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸ĵ���ϵ��: ";
		string name;
		int i;
		cin >> name;
		for (i = 0; i < adb->size; i++)
		{
			if (adb->arrperson[i].name == name)
			{
				string n;
				cout << "�������޸ĵ����֣�";
				cin >> n;
				adb->arrperson[i].name = n;
			}
		}
		cout << "�޸ĳɹ���\n";
	}
	system("pause");
	system("cls");
}
void clsPerson(addressBook* adb)
{
	if (adb->size == 0)
	{
		cout << "�ܱ�Ǹ��������ϵ�ˣ�" << endl;
	}
	else
	{
		adb->size = 0;
		cout << "ɾ���ɹ���\n";
	}
	system("pause");
	system("cls");
}
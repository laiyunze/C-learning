#include <iostream>
#include <string>
using namespace std;
const int MAX = 1000;
struct contact
{
	string name; //姓名
	int gender; //性别 1.男 2.女
	int age; //年龄
	string phone_number; //电话
	string address; //住址
};
struct addressBook
{
	contact arrperson[MAX]; //联系人数组
	int size; //当前数组大小
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
	//用户选择
	int select = 0; 
	//创建通讯录对象
	addressBook adb;
	adb.size = 0;
	//菜单调用
	while (1)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
			case 1: //1.添加联系人
				addPerson(&adb);
				break;
			case 2: //2.显示联系人
				showPerson(&adb);
				break;
			case 3: //3.删除联系人
				delPerson(&adb);
				break;
			case 4: //4.查找联系人
				findPerson(&adb);
				break;
			case 5: //5.修改联系人
				modPerson(&adb);
				break;
			case 6: //6.清空联系人
				clsPerson(&adb);
				break;
			case 0: //0.退出通讯录
				cout << "欢迎下次使用！\n";
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
//菜单界面
void showMenu()
{
	cout << "************************" << endl;
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4.查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
	cout << "************************" << endl;
}
//添加联系人
void addPerson(addressBook* adb)
{
	//判断通讯录是否满
	if (adb->size == MAX)
	{
		cout << "通讯录已满,无法添加！\n";
		return;
	} 
	else
	{
		//姓名
		string name;
		cout << "请输入姓名: \n";
		cin >> name;
		adb->arrperson[adb->size].name = name;
		//性别
		cout << "请输入性别: \n";
		cout << "1---男: \n";
		cout << "2---女: \n";
		cout << "请输入性别: \n";
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
				cout << "输入有误，请重新输入！\n";
			}
		}
		//年龄
		cout << "请输入年龄: \n";
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
				cout << "输入有误，请重新输入！\n";
			}
		}
		//电话
		cout << "请输入电话: \n";
		string num;
		while (1)
		{
			cin >> num;
			//判断电话格式是否正确,正确则跳出循环；
			if (size(num) == 11)
			{
				adb->arrperson[adb->size].phone_number = num;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入！\n";
			}
		}
		//住址
		cout << "请输入住址: \n";
		string add;
		/*cin.get();
		getline(cin, add);*/
		cin >> add;
		adb->arrperson[adb->size].address = add;
	}
	cout << "添加成功！！\n";
	adb->size++;
	system("pause");
	system("cls");
}
void showPerson(const addressBook* adb)
{
	if (adb->size == 0)
	{
		cout << "很抱歉，暂无联系人！" << endl;
	}
	else
	{
		for (int i = 0; i < adb->size; i++)
		{
			cout << "联系人#" << i + 1 << endl;
			cout << "姓名: " << adb->arrperson[i].name << "   ";
			if (adb->arrperson[i].gender == 1)
				cout << "性别: 男" << "   ";
			else
				cout << "性别: 女" << "   ";
			cout << "年龄: " << adb->arrperson[i].age << "   ";
			cout << "电话: " << adb->arrperson[i].phone_number << "   ";
			cout << "地址: " << adb->arrperson[i].address << endl;
		}
	}
	system("pause");
	system("cls");
}
void delPerson(addressBook* adb)
{
	if (adb->size == 0)
	{
		cout << "很抱歉，暂无联系人！" << endl;
	}
	else
	{
		cout << "请输入你要删除的联系人: ";
		string name;
		int i;
		cin >> name;
		for (i = 0; i < adb->size; i++)
		{
			if (adb->arrperson[i].name == name)
			{
				for (int x = i; x < adb->size; x++)
				{
					//给被删除的联系人附上下一个联系人的值
					adb->arrperson[x] = adb->arrperson[x + 1];
					
				}
				//删除后减去通讯录中的人数
				adb->size--;
			}
		}
		cout << "删除成功！\n";
	}
	system("pause");
	system("cls");
}
void findPerson(const addressBook* adb)
{
	if (adb->size == 0)
	{
		cout << "很抱歉，暂无联系人！" << endl;
	}
	else
	{
		cout << "请输入你要查询的联系人: ";
		string name;
		int i;
		cin >> name;
		for (i = 0; i < adb->size; i++)
		{
			if (adb->arrperson[i].name == name)
			{
				cout << "联系人#" << i + 1 << endl;
				cout << "姓名: " << adb->arrperson[i].name << "   ";
				if (adb->arrperson[i].gender == 1)
					cout << "性别: 男" << "   ";
				else
					cout << "性别: 女" << "   ";
				cout << "年龄: " << adb->arrperson[i].age << "   ";
				cout << "电话: " << adb->arrperson[i].phone_number << "   ";
				cout << "地址: " << adb->arrperson[i].address << endl;
			}
		}
		cout << "查询完毕！\n";
	}
	system("pause");
	system("cls");
}
void modPerson(addressBook* adb)
{
	if (adb->size == 0)
	{
		cout << "很抱歉，暂无联系人！" << endl;
	}
	else
	{
		cout << "请输入你要修改的联系人: ";
		string name;
		int i;
		cin >> name;
		for (i = 0; i < adb->size; i++)
		{
			if (adb->arrperson[i].name == name)
			{
				string n;
				cout << "请输入修改的名字：";
				cin >> n;
				adb->arrperson[i].name = n;
			}
		}
		cout << "修改成功！\n";
	}
	system("pause");
	system("cls");
}
void clsPerson(addressBook* adb)
{
	if (adb->size == 0)
	{
		cout << "很抱歉，暂无联系人！" << endl;
	}
	else
	{
		adb->size = 0;
		cout << "删除成功！\n";
	}
	system("pause");
	system("cls");
}
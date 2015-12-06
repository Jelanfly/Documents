// 计算机组成原理23333.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

class Math//booth法主要类
{
private:
	string Total;
	string Num_1;
	string Num_2;
	string Num_1_C;
	string F_Num_1_C;
	string Num_2_C;
	string Part;
	string Multiplicator;
public:
	Math()
	{};
	~Math()
	{};
	void Fun();//function函数
	void GetComplement();//记得x首位加0/1、/整个取补码工作均在此进行
	//	void GC(string &a,string &b);
	//void QuFan(string &a,string b);
	void YiWei(string &a, string &b);//移位函数
	//void DeleteDoit(string &a);
	int Sum(string &a, string &b);//二进制加法函数
};
void Math::YiWei(string &a, string &b)
{
	for (unsigned int i = b.length() - 1; i > 0; i--)
	{
		b[i] = b[i - 1];
	}
	b[0] = a[a.length() - 1];
	for (unsigned int i = a.length() - 1; i > 3; i--)
	{
		a[i] = a[i - 1];
	}
	a[3] = a[1];//符号位移入数值位
	/*string temp = a + b;
	temp = temp[0] + temp;
	unsigned int i = 0;
	for (; i < a.length(); i++)
	{
		a[i] = temp[i];
	}
	for (i = 0; i < b.length(); i++)
	{
		b[i] = temp[i + a.length()];
	}*/
}
int Math::Sum(string &a, string &b)
{
 	unsigned int Length_a = a.length();
	unsigned int Length_b = b.length();
	if (Length_a != Length_b)
	{
		cout << "求和两数位数不同！" << endl;
		return -1;
	}
	else
	{
		int s = 0;
		/*string temp;
		for (unsigned int i = 0; i < Length_a; i++)
		{
		temp = temp + "0";
		}*/
		for (unsigned int i = Length_a - 1; i > 2; i--)//循环而不是递归更易掌控
		{
			//	temp[Length_a - i - 1] = 
			if ((a[i] == '1'&&b[i] == '0') || (b[i] == '1'&&a[i] == '0'))
			{
				if (s == 0)
				{
					a[i] = '1';
					s = 0;
				}
				else if (s == 1)
				{
					a[i] = '0';
					s = 1;
				}
			}
			else if (a[i] == '1'&&b[i] == '1')
			{
				if (s == 0)
				{
					a[i] = '0';
					s = 1;
				}
				else if (s == 1)
				{
					a[i] = '1';
					s = 1;
				}
				s = 1;
			}
			else if (a[i] == '0'&&b[i] == '0')
			{
				if (s == 0)
				{
					a[i] = '0';
					s = 0;
				}
				else if (s == 1)
				{
					a[i] = '1';
					s = 0;
				}
			}//
		}
		if (b[2] != '0')//取决于fun函数中会有两重情况运用到sum函数，其中一种没有.所以b[2]==‘0’
		{
			if (a[0] == b[0] && a[0] == '0')
			{
				if (s == 1)
				{
					a[0] = '1';
					a[1] = '1';
					a[2] = '.';
				}
			}
			if ((a[0] == '1'&&b[0] == '0') || (a[0] == '0'&&b[0] == '1'))
			{
				if (s == 0)
				{
					a[0] = '1';
					a[1] = '1';
					a[2] = '.';
				}
				if (s == 1)
				{
					a[0] = '0';
					a[1] = '0';
					a[2] = '.';
				}
			}
		}
	}
	return 0;
}
void Math::GetComplement()//取补码，相反数补码并消去点号增加首位等工作
{
	unsigned int n = 0;
	string num_1 = "1";
	string num_0 = "0";
	if (Num_1[0] == '-')
	{
		Num_1_C = Num_1_C + "11.";
		n = Num_1.length() - 3;
		for (unsigned int i = 0; i < n; i++)
		{
			if (Num_1[3 + i] == '0')
			{
				Num_1_C = Num_1_C + num_1;
			}
			else if (Num_1[3 + i] == '1')
			{
				Num_1_C = Num_1_C + num_0;
			}
		}
		string temp;
		unsigned int temp_n = Num_1.length() - 1;
		for (unsigned int i = 0; i < temp_n; i++)
		{
			temp = temp + Num_1[i + 1];
		}
		F_Num_1_C = F_Num_1_C + "00.";
		temp_n = temp.length() - 2;
		for (unsigned int i = 0; i < temp_n; i++)
		{
			if (temp[2 + i] == '0')
			{
				F_Num_1_C = F_Num_1_C + num_0;
			}
			else if (temp[2 + i] == '1')
			{
				F_Num_1_C = F_Num_1_C + num_1;
			}
		}
		temp = "";
		for (unsigned int i = 1; i < Num_1_C.length(); i++)
		{
			temp = temp + "0";
		}
		temp = temp + "1";
		Sum(Num_1_C, temp);
		//Sum(F_Num_1_C, temp);
	}
	else if (Num_1[0] == '0')
	{
		Num_1_C = Num_1_C + "00.";
		n = Num_1.length() - 2;
		for (unsigned int i = 0; i < n; i++)
		{
			if (Num_1[2 + i] == '0')
			{
				Num_1_C = Num_1_C + num_0;
			}
			else if (Num_1[2 + i] == '1')
			{
				Num_1_C = Num_1_C + num_1;
			}
		}
		F_Num_1_C = F_Num_1_C + "11.";
		unsigned int temp_n = Num_1.length() - 2;
		for (unsigned int i = 0; i < temp_n; i++)
		{
			if (Num_1[2 + i] == '0')
			{
				F_Num_1_C = F_Num_1_C + num_1;
			}
			else if (Num_1[2 + i] == '1')
			{
				F_Num_1_C = F_Num_1_C + num_0;
			}
		}
		string temp;
		for (unsigned int i = 1; i < Num_1_C.length(); i++)
		{
			temp = temp + "0";
		}
		temp = temp + "1";
		//Sum(Num_1_C, temp);
		Sum(F_Num_1_C, temp);
	}

	//以上全是第一个数，求了x的补跟-x的补……太鸡巴累了绝对会报错……
	if (Num_2[0] == '0')
	{
		Num_2_C = Num_2_C + "0";
		unsigned int temp = Num_2.length() - 2;
		for (unsigned int i = 0; i < temp; i++)
		{
			Num_2_C = Num_2_C + Num_2[i + 2];
		}
		//Num_2_C = Num_2_C + "0";
	}
	else if (Num_2[0] == '-')
	{
		Num_2_C = Num_2_C + "1";
		unsigned int temp = Num_2.length() - 3;
		for (unsigned int i = 0; i < temp; i++)
		{
			if (Num_2[i + 3] == '0')
			{
				Num_2_C = Num_2_C + num_1;
			}
			else if (Num_2[i + 3] == '1')
			{
				Num_2_C = Num_2_C + num_0;
			}
		}
		string Temp;
		for (unsigned int i = 1; i < Num_2_C.length(); i++)
		{
			Temp = Temp + "0";
		}
		Temp = Temp + "1";
		int s = 0;
		for (unsigned int i = Temp.length() - 1; i >0; i--)
		{
			if (Temp[i] == Num_2_C[i] && Temp[i] == '0')
			{
				if (s == 0)
				{
					Num_2_C[i] = '0';
					s = 0;
				}
				else if (s == 1)
				{
					Num_2_C[i] = '1';
					s = 0;
				}
			}
			if (Temp[i] == Num_2_C[i] && Temp[i] == '1')
			{
				if (s == 0)
				{
					Num_2_C[i] = '0';
					s = 1;
				}
				else if (s == 1)
				{
					Num_2_C[i] = '1';
					s = 1;
				}
			}
			if (Num_2_C[i] == '0' && Temp[i] == '1' || Num_2_C[i] == '1' && Temp[i] == '0')
			{
				if (s == 0)
				{
					Num_2_C[i] = '1';
					s = 0;
				}
				else if (s == 1)
				{
					Num_2_C[i] = '0';
					s = 1;
				}
			}
		}
		//Sum(Num_2_C, Temp);
		//Sum(F_Num_1_C, Temp);
		//	Num_2_C = Num_2_C + "0";
	}
}
void Math::Fun(){
	cin >> Total;
	int i = 0;
	for (i = 0; Total[i] != ','; i++)
	{
		if (Total[i] != '+')
		{
			Num_1 = Num_1 + Total[i];
		}
	}
	i++;
	for (int i_ = 0; Total[i] != '\0'; i++, i_++)
	{
		if (Total[i] != '+')
		{
			Num_2 = Num_2 + Total[i];
		}
	}//分离函数两部分
	GetComplement();//取补码
	for (unsigned int i_ = 0; i_ < Num_1_C.length(); i_++)
	{
		Part = Part + "0";
	}
	Part[2] = '.';
	//DeleteDoit(Num_2_C);
	Multiplicator = Num_2_C + "0";//首位加0
	for (i = 0; (unsigned)i < Multiplicator.length() - 1; i++)//开始循环循环次数又被乘数位数计算出
	{
		string temp;
		temp = temp + Multiplicator[Multiplicator.length() - 1];
		temp = temp + Multiplicator[Multiplicator.length() - 2];
		if (temp == "00" || temp == "11")
		{

		}
		else if (temp == "01")
		{
			Sum(Part, F_Num_1_C);
		}
		else if (temp == "10")
		{
			Sum(Part, Num_1_C);
		}
		if (i != Multiplicator.length() - 2)
		{
			YiWei(Part, Multiplicator);
		}
	}
	string end;
	end = end + Part;
	for (unsigned int i = 0; i < Multiplicator.length() - 2; i++)
	{
		end = end + Multiplicator[i];
	}
	if (end[0] == '1')
	{
		for (unsigned int i = end.length() - 1; i>=0; i--)
		{
				if (end[i] == '1')
				{
					end[i] = '0';
					break;
				}
				else if (end[i] == '0')
				{
					end[i] = '1';
				}
		}
		string End = "-0.";
		for (unsigned int i = 3; i < end.length(); i++)
		{
			if (end[i] == '1')
			{
				End = End + "0";
			}
			else if (end[i] == '0')
			{
				End = End + "1";
			}
		}
		if (End[0] == '-')
		{
			cout << End;//输出结果
		}
		else
		{
			End = "+" + End;
			cout << End;
		}
	}
	else if (end[0] == '0')
	{
		string End = "0.";
		for (unsigned int i = 3; i < end.length(); i++)
		{
			End = End + end[i];
		}
		if (End[0] == '-')
		{
			cout << End;//输出结果
		}
		else
		{
			End = "+" + End;
			cout << End;
		}
		//cout << End;//输出结果
	}
	//cout << end << endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	Math a;
	a.Fun();
	//system("pause");
	return 0;
}


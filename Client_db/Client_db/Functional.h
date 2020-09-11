#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::SqlClient;
using namespace System::Drawing::Printing;

enum accesses { director=0, admin=1, cashier=2 }; //��������� ������ �������

ref struct FilterType //��������� �������� �������� ��������
{
	int count; //����� ������� (�������)
	array<String^>^ value; //������� ������

	//������������
	FilterType() :count(0) {};
	FilterType(int n, array<String^>^ val) :count(n), value(val) {}

	PrintDocument^ printDocument = gcnew PrintDocument();
};

ref class Functional
{
public:
	//������� ������� (����� �������,������� �������,����������/��������������/��������)
	static const array<const bool, 3>^ matrixAccess =
	{ {{0,0,0},{0,1,1},{1,0,0}},
	{{1,1,1},{0,0,0},{0,0,0}},
	{{1,0,1},{0,1,0},{0,0,0}},
	{{0,0,0},{0,1,1},{1,0,0}},
	{{0,0,0},{0,1,1},{1,0,0}},
	{{0,0,0},{1,1,1},{0,0,0}},
	{{0,0,0},{1,1,1},{0,0,0}},
	{{0,0,0},{1,1,1},{0,0,0}},
	{{0,0,0},{0,0,0},{0,0,0}} };

	// ������, ���������� �������� ���� ������
	static const array<String^>^ allTableNames = { "dbo.�������","dbo.����������","dbo.�������",
		"dbo.��������","dbo.������","dbo.��������","dbo.�������","dbo.Users","dbo.������_�����" };

	static String^ user; //����� ������������
	static accesses access; //������� ������� �������� �����
	static SqlConnection^ conn; //����������� � �������
	static SqlConnectionStringBuilder^ connStringBuilder; // ������ ��� �����������
	static String^ tableName; //�������� ������� �������
	static int tabNum; //����� ������� �������

	Functional(){} //������ �����������

	//������� ��������� ���������� � ��������
	static void ConnectToDB();
	//����� ���� �����-������ � ������� "Users"
	static bool Functional::FindUser(String^ log, String^ pas);

	//static void FillSource(DataGridView^ DataGV);
	//��������� ������� ������� � ������� � ������ ��������
	static void FillSource(DataGridView^ DataGV, FilterType^ wheres);

	//��������� ������� ���������� � ������� �������
	static DataTable^ GetDataTable(); 

	//��������� ������ ������ ���� �������� ������� �������
	static ListBox::ObjectCollection^ FillColumnName();
	//��������� ������ �������� ��������� 
	static ListBox::ObjectCollection^ Filloperation();
	//�������� ������� "������ ����� � ���������"
	static void CreateFullReportTable();
	//�������� ������� "������ ����� � ���������"
	static void DeleteFullReportTable();

	//��������� �������� ������� ������� �������
	static ListBox::ObjectCollection^ FillDataColumn(String^ columnName);
	//��������� �������� ������� �������� �������
	static ListBox::ObjectCollection^ FillDataColumn(String^ columnName, String^ theTableName);
	//���������� ������� �� ��������� ������
	static void Updata(String^ colNameWhere, String^ valWhere, String^ colNameSet, String^ valSet);

	//��������, �������� �� ������� ������� ������� ������� ������
	static bool isForgetKey(String^ columName);
	//��������� �������� �������� ������ ��� �������
	static ListBox::ObjectCollection^ GetValuesForgetKey(String^ columName);
	//������ ������ ��������� �������� ��� ����������� �������� ���� "���_�����"
	static double GetFullPrice(String^ IdRefueling);
	//��������� ������ � �������� ��� ����������� �������� ���� "�����_��������" �������
	static int GetPercentageDiscount(String^ phoneNumb);
	//���������� ������� �� ����������, ��� � ������� ���������� ��� 
	//�������� �����, ����� ����,�������� �������� AutoIncrement
	static void InsertData(array<String^>^);

	//���������� ������� �������� ���� ��������������� �������
	static void DeleteData(FilterType^ wheres);
};














//private:
	//static const array<String^>^ selects = { "*","*","*","*","*","*","*","*","*" };
		/*"������.���_�����, ������.����, ������.�����, "
		"�������.������� + LEFT(�������.���, 1) + '.' + LEFT(�������.��������, 1) + '.' AS ���_�������, " +
		"E1.������� + LEFT(E1.���, 1) + '.' + LEFT(E1.��������, 1) + '.' AS ���_����������, " +
		"��������.�����_������, �������.�������� AS �������, �������.����_��_����, " +
		"CAST(��������.�����_������*�������.����_��_���� AS decimal(8, 2)) AS ������_���������, "
		"������.���������_�������� AS ����_��_�������, �������.������, " +
		"E2.������� + LEFT(E1.���, 1) + '.' + LEFT(E1.��������, 1) + '.' AS ���_�������" };*/

		//static const array<String^>^ froms = { "dbo.�������","dbo.����������","dbo.�������",
			//"dbo.��������","dbo.������","dbo.��������","dbo.�������","dbo.Users", "dbo.������_�����" };
			/*"�������� INNER JOIN " +
			"������ ON ��������.���_����� = ������.���_����� INNER JOIN " +
			"������� ON ������.���_���_������� = �������.�����_�������� INNER JOIN " +
			"���������� E1 ON ��������.���_����_���������� = E1.�����_�������� INNER JOIN " +
			"���������� E2 ON ������.���_����_������� = E2.�����_�������� INNER JOIN " +
			"������� ON �������.������ = �������.������ INNER JOIN " +
			"������� ON ��������.���_�����_������� = �������.���_�����"};*/
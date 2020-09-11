#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::SqlClient;
using namespace System::Drawing::Printing;

enum accesses { director=0, admin=1, cashier=2 }; //возможные уровни доступа

ref struct FilterType //структура хранения значений фильтров
{
	int count; //число фильров (условий)
	array<String^>^ value; //условия поиска

	//конструкторы
	FilterType() :count(0) {};
	FilterType(int n, array<String^>^ val) :count(n), value(val) {}

	PrintDocument^ printDocument = gcnew PrintDocument();
};

ref class Functional
{
public:
	//матрица доступа (Номер таблицы,уровень доступа,добавление/редактирование/удаление)
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

	// массив, содержащий названия всех таблиц
	static const array<String^>^ allTableNames = { "dbo.Клиенты","dbo.Сотрудники","dbo.Топливо",
		"dbo.Заправки","dbo.Оплаты","dbo.Поставки","dbo.Статусы","dbo.Users","dbo.Полный_отчет" };

	static String^ user; //логин пользователя
	static accesses access; //уровень доступа текущего входа
	static SqlConnection^ conn; //подключение к серверу
	static SqlConnectionStringBuilder^ connStringBuilder; // строка для подключения
	static String^ tableName; //название текущей таблицы
	static int tabNum; //номер текущей таблицы

	Functional(){} //пустой конструктор

	//функция установки соединения с сервером
	static void ConnectToDB();
	//поиск пары логин-пароль в таблице "Users"
	static bool Functional::FindUser(String^ log, String^ pas);

	//static void FillSource(DataGridView^ DataGV);
	//получение текущей таблицы с данными с учетом фильтров
	static void FillSource(DataGridView^ DataGV, FilterType^ wheres);

	//получение таблицы информации о текущей таблице
	static DataTable^ GetDataTable(); 

	//получение списка списка имен столбцов текущей таблицы
	static ListBox::ObjectCollection^ FillColumnName();
	//получение списка операций сравнения 
	static ListBox::ObjectCollection^ Filloperation();
	//создание таблицы "Полный отчет о заправках"
	static void CreateFullReportTable();
	//удаление таблицы "Полный отчет о заправках"
	static void DeleteFullReportTable();

	//получение значений столбца текущей таблицы
	static ListBox::ObjectCollection^ FillDataColumn(String^ columnName);
	//получение значений столбца выбанной таблицы
	static ListBox::ObjectCollection^ FillDataColumn(String^ columnName, String^ theTableName);
	//выполнение запроса на изменения данных
	static void Updata(String^ colNameWhere, String^ valWhere, String^ colNameSet, String^ valSet);

	//проверка, является ли столбец текущей таблицы внешним ключем
	static bool isForgetKey(String^ columName);
	//получение значений внешнего ключад для столбца
	static ListBox::ObjectCollection^ GetValuesForgetKey(String^ columName);
	//расчет полной стоимости заправки для конкретного значения поля "Идн_номер"
	static double GetFullPrice(String^ IdRefueling);
	//получение скидки в проценах для конкретного значения поля "Номер_телефона" клиента
	static int GetPercentageDiscount(String^ phoneNumb);
	//выполнение запроса на добавления, где в массиве передаются все 
	//значения полей, кроме поля,имеющего свойство AutoIncrement
	static void InsertData(array<String^>^);

	//Выполнения запроса удаления всех отфильтрованных записей
	static void DeleteData(FilterType^ wheres);
};














//private:
	//static const array<String^>^ selects = { "*","*","*","*","*","*","*","*","*" };
		/*"Оплаты.Инд_номер, Оплаты.Дата, Оплаты.Время, "
		"Клиенты.Фамилия + LEFT(Клиенты.Имя, 1) + '.' + LEFT(Клиенты.Отчество, 1) + '.' AS ФИО_клиента, " +
		"E1.Фамилия + LEFT(E1.Имя, 1) + '.' + LEFT(E1.Отчество, 1) + '.' AS ФИО_Заправщика, " +
		"Заправки.Число_литров, Топливо.Название AS Топливо, Топливо.Цена_за_литр, " +
		"CAST(Заправки.Число_литров*Топливо.Цена_за_литр AS decimal(8, 2)) AS Полная_стоимость, "
		"Оплаты.Стоимость_заправки AS Цена_со_скидкой, Статусы.Скидка, " +
		"E2.Фамилия + LEFT(E1.Имя, 1) + '.' + LEFT(E1.Отчество, 1) + '.' AS ФИО_кассира" };*/

		//static const array<String^>^ froms = { "dbo.Клиенты","dbo.Сотрудники","dbo.Топливо",
			//"dbo.Заправки","dbo.Оплаты","dbo.Поставки","dbo.Статусы","dbo.Users", "dbo.Полный_отчет" };
			/*"Заправки INNER JOIN " +
			"Оплаты ON Заправки.Инд_номер = Оплаты.Инд_номер INNER JOIN " +
			"Клиенты ON Оплаты.Ном_тел_клиента = Клиенты.Номер_телефона INNER JOIN " +
			"Сотрудники E1 ON Заправки.Ном_пасп_заправщика = E1.Номер_паспорта INNER JOIN " +
			"Сотрудники E2 ON Оплаты.Ном_пасп_кассира = E2.Номер_паспорта INNER JOIN " +
			"Статусы ON Клиенты.Статус = Статусы.Статус INNER JOIN " +
			"Топливо ON Заправки.Инд_номер_топлива = Топливо.Инд_номер"};*/
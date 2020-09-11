#include"Functional.h"

void Functional::ConnectToDB()
{
	if (connStringBuilder!=nullptr) delete connStringBuilder;
	connStringBuilder = gcnew SqlConnectionStringBuilder();
	connStringBuilder->DataSource = "PC\\SQLEXPRESS";
	connStringBuilder->UserID = "Константин";
	connStringBuilder->Password = "12345";
	connStringBuilder->InitialCatalog = "АЗС";
	connStringBuilder->PersistSecurityInfo = false; //защита конфиденц даанных в строке подклчения вклчена
	connStringBuilder->IntegratedSecurity = false;
	if (conn != nullptr) delete conn;
	conn = gcnew SqlConnection(Convert::ToString(connStringBuilder));
}

bool Functional::FindUser(String^ log,String^ pas)
{
	bool result = false;
	try {
		ConnectToDB();

		String^ cmdText = "SELECT * FROM dbo.Users";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		conn->Open();
		SqlDataReader^ reader = cmd->ExecuteReader();

		while (reader->Read())
		{
			if (reader["Логин"]->ToString() == log && reader["Пароль"]->ToString() == pas)
			{
				user = reader["Логин"]->ToString();
				access = accesses(Convert::ToInt32(reader["Уровень_доступа"]->ToString()));
				result = true;
				break;
			}
		}
	}
	finally{
		if (conn != nullptr)
			conn->Close();
	}
	return result;
}

DataTable^ Functional::GetDataTable()
{
	DataTable^ dataTabl;
	try {
		ConnectToDB();

		String^ cmdText = "SELECT * FROM " + tableName;
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		conn->Open();
		SqlDataReader^ reader = cmd->ExecuteReader();
		dataTabl = reader->GetSchemaTable();
	}
	finally{
		if (conn != nullptr)
			conn->Close();
	}
	return dataTabl;
}

bool Functional::isForgetKey(String^ columName)
{
	if (tableName == "dbo.Клиенты" && columName == "Статус" ||
		tableName == "dbo.Поставки" && columName == "Номер_топлива" ||
		tableName == "dbo.Заправки" && columName == "Идн_номер_топлива" ||
		tableName == "dbo.Заправки" && columName == "Ном_пасп_заправщика" ||
		tableName == "dbo.Оплаты" && columName == "Идн_номер" ||
		tableName == "dbo.Оплаты" && columName == "Ном_тел_клиента" ||
		tableName == "dbo.Оплаты" && columName == "Ном_пасп_кассира")
		return true;
	return false;
}

ListBox::ObjectCollection^ Functional::GetValuesForgetKey(String^ columName)
{
	if (tableName == "dbo.Клиенты" && columName == "Статус")
		return FillDataColumn("Статус", "dbo.Статусы");
	if (tableName == "dbo.Поставки" && columName == "Номер_топлива")
		return FillDataColumn("Идн_номер", "dbo.Топливо");
	if (tableName == "dbo.Заправки" && columName == "Идн_номер_топлива")
		return FillDataColumn("Идн_номер", "dbo.Топливо");
	if (tableName == "dbo.Заправки" && columName == "Ном_пасп_заправщика")
		return FillDataColumn("Номер_паспорта","dbo.Сотрудники");
	if (tableName == "dbo.Оплаты" && columName == "Идн_номер") {
		ListBox::ObjectCollection^ RefuelingsList = FillDataColumn("Идн_номер", "dbo.Заправки");
		ListBox::ObjectCollection^ PaymentsList= FillDataColumn("Идн_номер", "dbo.Оплаты");
		for (int j=0;j<PaymentsList->Count;j++)
			RefuelingsList->Remove(PaymentsList[j]);
		return RefuelingsList;
	}
	if (tableName == "dbo.Оплаты" && columName == "Ном_тел_клиента")
		return FillDataColumn("Номер_телефона", "dbo.Клиенты");
	if (tableName == "dbo.Оплаты" && columName == "Ном_пасп_кассира")
		return FillDataColumn("Номер_паспорта", "dbo.Сотрудники");
}

ListBox::ObjectCollection^ Functional::FillDataColumn(String^ columnName, String^ theTableName)
{
	try {
		ConnectToDB();
		ListBox^ dataList = gcnew ListBox();

		String^ cmdText = "SELECT * FROM " + theTableName + " ORDER BY " + columnName;
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		conn->Open();
		SqlDataReader^ reader = cmd->ExecuteReader();

		while (reader->Read())
		{
			if (reader[columnName]->ToString() != reader[0]->ToString())
				dataList->Items->Add(reader[columnName]->ToString() + "-" + reader[0]->ToString());
			else
				dataList->Items->Add(reader[columnName]->ToString());
		}
		return dataList->Items;
	}
	finally{
		if (conn != nullptr)
			conn->Close();
	}
}

void Functional::InsertData(array<String^>^ dataList)
{
	try {
		ConnectToDB();
		String^ cmdText = "INSERT INTO " + tableName +"(";
		//Name, Instruct, Unit, Vol, Name_Maker) VALUES(@NV,'a','bb',3,'dddd')";
		
		DataTable^ tableInfo = GetDataTable();
		int columnCount = tableInfo->MinimumCapacity;
		for (int j = 0; j < columnCount; j++)
		{
			DataRow^ row = tableInfo->Rows[j];
			if (row["IsAutoIncrement"]->ToString() == "False")
			{
				cmdText += row["ColumnName"]->ToString();
				if (j < columnCount - 1) cmdText += ", ";
			}
		}
		cmdText += ") VALUES('";

		for (int j = 0; j < columnCount; j++)
		{
			DataRow^ row = tableInfo->Rows[j];
			if (row["IsAutoIncrement"]->ToString() == "False")
			{
				cmdText += dataList[j];
				if (j < columnCount - 1) cmdText += "', '";
			}
		}
		cmdText += "')";

		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		conn->Open();
		cmd->ExecuteNonQuery();
	}
	finally{
		if (conn != nullptr)
			conn->Close();
	}
	
}

ListBox::ObjectCollection^ Functional::FillColumnName()
{
	try {
		ConnectToDB();
		ListBox^ ListColumnNames = gcnew ListBox();

		DataTable^ tableInfo = GetDataTable();
		int columnCount = tableInfo->MinimumCapacity;
		for (int j = 0; j < columnCount; j++)
		{
			DataRow^ row = tableInfo->Rows[j];
			ListColumnNames->Items->Add(row["ColumnName"]->ToString());
		}
		return ListColumnNames->Items;
	}
	finally{
		if (conn != nullptr)
			conn->Close();
	}
}

ListBox::ObjectCollection^ Functional::FillDataColumn(String^ columnName)
{
	try {
		ConnectToDB();
		ListBox^ dataList = gcnew ListBox();

		String^ cmdText = "SELECT * FROM " + tableName + " ORDER BY " + columnName;
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		conn->Open();
		SqlDataReader^ reader = cmd->ExecuteReader();

		while (reader->Read())
		{
			dataList->Items->Add(reader[columnName]->ToString());
		}
		return dataList->Items;
	}
	finally{
		if (conn != nullptr)
			conn->Close();
	}
}

void Functional::Updata(String^ colNameWhere, String^ valWhere, String^ colNameSet, String^ valSet)
{
	try {
		ConnectToDB();

		String^ cmdText = "UPDATE " + tableName + " SET " + colNameSet + " = '" + valSet;
		cmdText += "' WHERE " + colNameWhere + " = '" + valWhere + "'";
		conn->Open();

		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		cmd->ExecuteNonQuery();
	}
	finally{
		if (conn != nullptr)
			conn->Close();
	}
}
//==================================================================================


void Functional::FillSource(DataGridView^ DataGV, FilterType^ wheres)
{
	try {
		ConnectToDB();
		String^ SqlText = "SELECT * FROM " +tableName;

		if (wheres->count != 0) SqlText += " WHERE (";
		for (int j = 0; j < wheres->count; j++)
		{
			SqlText += wheres->value[j];
			if (j < wheres->count - 1) SqlText += " AND ";
		}
		if (wheres->count != 0) SqlText += ")";

		conn->Open();
		SqlDataAdapter^ da = gcnew SqlDataAdapter(SqlText, conn);
		DataSet^ ds = gcnew DataSet();
		da->Fill(ds, tableName);
		DataGV->DataSource = ds->Tables[tableName]->DefaultView;
	}
	finally{
		if (conn != nullptr)
			conn->Close();
	}
}

ListBox::ObjectCollection^ Functional::Filloperation()
{
		ListBox^ ListWithNames = gcnew ListBox();

		ListWithNames->Items->Add("=");
		ListWithNames->Items->Add("<");
		ListWithNames->Items->Add("<=");
		ListWithNames->Items->Add(">");
		ListWithNames->Items->Add(">=");
		ListWithNames->Items->Add("<>");
		return ListWithNames->Items;
}

void Functional::DeleteData(FilterType^ wheres)
{
	try {
		ConnectToDB();
		String^ SqlText = "DELETE FROM " + tableName;

		if (wheres->count != 0) SqlText += " WHERE (";
		for (int j = 0; j < wheres->count; j++)
		{
			SqlText += wheres->value[j];
			if (j < wheres->count - 1) SqlText += " AND ";
		}
		if (wheres->count != 0) SqlText += ")";

		conn->Open();
		SqlCommand^ cmd = gcnew SqlCommand(SqlText, conn);
		cmd->ExecuteNonQuery();
	}
	finally{
		if (conn != nullptr)
			conn->Close();
	}
}

double Functional::GetFullPrice(String^ IdRefueling)
{
	try {
		ConnectToDB();
		ListBox^ dataList = gcnew ListBox();

		String^ cmdText =
			"SELECT Заправки.Идн_номер, Заправки.Число_литров, Топливо.Цена_за_литр " +
			"FROM   Заправки INNER JOIN " +
			"Топливо ON Заправки.Идн_номер_топлива = Топливо.Идн_номер " +
			"WHERE(Заправки.Идн_номер = " + IdRefueling + ")";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		conn->Open();
		SqlDataReader^ reader = cmd->ExecuteReader();

		double price=0;
		while (reader->Read())
		{
			price = Convert::ToDouble(reader["Число_литров"]->ToString())*
				Convert::ToDouble(reader["Цена_за_литр"]->ToString());
		}
		return price;
	}
	finally{
		if (conn != nullptr)
			conn->Close();
	}
	return 0;
}

int Functional::GetPercentageDiscount(String^ phoneNumb)
{
	try {
		ConnectToDB();
		ListBox^ dataList = gcnew ListBox();

		String^ cmdText ="SELECT   Статусы.Скидка " +
			"FROM   Клиенты INNER JOIN " +
			"Статусы ON Клиенты.Статус = Статусы.Статус " +
			"WHERE(Клиенты.Номер_телефона = "+phoneNumb+")";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		conn->Open();
		SqlDataReader^ reader = cmd->ExecuteReader();

		int percent=0;
		while (reader->Read())
		{
			percent = Convert::ToInt32(reader["Скидка"]->ToString());
		}
		return percent;
	}
	finally{
		if (conn != nullptr)
			conn->Close();
	}
	return 0;
}

void Functional::DeleteFullReportTable()
{
	try {
		ConnectToDB();
		String^ SqlText = "IF OBJECT_ID(N'" + allTableNames[8] + "','U') IS NOT NULL"
			+ " DROP TABLE " + allTableNames[8];
		conn->Open();
		SqlCommand^ cmd = gcnew SqlCommand(SqlText, conn);
		cmd->ExecuteNonQuery();
	}
	finally{
		if (conn != nullptr)
			conn->Close();
	}
}

void Functional::CreateFullReportTable()
{
	try {
		DeleteFullReportTable();
		ConnectToDB();
		String^ SqlText = "SELECT        Оплаты.Идн_номер, Оплаты.Дата, Оплаты.Время,"
			+ " Клиенты.Фамилия + LEFT(Клиенты.Имя, 1) + '.' + LEFT(Клиенты.Отчество, 1) + '.' AS ФИО_клиента,"
			+ " E1.Фамилия + LEFT(E1.Имя, 1) + '.' + LEFT(E1.Отчество, 1) + '.' AS ФИО_заправщика,"
			+ " Заправки.Число_литров, Топливо.Название AS Топливо, Топливо.Цена_за_литр,"
			+ " CAST(Заправки.Число_литров*Топливо.Цена_за_литр AS decimal(8, 2)) AS Полная_стоимость,"
			+ " Оплаты.Стоимость_заправки AS Цена_со_скидкой, Статусы.Скидка,"
			+ " E2.Фамилия + LEFT(E1.Имя, 1) + '.' + LEFT(E1.Отчество, 1) + '.' AS ФИО_кассира"
			+ " INTO[" + allTableNames[8]->Split('.')[1] + "]"
			+ " FROM            Заправки INNER JOIN"
			+ " Оплаты ON Заправки.Идн_номер = Оплаты.Идн_номер INNER JOIN"
			+ " Клиенты ON Оплаты.Ном_тел_клиента = Клиенты.Номер_телефона INNER JOIN"
			+ " Сотрудники E1 ON Заправки.Ном_пасп_заправщика = E1.Номер_паспорта INNER JOIN"
			+ " Сотрудники E2 ON Оплаты.Ном_пасп_кассира = E2.Номер_паспорта INNER JOIN"
			+ " Статусы ON Клиенты.Статус = Статусы.Статус INNER JOIN"
			+ " Топливо ON Заправки.Идн_номер_топлива = Топливо.Идн_номер";
		conn->Open();
		SqlCommand^ cmd = gcnew SqlCommand(SqlText, conn);
		cmd->ExecuteNonQuery();
	}
	finally{
		if (conn != nullptr)
			conn->Close();
	}
}


/*ListBox::ObjectCollection^ Functional::FillComboBox()
{
	try {
		ConnectToDB();
		ListBox^ ListWithNames = gcnew ListBox();
		ClassNames^ n = gcnew ClassNames();

		String^ cmdText = "SELECT * FROM dbo.Клиенты";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		conn->Open();
		SqlDataReader^ reader = cmd->ExecuteReader();

		while (reader->Read())
		{
			int count1 = reader->FieldCount;
			String^ name1;
			String^ type1;
			for (int i = 1; i < count1; i++)
			{
				name1 = reader->GetName(i)->ToString();
				type1 = reader->GetDataTypeName(i)->ToString();
			}
			//n->ID = Convert::ToInt32(reader["Id_Med"]->ToString());
			n->PhoneNumber = Convert::ToUInt64(reader["Номер_телефона"]->ToString());
			//n->Name = (reader["Name"]->ToString());
			n->Name = (reader["Имя"]->ToString());
			//ListWithNames->Items->Add(String::Format("{0}-{1}", n->ID, n->Name));
			ListWithNames->Items->Add(String::Format("{0}-{1}", n->PhoneNumber, n->Name));
		}
		return ListWithNames->Items;

	}
	finally{
		if (conn != nullptr)
			conn->Close();
	}
}*/
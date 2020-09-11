#include"Functional.h"

void Functional::ConnectToDB()
{
	if (connStringBuilder!=nullptr) delete connStringBuilder;
	connStringBuilder = gcnew SqlConnectionStringBuilder();
	connStringBuilder->DataSource = "PC\\SQLEXPRESS";
	connStringBuilder->UserID = "����������";
	connStringBuilder->Password = "12345";
	connStringBuilder->InitialCatalog = "���";
	connStringBuilder->PersistSecurityInfo = false; //������ ��������� ������� � ������ ���������� �������
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
			if (reader["�����"]->ToString() == log && reader["������"]->ToString() == pas)
			{
				user = reader["�����"]->ToString();
				access = accesses(Convert::ToInt32(reader["�������_�������"]->ToString()));
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
	if (tableName == "dbo.�������" && columName == "������" ||
		tableName == "dbo.��������" && columName == "�����_�������" ||
		tableName == "dbo.��������" && columName == "���_�����_�������" ||
		tableName == "dbo.��������" && columName == "���_����_����������" ||
		tableName == "dbo.������" && columName == "���_�����" ||
		tableName == "dbo.������" && columName == "���_���_�������" ||
		tableName == "dbo.������" && columName == "���_����_�������")
		return true;
	return false;
}

ListBox::ObjectCollection^ Functional::GetValuesForgetKey(String^ columName)
{
	if (tableName == "dbo.�������" && columName == "������")
		return FillDataColumn("������", "dbo.�������");
	if (tableName == "dbo.��������" && columName == "�����_�������")
		return FillDataColumn("���_�����", "dbo.�������");
	if (tableName == "dbo.��������" && columName == "���_�����_�������")
		return FillDataColumn("���_�����", "dbo.�������");
	if (tableName == "dbo.��������" && columName == "���_����_����������")
		return FillDataColumn("�����_��������","dbo.����������");
	if (tableName == "dbo.������" && columName == "���_�����") {
		ListBox::ObjectCollection^ RefuelingsList = FillDataColumn("���_�����", "dbo.��������");
		ListBox::ObjectCollection^ PaymentsList= FillDataColumn("���_�����", "dbo.������");
		for (int j=0;j<PaymentsList->Count;j++)
			RefuelingsList->Remove(PaymentsList[j]);
		return RefuelingsList;
	}
	if (tableName == "dbo.������" && columName == "���_���_�������")
		return FillDataColumn("�����_��������", "dbo.�������");
	if (tableName == "dbo.������" && columName == "���_����_�������")
		return FillDataColumn("�����_��������", "dbo.����������");
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
			"SELECT ��������.���_�����, ��������.�����_������, �������.����_��_���� " +
			"FROM   �������� INNER JOIN " +
			"������� ON ��������.���_�����_������� = �������.���_����� " +
			"WHERE(��������.���_����� = " + IdRefueling + ")";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		conn->Open();
		SqlDataReader^ reader = cmd->ExecuteReader();

		double price=0;
		while (reader->Read())
		{
			price = Convert::ToDouble(reader["�����_������"]->ToString())*
				Convert::ToDouble(reader["����_��_����"]->ToString());
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

		String^ cmdText ="SELECT   �������.������ " +
			"FROM   ������� INNER JOIN " +
			"������� ON �������.������ = �������.������ " +
			"WHERE(�������.�����_�������� = "+phoneNumb+")";
		SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
		conn->Open();
		SqlDataReader^ reader = cmd->ExecuteReader();

		int percent=0;
		while (reader->Read())
		{
			percent = Convert::ToInt32(reader["������"]->ToString());
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
		String^ SqlText = "SELECT        ������.���_�����, ������.����, ������.�����,"
			+ " �������.������� + LEFT(�������.���, 1) + '.' + LEFT(�������.��������, 1) + '.' AS ���_�������,"
			+ " E1.������� + LEFT(E1.���, 1) + '.' + LEFT(E1.��������, 1) + '.' AS ���_����������,"
			+ " ��������.�����_������, �������.�������� AS �������, �������.����_��_����,"
			+ " CAST(��������.�����_������*�������.����_��_���� AS decimal(8, 2)) AS ������_���������,"
			+ " ������.���������_�������� AS ����_��_�������, �������.������,"
			+ " E2.������� + LEFT(E1.���, 1) + '.' + LEFT(E1.��������, 1) + '.' AS ���_�������"
			+ " INTO[" + allTableNames[8]->Split('.')[1] + "]"
			+ " FROM            �������� INNER JOIN"
			+ " ������ ON ��������.���_����� = ������.���_����� INNER JOIN"
			+ " ������� ON ������.���_���_������� = �������.�����_�������� INNER JOIN"
			+ " ���������� E1 ON ��������.���_����_���������� = E1.�����_�������� INNER JOIN"
			+ " ���������� E2 ON ������.���_����_������� = E2.�����_�������� INNER JOIN"
			+ " ������� ON �������.������ = �������.������ INNER JOIN"
			+ " ������� ON ��������.���_�����_������� = �������.���_�����";
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

		String^ cmdText = "SELECT * FROM dbo.�������";
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
			n->PhoneNumber = Convert::ToUInt64(reader["�����_��������"]->ToString());
			//n->Name = (reader["Name"]->ToString());
			n->Name = (reader["���"]->ToString());
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
#pragma once
#include"Functional.h"
namespace Clientdb {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddRecordForm
	/// </summary>
	public ref class AddRecordForm : public System::Windows::Forms::Form
	{
	public:
		AddRecordForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	//public:DataTable^ tableInfo;
	public: int columnCount;
			String^ nameTextboxSum;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddRecordForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1_saveRecord;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1_saveRecord = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1_saveRecord
			// 
			this->button1_saveRecord->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1_saveRecord->Location = System::Drawing::Point(74, 12);
			this->button1_saveRecord->Name = L"button1_saveRecord";
			this->button1_saveRecord->Size = System::Drawing::Size(120, 34);
			this->button1_saveRecord->TabIndex = 0;
			this->button1_saveRecord->Text = L"���������";
			this->button1_saveRecord->UseVisualStyleBackColor = true;
			this->button1_saveRecord->Click += gcnew System::EventHandler(this, &AddRecordForm::button1_saveRecord_Click);
			// 
			// AddRecordForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button1_saveRecord);
			this->Name = L"AddRecordForm";
			this->Text = L"���������� �������";
			this->Load += gcnew System::EventHandler(this, &AddRecordForm::AddRecordForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	//�������� �����
	private: System::Void AddRecordForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		//��������� ������� � ����������� � ������� �������
		DataTable^ tableInfo = Functional::GetDataTable();

		columnCount = tableInfo->MinimumCapacity;//����� ������� ������ �������
		this->ClientSize = System::Drawing::Size(480, 70 + columnCount * 30); //������ �����
		//��������� ��������� ������ "���������"
		this->button1_saveRecord->Location = System::Drawing::Point(180, 20 + columnCount * 30);
		//��������� ����� �����
		this->Text = L"���������� �������" + " � '"+Functional::tableName->Split('.')[1]+"'";
		
		for (int j = 0; j < columnCount; j++)
		{
			//���������� �������� ������� ������� ������� �� �����
			Label^  label1 = gcnew Label;
			label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, FontStyle::Regular, GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			label1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			label1->Location = System::Drawing::Point(10, 10+j*30);
			label1->Size = System::Drawing::Size(200, 20);
			this->Controls->Add(label1);

			DataRow^ row = tableInfo->Rows[j];
			label1->Text = row["ColumnName"]->ToString();

			//���� ������� �������� ������� ������
			if (Functional::isForgetKey(row["ColumnName"]->ToString()))
			{
				//�������� ���� � �������
				ComboBox^  comboBox1 = gcnew ComboBox;
				//�������� �������� �������� �����
				comboBox1->DataSource = Functional::GetValuesForgetKey(row["ColumnName"]->ToString());
				//�������� �������� ���
				comboBox1->Name = L"itemBox0" + j.ToString();

				//��� ����� "���_�����" � "���_���_�������" ��������� �������, �������
				//�������� ��������� ����� ������ ��� ������ ��������� ������ �� ���� �����
				if (Functional::tableName == "dbo.������" && (row["ColumnName"]->ToString() == "���_�����"
					|| row["ColumnName"]->ToString() == "���_���_�������"))
				{
					comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &AddRecordForm::comboBoxs_SelectedIndexChanged);
				}
				//������� ������� � �����
				this->Controls->Add(comboBox1);
			}
			else
			{
				//�������� ������� ���� ��� �����
				TextBox^ textBox1 = gcnew TextBox;
				//�������� �������� ���
				textBox1->Name = L"itemBox0" + j.ToString();

				//�������� ��� ���� � ������, ��� ���������� ������� � ���
				if (row["ColumnName"]->ToString() == "���������_��������")
					nameTextboxSum = textBox1->Name;

				//������� ������� � �����
				this->Controls->Add(textBox1);
			}
			//������� ��������� ��������� ���������
			Controls["itemBox0" + j.ToString()]->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			Controls["itemBox0" + j.ToString()]->Location = System::Drawing::Point(240, 8+j*30);
			Controls["itemBox0" + j.ToString()]->Size = System::Drawing::Size(200, 24);
			//���� ���� ����� �������� AutoIncrement, �� �������� ����
			if (row["IsAutoIncrement"]->ToString() == "True")
			{
				Controls["itemBox0" + j.ToString()]->Text = "*autoIncrement";
				Controls["itemBox0" + j.ToString()]->Enabled = false;
			}
		}
	}

	//������� �� ������ "���������"
	private: System::Void button1_saveRecord_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		//�������� ������ ��� ������ �������� ���� �����
		array<String^>^ textboxlist = gcnew array<String^>(columnCount);
		for (int j = 0; j < columnCount; j++)
		{
			//������� �������� ���� � ������
			textboxlist[j] = Controls["itemBox0" + j.ToString()]->Text->Split('-')[0];
			if (textboxlist[j] == "")
			{
				MessageBox::Show("��������� ��� ����!", "������");
				return;
			}
		}
		//�������� ������ �� ����������
		Functional::InsertData(textboxlist);
		MessageBox::Show("������ ���� ������� ���������!", "��������� ��������");
		if (Functional::tableName == "dbo.������")
			Controls[nameTextboxSum]->Text = "";

	}

	//���������� ������� ��������� ����� "���_�����" ��� "���_���_�������"
	private: System::Void comboBoxs_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		//������ �����
		double price = Functional::GetFullPrice(Controls["itemBox00"]->Text)*0.01*
			(100 - Functional::GetPercentageDiscount(Controls["itemBox03"]->Text->Split('-')[0]));
		//������ ������� �� ����� � ���� �����
		Controls[nameTextboxSum]->Text = Convert::ToString(price)->Replace(",", ".");
	}
	};
}

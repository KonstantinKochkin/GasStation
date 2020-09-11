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
	/// Summary for ChangeDataForm
	/// </summary>
	public ref class ChangeDataForm : public System::Windows::Forms::Form
	{
	public:
		ChangeDataForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ChangeDataForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1_comm;
	private: System::Windows::Forms::Label^  label2_columnName;
	private: System::Windows::Forms::Label^  label3_Value;
	private: System::Windows::Forms::TextBox^  textBox1_changedValue;


	private: System::Windows::Forms::Label^  label4_comm;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label5_columnName;
	private: System::Windows::Forms::ComboBox^  comboBox3_columnName;
	private: System::Windows::Forms::Label^  label6_changedValue;
	private: System::Windows::Forms::ComboBox^  comboBox2_Value;
	private: System::Windows::Forms::ComboBox^  comboBox1_columnName;

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
			this->label1_comm = (gcnew System::Windows::Forms::Label());
			this->label2_columnName = (gcnew System::Windows::Forms::Label());
			this->label3_Value = (gcnew System::Windows::Forms::Label());
			this->textBox1_changedValue = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1_columnName = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2_Value = (gcnew System::Windows::Forms::ComboBox());
			this->label4_comm = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label5_columnName = (gcnew System::Windows::Forms::Label());
			this->comboBox3_columnName = (gcnew System::Windows::Forms::ComboBox());
			this->label6_changedValue = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1_comm
			// 
			this->label1_comm->AutoSize = true;
			this->label1_comm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1_comm->Location = System::Drawing::Point(13, 18);
			this->label1_comm->Name = L"label1_comm";
			this->label1_comm->Size = System::Drawing::Size(116, 16);
			this->label1_comm->TabIndex = 0;
			this->label1_comm->Text = L"Условия замены";
			// 
			// label2_columnName
			// 
			this->label2_columnName->AutoSize = true;
			this->label2_columnName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label2_columnName->Location = System::Drawing::Point(13, 47);
			this->label2_columnName->Name = L"label2_columnName";
			this->label2_columnName->Size = System::Drawing::Size(100, 18);
			this->label2_columnName->TabIndex = 1;
			this->label2_columnName->Text = L"Имя столбца";
			// 
			// label3_Value
			// 
			this->label3_Value->AutoSize = true;
			this->label3_Value->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3_Value->Location = System::Drawing::Point(209, 47);
			this->label3_Value->Name = L"label3_Value";
			this->label3_Value->Size = System::Drawing::Size(74, 18);
			this->label3_Value->TabIndex = 2;
			this->label3_Value->Text = L"Значение";
			// 
			// textBox1_changedValue
			// 
			this->textBox1_changedValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBox1_changedValue->Location = System::Drawing::Point(202, 205);
			this->textBox1_changedValue->Name = L"textBox1_changedValue";
			this->textBox1_changedValue->Size = System::Drawing::Size(145, 24);
			this->textBox1_changedValue->TabIndex = 3;
			// 
			// comboBox1_columnName
			// 
			this->comboBox1_columnName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->comboBox1_columnName->FormattingEnabled = true;
			this->comboBox1_columnName->Location = System::Drawing::Point(16, 76);
			this->comboBox1_columnName->Name = L"comboBox1_columnName";
			this->comboBox1_columnName->Size = System::Drawing::Size(156, 26);
			this->comboBox1_columnName->TabIndex = 4;
			this->comboBox1_columnName->SelectedIndexChanged += gcnew System::EventHandler(this, &ChangeDataForm::comboBox1_columnName_SelectedIndexChanged);
			// 
			// comboBox2_Value
			// 
			this->comboBox2_Value->DisplayMember = L"123123";
			this->comboBox2_Value->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->comboBox2_Value->FormattingEnabled = true;
			this->comboBox2_Value->Location = System::Drawing::Point(197, 76);
			this->comboBox2_Value->Name = L"comboBox2_Value";
			this->comboBox2_Value->Size = System::Drawing::Size(150, 26);
			this->comboBox2_Value->TabIndex = 5;
			// 
			// label4_comm
			// 
			this->label4_comm->AutoSize = true;
			this->label4_comm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4_comm->Location = System::Drawing::Point(13, 144);
			this->label4_comm->Name = L"label4_comm";
			this->label4_comm->Size = System::Drawing::Size(72, 16);
			this->label4_comm->TabIndex = 6;
			this->label4_comm->Text = L"Заменить";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(104, 260);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(166, 34);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Произвести замену";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ChangeDataForm::button1_Click);
			// 
			// label5_columnName
			// 
			this->label5_columnName->AutoSize = true;
			this->label5_columnName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label5_columnName->Location = System::Drawing::Point(13, 173);
			this->label5_columnName->Name = L"label5_columnName";
			this->label5_columnName->Size = System::Drawing::Size(100, 18);
			this->label5_columnName->TabIndex = 8;
			this->label5_columnName->Text = L"Имя столбца";
			// 
			// comboBox3_columnName
			// 
			this->comboBox3_columnName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->comboBox3_columnName->FormattingEnabled = true;
			this->comboBox3_columnName->Location = System::Drawing::Point(16, 203);
			this->comboBox3_columnName->Name = L"comboBox3_columnName";
			this->comboBox3_columnName->Size = System::Drawing::Size(156, 26);
			this->comboBox3_columnName->TabIndex = 9;
			// 
			// label6_changedValue
			// 
			this->label6_changedValue->AutoSize = true;
			this->label6_changedValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label6_changedValue->Location = System::Drawing::Point(209, 173);
			this->label6_changedValue->Name = L"label6_changedValue";
			this->label6_changedValue->Size = System::Drawing::Size(74, 18);
			this->label6_changedValue->TabIndex = 10;
			this->label6_changedValue->Text = L"Значение";
			// 
			// ChangeDataForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(386, 306);
			this->Controls->Add(this->label6_changedValue);
			this->Controls->Add(this->comboBox3_columnName);
			this->Controls->Add(this->label5_columnName);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4_comm);
			this->Controls->Add(this->comboBox2_Value);
			this->Controls->Add(this->comboBox1_columnName);
			this->Controls->Add(this->textBox1_changedValue);
			this->Controls->Add(this->label3_Value);
			this->Controls->Add(this->label2_columnName);
			this->Controls->Add(this->label1_comm);
			this->Name = L"ChangeDataForm";
			this->Text = L"Изменение данных";
			this->Load += gcnew System::EventHandler(this, &ChangeDataForm::ChangeData_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//Загрузка формы
	private: System::Void ChangeData_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		this->Text = L"Изменение данных" + " в '" + Functional::tableName->Split('.')[1] + "'";
		//Заполнение вариантов полей названиями столбцов
		comboBox1_columnName->DataSource = Functional::FillColumnName();
		comboBox3_columnName->DataSource = Functional::FillColumnName();
	}

	//Выбор значения в поле Улсловие -> Имя столбца
	private: System::Void comboBox1_columnName_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		//Запонение вариантов поля данными
		String^ columnName = Convert::ToString(comboBox1_columnName->SelectedItem);
		comboBox2_Value->DataSource = Functional::FillDataColumn(columnName);
	}

	//Нажатие на кнопку "Произвести замену"
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (this->textBox1_changedValue->Text == "")
			MessageBox::Show("Заполните все поля!", "Ошибка");
		else
		{
			//считывание данных из полей
			String^ colNameWhere = this->comboBox1_columnName->Text;
			String^ valWhere = this->comboBox2_Value->Text;
			String^ colNameSet = this->comboBox3_columnName->Text;
			String^ valSet = this->textBox1_changedValue->Text;
			//Отправка запроса на изменения данных
			Functional::Updata(colNameWhere, valWhere, colNameSet, valSet);
			MessageBox::Show("Данные были успешно изменены!", "Результат операции");
			//Обновить варианты значений столбца "Значение" в усовии замены
			String^ columnName = Convert::ToString(comboBox1_columnName->SelectedItem);
			comboBox2_Value->DataSource = Functional::FillDataColumn(columnName);
		}
	}
};
}

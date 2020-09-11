#pragma once
#include"Functional.h";
#include"AddRecordForm.h"
#include"ChangeDataForm.h"
#include"AuthorizationForm.h"
namespace Clientdb {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Tables
	/// </summary>
	public ref class Tables : public System::Windows::Forms::Form
	{
	public:
		Tables(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Tables(AuthorizationForm^ parForm)
		{
			InitializeComponent();
			parentForm = parForm;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Tables()
		{
			if (components)
			{
				delete components;
			}
		}

	private:AuthorizationForm^ parentForm;
	private:const int FCOUNT = 4;
	//меню
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  CustomersToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  EmployeesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  FuelToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  FuelsthecarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  PayingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  SupplyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  StatusesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  usersToolStripMenuItem;

	private: System::Windows::Forms::MenuStrip^  menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^  fullRefuelingReportToolStripMenuItem;

	//фильтры
	private: System::Windows::Forms::GroupBox^  groupBox1_filter;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::CheckBox^  checkBox4;

	private: System::Windows::Forms::ComboBox^  comboBox1_column;
	private: System::Windows::Forms::ComboBox^  comboBox2_column;
	private: System::Windows::Forms::ComboBox^  comboBox3_column;
	private: System::Windows::Forms::ComboBox^  comboBox4_column;

	private: System::Windows::Forms::ComboBox^  comboBox1_operation;
	private: System::Windows::Forms::ComboBox^  comboBox2_operation;
	private: System::Windows::Forms::ComboBox^  comboBox3_operation;
	private: System::Windows::Forms::ComboBox^  comboBox4_operation;

	private: System::Windows::Forms::TextBox^  textBox1_val;
	private: System::Windows::Forms::TextBox^  textBox2_val;
	private: System::Windows::Forms::TextBox^  textBox3_val;
	private: System::Windows::Forms::TextBox^  textBox4_val;

	//работа с БД
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;

	private: System::Windows::Forms::Button^  button1_addData;
	private: System::Windows::Forms::Button^  button2_changeData;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button3_deleteData;

	private: System::ComponentModel::IContainer^  components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Tables::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->CustomersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->EmployeesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->FuelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->FuelsthecarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->PayingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SupplyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->StatusesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->usersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->fullRefuelingReportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1_filter = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox1_column = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2_column = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3_column = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4_column = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox1_operation = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2_operation = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3_operation = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4_operation = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1_val = (gcnew System::Windows::Forms::TextBox());
			this->textBox2_val = (gcnew System::Windows::Forms::TextBox());
			this->textBox3_val = (gcnew System::Windows::Forms::TextBox());
			this->textBox4_val = (gcnew System::Windows::Forms::TextBox());
			this->button1_addData = (gcnew System::Windows::Forms::Button());
			this->button2_changeData = (gcnew System::Windows::Forms::Button());
			this->button3_deleteData = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1->SuspendLayout();
			this->menuStrip2->SuspendLayout();
			this->groupBox1_filter->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Turquoise;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->CustomersToolStripMenuItem,
					this->EmployeesToolStripMenuItem, this->FuelToolStripMenuItem, this->FuelsthecarToolStripMenuItem, this->PayingsToolStripMenuItem,
					this->SupplyToolStripMenuItem, this->StatusesToolStripMenuItem, this->usersToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(781, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// CustomersToolStripMenuItem
			// 
			this->CustomersToolStripMenuItem->Name = L"CustomersToolStripMenuItem";
			this->CustomersToolStripMenuItem->Size = System::Drawing::Size(67, 20);
			this->CustomersToolStripMenuItem->Text = L"Клиенты";
			this->CustomersToolStripMenuItem->Click += gcnew System::EventHandler(this, &Tables::ToolStripMenuItems_Click);
			// 
			// EmployeesToolStripMenuItem
			// 
			this->EmployeesToolStripMenuItem->Name = L"EmployeesToolStripMenuItem";
			this->EmployeesToolStripMenuItem->Size = System::Drawing::Size(85, 20);
			this->EmployeesToolStripMenuItem->Text = L"Сотрудники";
			this->EmployeesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Tables::ToolStripMenuItems_Click);
			// 
			// FuelToolStripMenuItem
			// 
			this->FuelToolStripMenuItem->Name = L"FuelToolStripMenuItem";
			this->FuelToolStripMenuItem->Size = System::Drawing::Size(67, 20);
			this->FuelToolStripMenuItem->Text = L"Топливо";
			this->FuelToolStripMenuItem->Click += gcnew System::EventHandler(this, &Tables::ToolStripMenuItems_Click);
			// 
			// FuelsthecarToolStripMenuItem
			// 
			this->FuelsthecarToolStripMenuItem->Name = L"FuelsthecarToolStripMenuItem";
			this->FuelsthecarToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->FuelsthecarToolStripMenuItem->Text = L"Заправки";
			this->FuelsthecarToolStripMenuItem->Click += gcnew System::EventHandler(this, &Tables::ToolStripMenuItems_Click);
			// 
			// PayingsToolStripMenuItem
			// 
			this->PayingsToolStripMenuItem->Name = L"PayingsToolStripMenuItem";
			this->PayingsToolStripMenuItem->Size = System::Drawing::Size(62, 20);
			this->PayingsToolStripMenuItem->Text = L"Оплаты";
			this->PayingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Tables::ToolStripMenuItems_Click);
			// 
			// SupplyToolStripMenuItem
			// 
			this->SupplyToolStripMenuItem->Name = L"SupplyToolStripMenuItem";
			this->SupplyToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->SupplyToolStripMenuItem->Text = L"Поставки";
			this->SupplyToolStripMenuItem->Click += gcnew System::EventHandler(this, &Tables::ToolStripMenuItems_Click);
			// 
			// StatusesToolStripMenuItem
			// 
			this->StatusesToolStripMenuItem->Name = L"StatusesToolStripMenuItem";
			this->StatusesToolStripMenuItem->Size = System::Drawing::Size(64, 20);
			this->StatusesToolStripMenuItem->Text = L"Статусы";
			this->StatusesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Tables::ToolStripMenuItems_Click);
			// 
			// usersToolStripMenuItem
			// 
			this->usersToolStripMenuItem->Name = L"usersToolStripMenuItem";
			this->usersToolStripMenuItem->Size = System::Drawing::Size(47, 20);
			this->usersToolStripMenuItem->Text = L"Users";
			this->usersToolStripMenuItem->Visible = false;
			this->usersToolStripMenuItem->Click += gcnew System::EventHandler(this, &Tables::ToolStripMenuItems_Click);
			// 
			// menuStrip2
			// 
			this->menuStrip2->AutoSize = false;
			this->menuStrip2->BackColor = System::Drawing::Color::Chartreuse;
			this->menuStrip2->Dock = System::Windows::Forms::DockStyle::None;
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fullRefuelingReportToolStripMenuItem });
			this->menuStrip2->Location = System::Drawing::Point(0, 24);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(781, 24);
			this->menuStrip2->TabIndex = 15;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// fullRefuelingReportToolStripMenuItem
			// 
			this->fullRefuelingReportToolStripMenuItem->BackColor = System::Drawing::Color::Chartreuse;
			this->fullRefuelingReportToolStripMenuItem->Name = L"fullRefuelingReportToolStripMenuItem";
			this->fullRefuelingReportToolStripMenuItem->Size = System::Drawing::Size(165, 20);
			this->fullRefuelingReportToolStripMenuItem->Text = L"Полный отчет о заправках";
			this->fullRefuelingReportToolStripMenuItem->Click += gcnew System::EventHandler(this, &Tables::ToolStripMenuItems_Click);
			// 
			// groupBox1_filter
			// 
			this->groupBox1_filter->Controls->Add(this->checkBox1);
			this->groupBox1_filter->Controls->Add(this->checkBox2);
			this->groupBox1_filter->Controls->Add(this->checkBox3);
			this->groupBox1_filter->Controls->Add(this->checkBox4);
			this->groupBox1_filter->Controls->Add(this->comboBox1_column);
			this->groupBox1_filter->Controls->Add(this->comboBox2_column);
			this->groupBox1_filter->Controls->Add(this->comboBox3_column);
			this->groupBox1_filter->Controls->Add(this->comboBox4_column);
			this->groupBox1_filter->Controls->Add(this->comboBox1_operation);
			this->groupBox1_filter->Controls->Add(this->comboBox2_operation);
			this->groupBox1_filter->Controls->Add(this->comboBox3_operation);
			this->groupBox1_filter->Controls->Add(this->comboBox4_operation);
			this->groupBox1_filter->Controls->Add(this->textBox1_val);
			this->groupBox1_filter->Controls->Add(this->textBox2_val);
			this->groupBox1_filter->Controls->Add(this->textBox3_val);
			this->groupBox1_filter->Controls->Add(this->textBox4_val);
			this->groupBox1_filter->Location = System::Drawing::Point(20, 51);
			this->groupBox1_filter->Name = L"groupBox1_filter";
			this->groupBox1_filter->Size = System::Drawing::Size(744, 71);
			this->groupBox1_filter->TabIndex = 16;
			this->groupBox1_filter->TabStop = false;
			this->groupBox1_filter->Text = L"Фильтры";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Cursor = System::Windows::Forms::Cursors::Default;
			this->checkBox1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->checkBox1->Location = System::Drawing::Point(21, 22);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 17;
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Tables::checkBoxs_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->checkBox2->Location = System::Drawing::Point(393, 22);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(15, 14);
			this->checkBox2->TabIndex = 20;
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Tables::checkBoxs_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Cursor = System::Windows::Forms::Cursors::Default;
			this->checkBox3->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->checkBox3->Location = System::Drawing::Point(21, 48);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(15, 14);
			this->checkBox3->TabIndex = 25;
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &Tables::checkBoxs_CheckedChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->checkBox4->Location = System::Drawing::Point(393, 48);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(15, 14);
			this->checkBox4->TabIndex = 28;
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &Tables::checkBoxs_CheckedChanged);
			// 
			// comboBox1_column
			// 
			this->comboBox1_column->Enabled = false;
			this->comboBox1_column->FormattingEnabled = true;
			this->comboBox1_column->Location = System::Drawing::Point(42, 19);
			this->comboBox1_column->Name = L"comboBox1_column";
			this->comboBox1_column->Size = System::Drawing::Size(141, 21);
			this->comboBox1_column->TabIndex = 18;
			this->comboBox1_column->SelectedIndexChanged += gcnew System::EventHandler(this, &Tables::comboBoxs_SelectedIndexChanged);
			// 
			// comboBox2_column
			// 
			this->comboBox2_column->Enabled = false;
			this->comboBox2_column->FormattingEnabled = true;
			this->comboBox2_column->Location = System::Drawing::Point(414, 19);
			this->comboBox2_column->Name = L"comboBox2_column";
			this->comboBox2_column->Size = System::Drawing::Size(141, 21);
			this->comboBox2_column->TabIndex = 21;
			this->comboBox2_column->SelectedIndexChanged += gcnew System::EventHandler(this, &Tables::comboBoxs_SelectedIndexChanged);
			// 
			// comboBox3_column
			// 
			this->comboBox3_column->Enabled = false;
			this->comboBox3_column->FormattingEnabled = true;
			this->comboBox3_column->Location = System::Drawing::Point(42, 45);
			this->comboBox3_column->Name = L"comboBox3_column";
			this->comboBox3_column->Size = System::Drawing::Size(141, 21);
			this->comboBox3_column->TabIndex = 26;
			this->comboBox3_column->SelectedIndexChanged += gcnew System::EventHandler(this, &Tables::comboBoxs_SelectedIndexChanged);
			// 
			// comboBox4_column
			// 
			this->comboBox4_column->Enabled = false;
			this->comboBox4_column->FormattingEnabled = true;
			this->comboBox4_column->Location = System::Drawing::Point(414, 45);
			this->comboBox4_column->Name = L"comboBox4_column";
			this->comboBox4_column->Size = System::Drawing::Size(141, 21);
			this->comboBox4_column->TabIndex = 29;
			this->comboBox4_column->SelectedIndexChanged += gcnew System::EventHandler(this, &Tables::comboBoxs_SelectedIndexChanged);
			// 
			// comboBox1_operation
			// 
			this->comboBox1_operation->Enabled = false;
			this->comboBox1_operation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->comboBox1_operation->FormattingEnabled = true;
			this->comboBox1_operation->Location = System::Drawing::Point(189, 17);
			this->comboBox1_operation->Name = L"comboBox1_operation";
			this->comboBox1_operation->Size = System::Drawing::Size(37, 23);
			this->comboBox1_operation->TabIndex = 23;
			// 
			// comboBox2_operation
			// 
			this->comboBox2_operation->Enabled = false;
			this->comboBox2_operation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->comboBox2_operation->FormattingEnabled = true;
			this->comboBox2_operation->Location = System::Drawing::Point(561, 17);
			this->comboBox2_operation->Name = L"comboBox2_operation";
			this->comboBox2_operation->Size = System::Drawing::Size(37, 23);
			this->comboBox2_operation->TabIndex = 24;
			// 
			// comboBox3_operation
			// 
			this->comboBox3_operation->Enabled = false;
			this->comboBox3_operation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->comboBox3_operation->FormattingEnabled = true;
			this->comboBox3_operation->Location = System::Drawing::Point(189, 43);
			this->comboBox3_operation->Name = L"comboBox3_operation";
			this->comboBox3_operation->Size = System::Drawing::Size(37, 23);
			this->comboBox3_operation->TabIndex = 31;
			// 
			// comboBox4_operation
			// 
			this->comboBox4_operation->Enabled = false;
			this->comboBox4_operation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->comboBox4_operation->FormattingEnabled = true;
			this->comboBox4_operation->Location = System::Drawing::Point(561, 43);
			this->comboBox4_operation->Name = L"comboBox4_operation";
			this->comboBox4_operation->Size = System::Drawing::Size(37, 23);
			this->comboBox4_operation->TabIndex = 32;
			// 
			// textBox1_val
			// 
			this->textBox1_val->Enabled = false;
			this->textBox1_val->Location = System::Drawing::Point(232, 20);
			this->textBox1_val->Name = L"textBox1_val";
			this->textBox1_val->Size = System::Drawing::Size(114, 20);
			this->textBox1_val->TabIndex = 19;
			// 
			// textBox2_val
			// 
			this->textBox2_val->Enabled = false;
			this->textBox2_val->Location = System::Drawing::Point(604, 20);
			this->textBox2_val->Name = L"textBox2_val";
			this->textBox2_val->Size = System::Drawing::Size(114, 20);
			this->textBox2_val->TabIndex = 22;
			// 
			// textBox3_val
			// 
			this->textBox3_val->Enabled = false;
			this->textBox3_val->Location = System::Drawing::Point(232, 45);
			this->textBox3_val->Name = L"textBox3_val";
			this->textBox3_val->Size = System::Drawing::Size(114, 20);
			this->textBox3_val->TabIndex = 27;
			// 
			// textBox4_val
			// 
			this->textBox4_val->Enabled = false;
			this->textBox4_val->Location = System::Drawing::Point(604, 45);
			this->textBox4_val->Name = L"textBox4_val";
			this->textBox4_val->Size = System::Drawing::Size(114, 20);
			this->textBox4_val->TabIndex = 30;
			// 
			// button1_addData
			// 
			this->button1_addData->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button1_addData->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button1_addData->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button1_addData->Location = System::Drawing::Point(33, 407);
			this->button1_addData->Name = L"button1_addData";
			this->button1_addData->Size = System::Drawing::Size(167, 36);
			this->button1_addData->TabIndex = 2;
			this->button1_addData->Text = L"Добавить запись";
			this->button1_addData->UseVisualStyleBackColor = true;
			this->button1_addData->Click += gcnew System::EventHandler(this, &Tables::button1_addData_Click);
			// 
			// button2_changeData
			// 
			this->button2_changeData->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button2_changeData->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button2_changeData->Location = System::Drawing::Point(317, 407);
			this->button2_changeData->Name = L"button2_changeData";
			this->button2_changeData->Size = System::Drawing::Size(167, 36);
			this->button2_changeData->TabIndex = 3;
			this->button2_changeData->Text = L"Изменить данные";
			this->button2_changeData->UseVisualStyleBackColor = true;
			this->button2_changeData->Click += gcnew System::EventHandler(this, &Tables::button2_changeData_Click);
			// 
			// button3_deleteData
			// 
			this->button3_deleteData->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->button3_deleteData->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->button3_deleteData->Location = System::Drawing::Point(559, 407);
			this->button3_deleteData->Name = L"button3_deleteData";
			this->button3_deleteData->Size = System::Drawing::Size(167, 36);
			this->button3_deleteData->TabIndex = 14;
			this->button3_deleteData->Text = L"Удалить записи";
			this->button3_deleteData->UseVisualStyleBackColor = true;
			this->button3_deleteData->Click += gcnew System::EventHandler(this, &Tables::button3_deleteData_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(239, 407);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(42, 36);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Tables::pictureBox1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllHeaders;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(20, 130);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(744, 271);
			this->dataGridView1->TabIndex = 0;
			// 
			// Tables
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(781, 474);
			this->Controls->Add(this->groupBox1_filter);
			this->Controls->Add(this->button3_deleteData);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button2_changeData);
			this->Controls->Add(this->button1_addData);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->menuStrip2);
			this->HelpButton = true;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Tables";
			this->Text = L"АЗС";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Tables::Tables_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Tables::Tables_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->groupBox1_filter->ResumeLayout(false);
			this->groupBox1_filter->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//Загрузка формы
	private: System::Void Tables_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		//вызвать событие выбора одной из таблиц в меню
		ToolStripMenuItems_Click(menuStrip1->Items[0], e);
		for (int j = FCOUNT*2; j < FCOUNT*3; j++)
			//заполнене списков выбора полей фильтра операциями сравнения
			safe_cast<ComboBox^>(groupBox1_filter->Controls[j])->DataSource = Functional::Filloperation();

		//включение или отключение таблиц из меню в зависимости от уровня доступа
		if (Functional::access == 0 || Functional::access == 1) {
			this->EmployeesToolStripMenuItem->Visible = true;
			this->usersToolStripMenuItem->Visible = true;
		}
		else {
			this->EmployeesToolStripMenuItem->Visible = false;
			this->usersToolStripMenuItem->Visible = false;
		}
	}

//my functions---------------------------------------------------------------------------------------------------------------------------
	//фунция, выополняющаяся при выборе таблицы в пунке меню
	//аргументы - номер таблицы и верхнее|нижнее меню
	private: void FuncForEachMenu(int numTable, System::Windows::Forms::MenuStrip^ ms)
	{
		Functional f;
		f.tableName = f.allTableNames[numTable]; //запоминание текущей таблицы
		f.tabNum = numTable; //запоминание номера текущей таблицы
		//создание таблицы, если выбран "Полный отчет о запавках"
		if (numTable == 8) f.CreateFullReportTable();
		f.FillSource(dataGridView1, gcnew FilterType); //получение таблицы данных
		for (int j = FCOUNT; j < FCOUNT*2; j++)
			//заполнение полей фильтров с названиями столбцов
			safe_cast<ComboBox^>(groupBox1_filter->Controls[j])->DataSource = f.FillColumnName();

		//включение или отключение кнопок добавления, редактирования и просмотра
		this->button1_addData->Enabled = f.matrixAccess[numTable, f.access, 0];
		this->button2_changeData->Enabled = f.matrixAccess[numTable, f.access, 1];
		this->button3_deleteData->Enabled = f.matrixAccess[numTable, f.access, 2];
	}
	//**************************************************************************************************
	//Сборка каждой группы полей включенных фильтров в цельное условие
	private: FilterType^ GetWheres()
	{
		//создание пустого массива условий
		array<String^>^ wheres =gcnew array<String^>(FCOUNT);
		int countFindColumns = 0; //число активных фильров
		for (int j = 0; j < FCOUNT; j++)
			if (safe_cast<CheckBox^>(groupBox1_filter->Controls[j])->Checked)
			{
				if (groupBox1_filter->Controls[j + FCOUNT * 3]->Text == "")
					MessageBox::Show("Поле фильтра не заполнено!", "Ошибка");
				else {
					wheres[countFindColumns] = groupBox1_filter->Controls[j + FCOUNT]->Text
						+ " " + groupBox1_filter->Controls[j + FCOUNT * 2]->Text
						+ " '" + groupBox1_filter->Controls[j + FCOUNT * 3]->Text + "'";
					countFindColumns++;
				}
			}
		//создание и возвращение объекта структуры фильтра 
		return gcnew FilterType(countFindColumns, wheres);
	}
//----------------------------------------------------------------------------------------------------------------------------------------
	//При клике на один из пунктов меню, вызывает функцию "FuncForEachMenu"
	private: System::Void ToolStripMenuItems_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		//проверка, был ли выбан один из пунктов верхнего меню
		for (int j = 0; j < menuStrip1->Items->Count; j++)
			if (sender->Equals(menuStrip1->Items[j]))
				FuncForEachMenu(j, menuStrip1);

		//проверка, был ли выбран один из пунктов нижнего меню
		for (int j = 0; j < menuStrip2->Items->Count; j++)
			if (sender->Equals(menuStrip2->Items[j]))
				FuncForEachMenu(j + menuStrip1->Items->Count, menuStrip2);
	}
	
	//Закрытие формы
	private: System::Void Tables_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) 
	{
		if (parentForm != nullptr) parentForm->Visible = true;
		Functional::DeleteFullReportTable();
	}

	//Нажатие на кнопку "Добавить запись" 
	private: System::Void button1_addData_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		AddRecordForm^ AddForm1 = gcnew AddRecordForm();
		AddForm1->ShowDialog();
	}

	//Нажатие на кнопку "Изменить данные"
	private: System::Void button2_changeData_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		ChangeDataForm^ changeData1 = gcnew ChangeDataForm();
		changeData1->ShowDialog();
	}

	//Нажатие на картинку с зеленой стрелочкой для обновления данных
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Functional::FillSource(dataGridView1, GetWheres());
	}

	//Очистка поля ввода фильтра, при изменения имени столбца
	private: System::Void comboBoxs_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		for (int j = FCOUNT; j < FCOUNT*2; j++)
			if (sender->Equals(groupBox1_filter->Controls[j]))
				groupBox1_filter->Controls[j+ FCOUNT*2]->Text = "";
	}

	//Нажаие на кнопку "Удалить записи"
	private: System::Void button3_deleteData_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (MessageBox::Show("Вы действительно хотите удалить выбранные записи?"
			+ "\nКоличемтво выбранных записей: " + dataGridView1->RowCount, "Подтверждение удаления", 
			MessageBoxButtons::OKCancel, MessageBoxIcon::Exclamation) == ::DialogResult::OK)
		{
			Functional::DeleteData(GetWheres());
			MessageBox::Show("Готово!", "Результат удаления");
		}
	}

	//Включение или отключение фильтра, при начатии на "checkBox"
	private: System::Void checkBoxs_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		for (int j = 0; j < FCOUNT; j++)
		{
			if (sender->Equals(groupBox1_filter->Controls[j]))
			{
				bool TF = safe_cast<CheckBox^>(groupBox1_filter->Controls[j])->Checked;
				groupBox1_filter->Controls[j + FCOUNT]->Enabled = TF;
				groupBox1_filter->Controls[j + FCOUNT*2]->Enabled = TF;
				groupBox1_filter->Controls[j + FCOUNT*3]->Enabled = TF;
			}
		}
	}
};
}

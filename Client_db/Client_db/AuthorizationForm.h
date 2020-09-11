#pragma once
#include"Functional.h";

namespace Clientdb {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AuthorizationForm
	/// </summary>
	public ref class AuthorizationForm : public System::Windows::Forms::Form
	{
	public:
		AuthorizationForm(void)
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
		~AuthorizationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1_login;
	protected:
	private: System::Windows::Forms::Label^  label2_password;
	private: System::Windows::Forms::TextBox^  textBox1_login;
	private: System::Windows::Forms::TextBox^  textBox2_password;


	private: System::Windows::Forms::Button^  button1_intobd;

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
			this->label1_login = (gcnew System::Windows::Forms::Label());
			this->label2_password = (gcnew System::Windows::Forms::Label());
			this->textBox1_login = (gcnew System::Windows::Forms::TextBox());
			this->textBox2_password = (gcnew System::Windows::Forms::TextBox());
			this->button1_intobd = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1_login
			// 
			this->label1_login->AutoSize = true;
			this->label1_login->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1_login->Location = System::Drawing::Point(10, 30);
			this->label1_login->Name = L"label1_login";
			this->label1_login->Size = System::Drawing::Size(55, 20);
			this->label1_login->TabIndex = 0;
			this->label1_login->Text = L"Логин";
			// 
			// label2_password
			// 
			this->label2_password->AutoSize = true;
			this->label2_password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2_password->Location = System::Drawing::Point(10, 80);
			this->label2_password->Name = L"label2_password";
			this->label2_password->Size = System::Drawing::Size(67, 20);
			this->label2_password->TabIndex = 1;
			this->label2_password->Text = L"Пароль";
			// 
			// textBox1_login
			// 
			this->textBox1_login->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1_login->Location = System::Drawing::Point(100, 27);
			this->textBox1_login->Name = L"textBox1_login";
			this->textBox1_login->Size = System::Drawing::Size(141, 26);
			this->textBox1_login->TabIndex = 2;
			this->textBox1_login->Text = L"Misha";
			// 
			// textBox2_password
			// 
			this->textBox2_password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2_password->Location = System::Drawing::Point(100, 77);
			this->textBox2_password->Name = L"textBox2_password";
			this->textBox2_password->PasswordChar = '*';
			this->textBox2_password->Size = System::Drawing::Size(141, 26);
			this->textBox2_password->TabIndex = 3;
			this->textBox2_password->Text = L"000";
			// 
			// button1_intobd
			// 
			this->button1_intobd->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1_intobd->Location = System::Drawing::Point(52, 129);
			this->button1_intobd->Name = L"button1_intobd";
			this->button1_intobd->Size = System::Drawing::Size(170, 40);
			this->button1_intobd->TabIndex = 4;
			this->button1_intobd->Text = L"Вход";
			this->button1_intobd->UseVisualStyleBackColor = true;
			this->button1_intobd->Click += gcnew System::EventHandler(this, &AuthorizationForm::button1_intobd_Click);
			// 
			// AuthorizationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(279, 181);
			this->Controls->Add(this->button1_intobd);
			this->Controls->Add(this->textBox2_password);
			this->Controls->Add(this->textBox1_login);
			this->Controls->Add(this->label2_password);
			this->Controls->Add(this->label1_login);
			this->Name = L"AuthorizationForm";
			this->Text = L"Авторизация";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_intobd_Click(System::Object^  sender, System::EventArgs^  e);
};
}
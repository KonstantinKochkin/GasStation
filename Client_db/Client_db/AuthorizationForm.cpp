#include "AuthorizationForm.h"
#include"Tables.h"
using namespace System;
using namespace System::Windows::Forms;

namespace Clientdb
{
	System::Void AuthorizationForm::button1_intobd_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (Functional::FindUser(this->textBox1_login->Text, this->textBox2_password->Text))
		{
			Tables ^Tables1 = gcnew Tables(this);
			Tables1->Show();
			this->Visible = false;
		}
		else MessageBox::Show("Пароль или логин введен неверно!", "Ошибка входа");
	}
}

[STAThread]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Clientdb::AuthorizationForm Startform;
	Application::Run(%Startform);
}




/*System::Void Form1::button1_Click(System::Object^  sender, System::EventArgs^  e) {
	Form2^ f2 = gcnew Form2(this);
	f2->Show();
	this->Hide();
}*/
#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Data;
using namespace Data::SqlClient;

ref class ClassNames
{
public:
	ClassNames() {};
	static int id;
	static property int ID
	{
		int get() {
			return id;
		}
		void set(int value) {
			id = value;
		}
	}
	static String^ name;
	static property String^ Name
	{
		String^ get() {
			return name;
		}
		void set(String^ value) {
			name = value;
		}
	}
	static UInt64^ phoneNumber;
	static property UInt64^ PhoneNumber
	{
		UInt64^ get() {
			return phoneNumber;
		}
		void set(UInt64^ value) {
			phoneNumber = value;
		}
	}
};


#pragma once
#include "MyForm.h"

namespace TOPD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)		{
			InitializeComponent();

			textBox3->Text = serverIP;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		TOPD::MyForm MainForm;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label5;

		   String^ passwd = gcnew String(L'*', 0);
		   String^ serverIP = "localhost";
		   String^ connStr = nullptr;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Black", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(232, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 46);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ВХІД";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(191, 137);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(200, 34);
			this->textBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(106, 141);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 26);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Логін";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(191, 192);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(200, 34);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &LoginForm::textBox2_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(80, 196);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(91, 26);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Пароль";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Gainsboro;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(229, 284);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 37);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Увійти";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &LoginForm::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Firebrick;
			this->label4->Location = System::Drawing::Point(146, 247);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(286, 22);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Невірний логін, пароль або IP сервера";
			this->label4->Visible = false;
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(191, 84);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(200, 34);
			this->textBox3->TabIndex = 1;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(45, 88);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(126, 26);
			this->label5->TabIndex = 0;
			this->label5->Text = L"IP сервера";
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Silver;
			this->ClientSize = System::Drawing::Size(568, 358);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"LoginForm";
			this->Text = L"LoginForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Boolean SqlCheckUser(String^ user, String^ pass) {
		this->connStr = "server="+serverIP+";port=3306;database=mydb;uid="+user+";password="+pass;
		MySqlConnection^ conn = gcnew MySqlConnection(this->connStr);
		
		try {
			conn->Open();
			
			MySqlCommand^ users = gcnew MySqlCommand("SELECT users.user_name, users.password, roles.role_name FROM users JOIN roles ON users.roles_id_role = roles.id_role", conn);
			MySqlDataReader^ read = users->ExecuteReader();

			while (read->Read()) {
				String^ qRes = read->GetString(0) + read->GetString(1);

				if (user+pass == qRes) {
					MainForm.permission = read->GetString(2);
					conn->Close();
					return true;
				}
			}
		}
		catch (...) {
			//MessageBox::Show(L"Не вийшло під'єднатися до серверу", L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			conn->Close();
			return false;
		}	
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (textBox2->Text->Length != 0) {
			int pos = textBox2->Text->Length - 1;
			String^ ins = Convert::ToString(textBox2->Text[pos]);

			if (ins[0] != L'*') passwd = gcnew String(passwd + ins);
			
			String^ stars = gcnew String(L'*', textBox2->Text->Length);
			textBox2->Text = stars;
			textBox2->SelectionStart = textBox2->Text->Length;
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ user = textBox1->Text;

		serverIP = textBox3->Text;

		if (SqlCheckUser(user, passwd)) {
			MainForm.connStr = this->connStr;
			MainForm.Show();
			this->Hide();
		}
		else {
			label4->Visible = true;
			passwd = gcnew String(L'*', 0);
		}
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	
	}

};
}

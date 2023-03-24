#pragma once


System::Drawing::Drawing2D::GraphicsPath^ GetFigurePath(System::Drawing::RectangleF rect, float radius);

System::Void MakeFigureRounded();


namespace TOPD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		String^ permission;
		String^ connStr = nullptr;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(636, 441);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(209, 58);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			this->button1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::button1_Paint);
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Location = System::Drawing::Point(603, 143);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(508, 224);
			this->panel1->TabIndex = 2;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(14, 17);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(404, 173);
			this->dataGridView1->TabIndex = 3;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1349, 657);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	
	private: System::Void button1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		//GraphicsPath^ buttonPath = gcnew GraphicsPath;
		//Rectangle newRectangle = button1->ClientRectangle;
		//newRectangle.Inflate(-5, -5);
		//buttonPath->AddArc(newRectangle.X, newRectangle.Y, 20, 20, 180, 90);
		//buttonPath->AddArc(newRectangle.X + newRectangle.Width - 20, newRectangle.Y, 20, 20, 270, 90);
		//buttonPath->AddArc(newRectangle.X + newRectangle.Width - 20, newRectangle.Y + newRectangle.Height - 20, 20, 20, 0, 90);
		//buttonPath->AddArc(newRectangle.X, newRectangle.Y + newRectangle.Height - 20, 20, 20, 90, 90);
		//buttonPath->CloseAllFigures();
		//
		//// Draw the border of the button.
		////e->Graphics->DrawPath(gcnew System::Drawing::Pen(System::Drawing::Color::DarkGray), buttonPath);
		//
		//// Fill the button with a color.
		////System::Drawing::Brush^ brush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::MediumBlue);
		////e->Graphics->FillPath(brush, buttonPath);
		//
		//
		//// Set the Region property of the button to the region created from the GraphicsPath object.
		//button1->Region = gcnew System::Drawing::Region(buttonPath);

		float borderSize = 0.f;
		float borderRadius = button1->Height - 5.f;
		//button1->BackColor = Color::LightBlue;
		Color borderColor = Color::PaleVioletRed;
		borderColor = button1->BackColor;


		RectangleF rectSurface = RectangleF(0, 0, button1->Width, button1->Height);
		RectangleF rectBorder = RectangleF::Inflate(rectSurface, -borderSize, -borderSize);

		if (borderSize >= 1) {
			e->Graphics->SmoothingMode = SmoothingMode::HighQuality;

			GraphicsPath^ pathSurface = GetFigurePath(rectSurface, borderRadius);
			GraphicsPath^ pathBorder = GetFigurePath(rectBorder, borderRadius - 1.f);
			Pen^ penSurface = gcnew Pen(button1->Parent->BackColor, 2);
			Pen^ penBorder = gcnew Pen(borderColor, borderSize);

			penBorder->Alignment = PenAlignment::Inset;
			//Button surface
			button1->Region = gcnew System::Drawing::Region(pathSurface);
			//Draw surface border for HD result
			e->Graphics->DrawPath(penSurface, pathSurface);
			e->Graphics->DrawPath(penBorder, pathBorder);
		}
		else {//borderless
			e->Graphics->SmoothingMode = SmoothingMode::HighQuality;
			//Button surface
			GraphicsPath^ pathSurface = GetFigurePath(rectSurface, borderRadius);
			
			Pen^ penSurface = gcnew Pen(button1->Parent->BackColor, 2);
			
			//Button surface
			button1->Region = gcnew System::Drawing::Region(pathSurface);
			//Draw surface border for HD result
			e->Graphics->DrawPath(penSurface, pathSurface);
			
		}
	}
	private: System::Void MyForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		Application::Exit();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
};
}

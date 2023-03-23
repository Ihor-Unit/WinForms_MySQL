#pragma once

System::Drawing::Drawing2D::GraphicsPath^ GetFigurePath(System::Drawing::RectangleF rect, float radius);

namespace TOPD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

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
	private: System::Diagnostics::EventLog^ eventLog1;



	protected:

	protected:

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
			this->eventLog1 = (gcnew System::Diagnostics::EventLog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eventLog1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(323, 131);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(171, 50);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			this->button1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::button1_Paint);
			// 
			// eventLog1
			// 
			this->eventLog1->SynchronizingObject = this;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1035, 491);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->eventLog1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	
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

	float borderSize = 1.f;
	float borderRadius = 40.f;
	button1->BackColor = Color::LightBlue;
	Color borderColor = Color::PaleVioletRed;
	
	e->Graphics->SmoothingMode = SmoothingMode::AntiAlias;

	RectangleF rectSurface = RectangleF(0, 0, button1->Width, button1->Height);
	RectangleF rectBorder = RectangleF(1, 1, button1->Width - 0.8f, button1->Height - 1.f);
	
	if (borderRadius > 2) {
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
	else {//normal butt
		//Button surface
		this->Region = gcnew System::Drawing::Region(rectSurface);
		//Button border
		if (borderSize >= 1) {
			Pen^ penBorder = gcnew Pen(borderColor, borderSize);

			penBorder->Alignment = PenAlignment::Inset;
			e->Graphics->DrawRectangle(penBorder, 0, 0, this->Width - 1, this->Height - 1);
		}
	}
}
};
}

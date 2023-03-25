#pragma once


System::Drawing::Drawing2D::GraphicsPath^ GetFigurePath(System::Drawing::RectangleF rect, float radius);

template<typename T>
System::Void MakeFigureRounded(T^ figure, System::Windows::Forms::PaintEventArgs^ e, float borderRadius = 20.f) {
	RectangleF rectSurface = RectangleF(0, 0, figure->Width, figure->Height);
	e->Graphics->SmoothingMode = SmoothingMode::AntiAlias;
	//Button surface
	GraphicsPath^ pathSurface = GetFigurePath(rectSurface, borderRadius);

	Pen^ penSurface = gcnew Pen(figure->Parent->BackColor, 2);

	//Button surface
	figure->Region = gcnew System::Drawing::Region(pathSurface);
	//Draw surface border for HD result
	e->Graphics->DrawPath(penSurface, pathSurface);
}



namespace TOPD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	using namespace MySql::Data::MySqlClient;

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
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;


	public:

	public:

	public:

	public:

	public:
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(77, 120);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(209, 58);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			this->button1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::button1_Paint);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->Location = System::Drawing::Point(556, 481);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1288, 334);
			this->dataGridView1->TabIndex = 3;
			this->dataGridView1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::dataGridView1_Paint);
			// 
			// chart1
			// 
			this->chart1->BackImageTransparentColor = System::Drawing::SystemColors::Control;
			this->chart1->BackSecondaryColor = System::Drawing::SystemColors::Control;
			this->chart1->BorderlineColor = System::Drawing::SystemColors::Control;
			this->chart1->BorderSkin->PageColor = System::Drawing::SystemColors::Control;
			chartArea1->AxisY->MajorTickMark->LineWidth = 0;
			chartArea1->BackColor = System::Drawing::Color::White;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Alignment = System::Drawing::StringAlignment::Center;
			legend1->BackColor = System::Drawing::Color::White;
			legend1->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			legend1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			legend1->InterlacedRowsColor = System::Drawing::SystemColors::Control;
			legend1->IsTextAutoFit = false;
			legend1->Name = L"Legend1";
			legend1->TitleBackColor = System::Drawing::SystemColors::Control;
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(1472, 40);
			this->chart1->Name = L"chart1";
			series1->BackImageTransparentColor = System::Drawing::SystemColors::Control;
			series1->BackSecondaryColor = System::Drawing::SystemColors::Control;
			series1->BorderColor = System::Drawing::SystemColors::Control;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Doughnut;
			series1->Color = System::Drawing::SystemColors::ButtonShadow;
			series1->CustomProperties = L"PieLineColor=Control, CollectedColor=Control";
			series1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			series1->IsValueShownAsLabel = true;
			series1->LabelForeColor = System::Drawing::Color::White;
			series1->Legend = L"Legend1";
			series1->MarkerBorderColor = System::Drawing::Color::White;
			series1->Name = L"Series1";
			series1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::BrightPastel;
			series1->ShadowColor = System::Drawing::SystemColors::Control;
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(407, 334);
			this->chart1->TabIndex = 4;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			this->chart1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::chart1_Paint);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(247)),
				static_cast<System::Int32>(static_cast<System::Byte>(251)));
			this->ClientSize = System::Drawing::Size(1924, 853);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Система обліку пораненних";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
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
		MySqlConnection^ conn = gcnew MySqlConnection(this->connStr);
		conn->Open();

		//MySqlCommand^ cmd = gcnew MySqlCommand(L"SELECT patients.id_no AS ID, patients.full_name AS Повне_імя, patients.age AS Вік, patients.gender AS Стать, patients.disease AS Хвороба, bills.amount AS Сума, doctors.full_name AS Імя_доктора, patients.room_no AS Палата, rooms.room_type AS Тип_палати FROM patients LEFT JOIN bills ON patients.bill_no = bills.bill_no LEFT JOIN doctors ON patients.doctor_id = doctors.doctor_id LEFT JOIN rooms ON patients.room_no = rooms.room_no", conn);
		//
		//// execute the command and retrieve the data
		//MySqlDataReader^ reader = cmd->ExecuteReader();
		//
		//// iterate through the data and add it to the ListBox control
		//while (reader->Read()) {
		//	// get the data for the current row
		//	String^ data = reader->GetString("ID") + ", " + reader->GetString(L"Повне_імя") + ", " + reader->GetString(L"Вік") + ", " + reader->GetString(L"Стать");
		//	// add the data to the ListBox control
		//	listBox1->Items->Add(data);
		//}
		//
		//// close the reader and the connection
		//reader->Close();
		//conn->Close();

		MySqlDataAdapter^ da = gcnew MySqlDataAdapter(L"SELECT patients.id_no AS ID, patients.full_name AS Повне_імя, patients.age AS Вік, patients.gender AS Стать, patients.disease AS Хвороба, bills.amount AS Сума, doctors.full_name AS Імя_доктора, patients.room_no AS Палата, rooms.room_type AS Тип_палати FROM patients LEFT JOIN bills ON patients.bill_no = bills.bill_no LEFT JOIN doctors ON patients.doctor_id = doctors.doctor_id LEFT JOIN rooms ON patients.room_no = rooms.room_no", conn);
		DataTable^ dt = gcnew DataTable();

		da->Fill(dt);

		dataGridView1->DataSource = dt;

		for (int row = 0; row < dataGridView1->RowCount; row++) {
			// iterate through the columns of the current row
			for (int col = 0; col < dataGridView1->ColumnCount; col++) {
				// get the value of the current cell
				if (dataGridView1->Rows[row]->Cells[col]->Value != nullptr) {
					String^ value = dataGridView1->Rows[row]->Cells[col]->Value->ToString();
				}
			}
		}
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void chart1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		MakeFigureRounded(chart1, e);
	}
	private: System::Void dataGridView1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		MakeFigureRounded(dataGridView1, e);
	}
	};
}

//adfasdfasdfasdf
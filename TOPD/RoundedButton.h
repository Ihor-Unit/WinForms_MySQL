#pragma once
using namespace System;
using namespace System::Text;
using namespace System::Threading::Tasks;
using namespace System::Collections::Generic;

using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;

ref class RoundedButton : public Button {
public:
	RoundedButton();

protected: 
	void  OnPaint(PaintEventArgs^ e) override;

	void OnHandleCreated(EventArgs^ e) override;
private:
	GraphicsPath^ GetFigurePath(RectangleF rect, float radius);

	void Container_BackColorChanged(Object^ sender, EventArgs^ e);


	int borderSize = 0;
	int borderRadius = 40;
	Color borderColor = Color::PaleVioletRed;
};


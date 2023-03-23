#include "RoundedButton.h"

RoundedButton::RoundedButton(){
	this->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
	this->FlatAppearance->BorderSize = 0;
	this->Size = System::Drawing::Size(150, 40);
	this->BackColor = Color::MediumSlateBlue;
	this->ForeColor = Color::White;
}

GraphicsPath^ RoundedButton::GetFigurePath(RectangleF rect, float radius){
	GraphicsPath^ path = gcnew GraphicsPath();
	path->StartFigure();
	path->AddArc(rect.X, rect.Y, radius, radius, 180, 90);
	path->AddArc(rect.Width - radius, rect.Y, radius, radius, 270, 90);
	path->AddArc(rect.Width - radius, rect.Height - radius, radius, radius, 0, 90);
	path->AddArc(rect.X, rect.Height - radius, radius, radius, 90, 90);
	path->CloseFigure();

	return path;
}


void RoundedButton::OnPaint(PaintEventArgs^ e) {
	Button::OnPaint(e);// ?
	e->Graphics->SmoothingMode = SmoothingMode::AntiAlias;

	RectangleF rectSurface = RectangleF(0, 0, this->Width, this->Height);
	RectangleF rectBorder  = RectangleF(1, 1, this->Width - 0.8f, this->Height - 1);
	
	if (borderRadius > 2) {//rounded button
		GraphicsPath^ pathSurface = GetFigurePath(rectSurface, borderRadius);
		GraphicsPath^ pathBorder  = GetFigurePath(rectBorder, borderRadius - 1.f);
		Pen^ penSurface = gcnew Pen(this->Parent->BackColor, 2);
		Pen^ penBorder = gcnew Pen(borderColor, borderSize);

		penBorder->Alignment = PenAlignment::Inset;
		//Button surface
		this->Region = gcnew System::Drawing::Region(pathSurface);
		//Draw surface border for HD result
		e->Graphics->DrawPath(penSurface, pathSurface);

		//button border
		if (borderSize >= 1) {
			//Draw control border
			e->Graphics->DrawPath(penBorder, pathBorder);
		}
		
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

void RoundedButton::Container_BackColorChanged(Object^ sender, EventArgs^ e) {
	if (this->DesignMode) {
		this->Invalidate();
	}
}	

void RoundedButton::OnHandleCreated(EventArgs^ e){
	Button::OnHandleCreated(e);
	this->Parent->BackColorChanged += gcnew EventHandler(this, &RoundedButton::Container_BackColorChanged);
}

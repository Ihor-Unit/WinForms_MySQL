#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::SqlClient;

[STAThreadAttribute]
void Main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    //WinformCDemo is your project name
    TOPD::MyForm BaseForm;
    Application::Run(%BaseForm);
}
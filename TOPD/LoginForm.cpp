#include "LoginForm.h"

using namespace System;
using namespace System::Windows::Forms;

using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;

[STAThreadAttribute]
void Main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    TOPD::LoginForm LoginForm;

    Application::Run(%LoginForm);
}
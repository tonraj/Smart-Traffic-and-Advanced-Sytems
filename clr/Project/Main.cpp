#include "Main.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project::Main form;
	Application::Run(% form);
}
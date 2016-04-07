#include "HeapSort.h"
#include <d-heap.h>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^args)
{
	Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
	sample_heapsort::HeapSort form;
    Application::Run(%form);
}
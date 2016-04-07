#pragma once
#include <d-heap.h>

namespace sample_heapsort {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для HeapSort
	/// </summary>
	public ref class HeapSort : public System::Windows::Forms::Form
	{
	public:
		int tmp1, tmp2;
		int tmp3, c;
		DHeap<int> *a;
	private: System::Windows::Forms::Label^  label5;
	public: 


	private: System::Windows::Forms::ProgressBar^  progressBar1;

	private: System::Windows::Forms::Label^  label6;

	private: System::Windows::Forms::Button^  button3;

	private: System::Windows::Forms::TextBox^  textBox1;

	private: System::Windows::Forms::Button^  button2;
	public: 
			 HeapSort(void)
		{
			InitializeComponent();
			c = 0;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~HeapSort()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;


	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::NumericUpDown^  arn;
	private: System::Windows::Forms::NumericUpDown^  siz;
	private: System::ComponentModel::IContainer^  components;



	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->arn = (gcnew System::Windows::Forms::NumericUpDown());
			this->siz = (gcnew System::Windows::Forms::NumericUpDown());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->arn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->siz))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(33, 293);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(182, 25);
			this->textBox1->TabIndex = 16;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &HeapSort::textBox1_TextChanched);
			this->textBox1->KeyUp += gcnew KeyEventHandler(this, &HeapSort::textBox1_KeyUp);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 23));
			this->label1->Location = System::Drawing::Point(27, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(419, 35);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Пирамидальная сортировка";
			this->label1->Click += gcnew System::EventHandler(this, &HeapSort::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label2->Location = System::Drawing::Point(28, 59);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 26);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Введите:";
			this->label2->Click += gcnew System::EventHandler(this, &HeapSort::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(30, 121);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Арность";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(30, 163);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(71, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Размер кучи";
			this->label4->Click += gcnew System::EventHandler(this, &HeapSort::label4_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(57, 215);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Далее";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &HeapSort::button1_Click_1);
			// 
			// arn
			// 
			this->arn->Location = System::Drawing::Point(85, 121);
			this->arn->Name = L"arn";
			this->arn->Size = System::Drawing::Size(65, 20);
			this->arn->TabIndex = 7;
			// 
			// siz
			// 
			this->siz->Location = System::Drawing::Point(108, 163);
			this->siz->Name = L"siz";
			this->siz->Size = System::Drawing::Size(42, 20);
			this->siz->TabIndex = 8;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(360, 390);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Сортирнуть";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &HeapSort::button2_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(30, 265);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(73, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Введите кучу";
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(441, 390);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(100, 23);
			this->progressBar1->TabIndex = 13;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->label6->Location = System::Drawing::Point(258, 121);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(214, 22);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Введите данные справа";
			this->label6->Click += gcnew System::EventHandler(this, &HeapSort::label6_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(198, 390);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(148, 23);
			this->button3->TabIndex = 17;
			this->button3->Text = L"Вывести кучу ещё раз";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &HeapSort::button3_Click_1);
			// 
			// HeapSort
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(750, 435);
			this->Controls->Add(this->button3);
			this->Controls->Add(textBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->siz);
			this->Controls->Add(this->arn);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"HeapSort";
			this->Text = L"HeapSort";
			this->Load += gcnew System::EventHandler(this, &HeapSort::HeapSort_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->arn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->siz))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 tmp1 = Convert::ToInt32(siz->Value);
			tmp2 = Convert::ToInt32(arn->Value);
			a = new DHeap<int>(tmp1,tmp2);
			label6->Text = Convert::ToString(' ');
		}

private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
				  }
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
				  }
private: System::Void HeapSort_Load(System::Object^  sender, System::EventArgs^  e) {
				  }
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void arnost_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void size_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
			tmp1 = Convert::ToInt32(siz->Value);
			tmp2 = Convert::ToInt32(arn->Value);
			a = new DHeap<int>(tmp2,tmp1);	
			label6->Text = Convert::ToString("");
		 }

private: System::Void elementHost1_ChildChanged(System::Object^  sender, System::Windows::Forms::Integration::ChildChangedEventArgs^  e) {		 }

private: System::Void ovalShape1_Click(System::Object^  sender, System::EventArgs^  e) {

		 }

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void flowLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

		 }

private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		 }

private: System::Void textBox1_TextChanched (System::Object^  sender, System::EventArgs^  e) { 
		 }

private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		 }

private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void textBox1_KeyUp(System::Object^  sender, KeyEventArgs^  e) {
			 if ((e->KeyCode == Keys::Enter) && (c <=tmp1))
			 {	
					tmp3 = Convert::ToInt32(textBox1->Text);
					a->vstavka(c,tmp3);
					c++;
					label6->Text += Convert::ToString(a->vyvod(c-1));
					label6->Text += Convert::ToString(" ");
					textBox1->Text = ("");
			}			
};

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
					 label6->Text = Convert::ToString("");
					  a->okych();
					  int z = tmp1;
					  for (int i=z-1;i>=0;i--)
					  {
						  a->trans(0,i);
						  a->pogryzh(0);
					  }
				  }

private: System::Void button3_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 label6->Text = Convert::ToString("");
			 for (int i=0; i<tmp1; i++)
			 {
				 label6->Text += Convert::ToString(a->vyvod(i));
					label6->Text += Convert::ToString(" ");
			 }
		 }
};
		 }

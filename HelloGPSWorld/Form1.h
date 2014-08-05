#pragma once

namespace HelloGPSWorld {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  tbTempF;
	protected: 
	private: System::Windows::Forms::TextBox^  tbTempC;
	private: System::Windows::Forms::Button^  btnConvert;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tbTempF = (gcnew System::Windows::Forms::TextBox());
			this->tbTempC = (gcnew System::Windows::Forms::TextBox());
			this->btnConvert = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// tbTempF
			// 
			this->tbTempF->Location = System::Drawing::Point(141, 136);
			this->tbTempF->Name = L"tbTempF";
			this->tbTempF->Size = System::Drawing::Size(100, 22);
			this->tbTempF->TabIndex = 0;
			// 
			// tbTempC
			// 
			this->tbTempC->Location = System::Drawing::Point(141, 179);
			this->tbTempC->Name = L"tbTempC";
			this->tbTempC->Size = System::Drawing::Size(100, 22);
			this->tbTempC->TabIndex = 1;
			// 
			// btnConvert
			// 
			this->btnConvert->Location = System::Drawing::Point(280, 134);
			this->btnConvert->Name = L"btnConvert";
			this->btnConvert->Size = System::Drawing::Size(213, 67);
			this->btnConvert->TabIndex = 2;
			this->btnConvert->Text = L"Convert!";
			this->btnConvert->UseVisualStyleBackColor = true;
			this->btnConvert->Click += gcnew System::EventHandler(this, &Form1::btnConvert_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 136);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Fahrenheit";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(29, 179);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Celsius";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Crimson;
			this->label3->Location = System::Drawing::Point(32, 32);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(662, 40);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Brian\'s Totally Awesome Temperature Converter";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(779, 625);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnConvert);
			this->Controls->Add(this->tbTempC);
			this->Controls->Add(this->tbTempF);
			this->Name = L"Form1";
			this->Text = L"BTATC";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnConvert_Click(System::Object^  sender, System::EventArgs^  e) {

				 double temp;
				 if(tbTempF->Text == String::Empty) {
					 tbTempC->Text = String::Empty;
				 } else {
					 temp = Convert::ToDouble(tbTempF->Text) - 32.0;
					 temp = temp / 9.0;
					 temp = temp * 5.0;
					 tbTempC->Text = temp.ToString(".00");
				 }
			 } // end btnConvert_Click
	};
}


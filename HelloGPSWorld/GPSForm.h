#ifndef _GPSForm_
#define _GPSForm_

#pragma once

namespace HelloGPSWorld {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::IO::Ports;
	using namespace System::Threading;

	/// <summary>
	/// Summary for GPSForm
	/// </summary>
	public ref class GPSForm : public System::Windows::Forms::Form
	{
	public:
		GPSForm(void)
		{
			InitializeComponent();
			
			// Find the available COM ports, set it to the first one.
			FindPorts();
			if(this->cbComPort->Items->Count > 0)
				this->cbComPort->Text = (String^) this->cbComPort->Items[0];


			// Set up backgroundWorker
			bgwMonitorGPS->DoWork += gcnew DoWorkEventHandler( this, &GPSForm::bgwMonitorGPS_DoWork );
			bgwMonitorGPS->RunWorkerCompleted += gcnew RunWorkerCompletedEventHandler( this, &GPSForm::bgwMonitorGPS_RunWorkerCompleted );
			bgwMonitorGPS->ProgressChanged += gcnew ProgressChangedEventHandler( this, &GPSForm::bgwMonitorGPS_ProgressChanged );
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GPSForm()
		{
			if (components)
			{
				delete components;
			}
		}
    // Functions that will live in the .cpp file
	private:void FindPorts(void);
	private:void handleGPSOutput(String^);

	private: System::Windows::Forms::Label^  label1;
	protected: 

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  btnOpenCOMPort;

	private: System::Windows::Forms::Button^  btnStartGPS;

	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::ComboBox^  cbComPort;
	private: System::Windows::Forms::Button^  btnCloseCOMPort;
	private: System::Windows::Forms::RichTextBox^  rtbGPSOutput;
	private: System::Windows::Forms::ProgressBar^  pbCOMPortStatus;
	private: System::Windows::Forms::Label^  label3;
	private: System::ComponentModel::BackgroundWorker^  bgwMonitorGPS;
	private: System::Windows::Forms::Button^  btnStopGPS;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  tbLatitude;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  tbLongitude;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  tbAltitude;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  tbAltitudeUnits;

	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  tbSpeedMPH;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  tbSpeedF_S;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  tbSpeedM_S;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  tbHeading;


	private:
		/// <summary>
		 StreamWriter^ din;

		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(GPSForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnOpenCOMPort = (gcnew System::Windows::Forms::Button());
			this->btnStartGPS = (gcnew System::Windows::Forms::Button());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->cbComPort = (gcnew System::Windows::Forms::ComboBox());
			this->btnCloseCOMPort = (gcnew System::Windows::Forms::Button());
			this->rtbGPSOutput = (gcnew System::Windows::Forms::RichTextBox());
			this->pbCOMPortStatus = (gcnew System::Windows::Forms::ProgressBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->bgwMonitorGPS = (gcnew System::ComponentModel::BackgroundWorker());
			this->btnStopGPS = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbLatitude = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbLongitude = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tbAltitude = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tbAltitudeUnits = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tbSpeedMPH = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tbSpeedF_S = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->tbSpeedM_S = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->tbHeading = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(146, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(241, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Kairos Epic GPS";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(544, 106);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"COM Port:";
			// 
			// btnOpenCOMPort
			// 
			this->btnOpenCOMPort->Location = System::Drawing::Point(145, 73);
			this->btnOpenCOMPort->Name = L"btnOpenCOMPort";
			this->btnOpenCOMPort->Size = System::Drawing::Size(172, 24);
			this->btnOpenCOMPort->TabIndex = 3;
			this->btnOpenCOMPort->Text = L"Open COM Port";
			this->btnOpenCOMPort->UseVisualStyleBackColor = true;
			this->btnOpenCOMPort->Click += gcnew System::EventHandler(this, &GPSForm::btnOpenCOMPort_Click);
			// 
			// btnStartGPS
			// 
			this->btnStartGPS->Location = System::Drawing::Point(147, 109);
			this->btnStartGPS->Name = L"btnStartGPS";
			this->btnStartGPS->Size = System::Drawing::Size(169, 24);
			this->btnStartGPS->TabIndex = 4;
			this->btnStartGPS->Text = L"Start GPS Logging";
			this->btnStartGPS->UseVisualStyleBackColor = true;
			this->btnStartGPS->Click += gcnew System::EventHandler(this, &GPSForm::btnStartGPS_Click);
			// 
			// serialPort1
			// 
			this->serialPort1->BaudRate = 4800;
			// 
			// cbComPort
			// 
			this->cbComPort->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbComPort->FormattingEnabled = true;
			this->cbComPort->Location = System::Drawing::Point(624, 102);
			this->cbComPort->Name = L"cbComPort";
			this->cbComPort->Size = System::Drawing::Size(84, 24);
			this->cbComPort->TabIndex = 5;
			// 
			// btnCloseCOMPort
			// 
			this->btnCloseCOMPort->Enabled = false;
			this->btnCloseCOMPort->Location = System::Drawing::Point(324, 73);
			this->btnCloseCOMPort->Name = L"btnCloseCOMPort";
			this->btnCloseCOMPort->Size = System::Drawing::Size(146, 24);
			this->btnCloseCOMPort->TabIndex = 6;
			this->btnCloseCOMPort->Text = L"Close COM Port";
			this->btnCloseCOMPort->UseVisualStyleBackColor = true;
			this->btnCloseCOMPort->Click += gcnew System::EventHandler(this, &GPSForm::btnCloseCOMPort_Click);
			// 
			// rtbGPSOutput
			// 
			this->rtbGPSOutput->HideSelection = false;
			this->rtbGPSOutput->Location = System::Drawing::Point(27, 188);
			this->rtbGPSOutput->Name = L"rtbGPSOutput";
			this->rtbGPSOutput->ReadOnly = true;
			this->rtbGPSOutput->Size = System::Drawing::Size(590, 271);
			this->rtbGPSOutput->TabIndex = 7;
			this->rtbGPSOutput->Text = L"";
			// 
			// pbCOMPortStatus
			// 
			this->pbCOMPortStatus->Location = System::Drawing::Point(652, 36);
			this->pbCOMPortStatus->Name = L"pbCOMPortStatus";
			this->pbCOMPortStatus->Size = System::Drawing::Size(56, 23);
			this->pbCOMPortStatus->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(533, 39);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(117, 17);
			this->label3->TabIndex = 9;
			this->label3->Text = L"COM Port Status:";
			// 
			// bgwMonitorGPS
			// 
			this->bgwMonitorGPS->WorkerReportsProgress = true;
			this->bgwMonitorGPS->WorkerSupportsCancellation = true;
			// 
			// btnStopGPS
			// 
			this->btnStopGPS->Enabled = false;
			this->btnStopGPS->Location = System::Drawing::Point(324, 109);
			this->btnStopGPS->Name = L"btnStopGPS";
			this->btnStopGPS->Size = System::Drawing::Size(146, 24);
			this->btnStopGPS->TabIndex = 10;
			this->btnStopGPS->Text = L"Stop GPS Logging";
			this->btnStopGPS->UseVisualStyleBackColor = true;
			this->btnStopGPS->Click += gcnew System::EventHandler(this, &GPSForm::btnStopGPS_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(24, 168);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(88, 17);
			this->label4->TabIndex = 11;
			this->label4->Text = L"GPS Output:";
			// 
			// tbLatitude
			// 
			this->tbLatitude->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->tbLatitude->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbLatitude->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->tbLatitude->Location = System::Drawing::Point(739, 191);
			this->tbLatitude->Name = L"tbLatitude";
			this->tbLatitude->ReadOnly = true;
			this->tbLatitude->Size = System::Drawing::Size(100, 15);
			this->tbLatitude->TabIndex = 12;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(675, 191);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(63, 17);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Latitude:";
			// 
			// tbLongitude
			// 
			this->tbLongitude->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->tbLongitude->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbLongitude->Location = System::Drawing::Point(739, 221);
			this->tbLongitude->Name = L"tbLongitude";
			this->tbLongitude->ReadOnly = true;
			this->tbLongitude->Size = System::Drawing::Size(100, 15);
			this->tbLongitude->TabIndex = 14;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(663, 221);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(75, 17);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Longitude:";
			// 
			// tbAltitude
			// 
			this->tbAltitude->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->tbAltitude->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbAltitude->Location = System::Drawing::Point(739, 250);
			this->tbAltitude->Name = L"tbAltitude";
			this->tbAltitude->ReadOnly = true;
			this->tbAltitude->Size = System::Drawing::Size(74, 15);
			this->tbAltitude->TabIndex = 16;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(677, 250);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(59, 17);
			this->label7->TabIndex = 17;
			this->label7->Text = L"Altitude:";
			// 
			// tbAltitudeUnits
			// 
			this->tbAltitudeUnits->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->tbAltitudeUnits->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbAltitudeUnits->Location = System::Drawing::Point(819, 250);
			this->tbAltitudeUnits->Name = L"tbAltitudeUnits";
			this->tbAltitudeUnits->ReadOnly = true;
			this->tbAltitudeUnits->Size = System::Drawing::Size(20, 15);
			this->tbAltitudeUnits->TabIndex = 18;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(683, 298);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(53, 17);
			this->label8->TabIndex = 19;
			this->label8->Text = L"Speed:";
			// 
			// tbSpeedMPH
			// 
			this->tbSpeedMPH->Location = System::Drawing::Point(739, 295);
			this->tbSpeedMPH->Name = L"tbSpeedMPH";
			this->tbSpeedMPH->Size = System::Drawing::Size(74, 22);
			this->tbSpeedMPH->TabIndex = 20;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(819, 298);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(38, 17);
			this->label9->TabIndex = 21;
			this->label9->Text = L"MPH";
			// 
			// tbSpeedF_S
			// 
			this->tbSpeedF_S->Location = System::Drawing::Point(739, 324);
			this->tbSpeedF_S->Name = L"tbSpeedF_S";
			this->tbSpeedF_S->Size = System::Drawing::Size(74, 22);
			this->tbSpeedF_S->TabIndex = 22;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(819, 327);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(58, 17);
			this->label10->TabIndex = 23;
			this->label10->Text = L"feet/sec";
			// 
			// tbSpeedM_S
			// 
			this->tbSpeedM_S->Location = System::Drawing::Point(739, 353);
			this->tbSpeedM_S->Name = L"tbSpeedM_S";
			this->tbSpeedM_S->Size = System::Drawing::Size(74, 22);
			this->tbSpeedM_S->TabIndex = 24;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(819, 356);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(77, 17);
			this->label11->TabIndex = 25;
			this->label11->Text = L"meters/sec";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(668, 407);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(65, 17);
			this->label12->TabIndex = 26;
			this->label12->Text = L"Heading:";
			// 
			// tbHeading
			// 
			this->tbHeading->Location = System::Drawing::Point(739, 404);
			this->tbHeading->Name = L"tbHeading";
			this->tbHeading->Size = System::Drawing::Size(74, 22);
			this->tbHeading->TabIndex = 27;
			// 
			// GPSForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DimGray;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(934, 484);
			this->Controls->Add(this->tbHeading);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->tbSpeedM_S);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->tbSpeedF_S);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->tbSpeedMPH);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->tbAltitudeUnits);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->tbAltitude);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->tbLongitude);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->tbLatitude);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->btnStopGPS);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pbCOMPortStatus);
			this->Controls->Add(this->rtbGPSOutput);
			this->Controls->Add(this->btnCloseCOMPort);
			this->Controls->Add(this->cbComPort);
			this->Controls->Add(this->btnStartGPS);
			this->Controls->Add(this->btnOpenCOMPort);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"GPSForm";
			this->Text = L"GPSForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void btnOpenCOMPort_Click(System::Object^  sender, System::EventArgs^  e) 
			 {

				 // Clear output box
				 this->rtbGPSOutput->Text = String::Empty;
				 if(this->cbComPort->Text == String::Empty) {
					 this->rtbGPSOutput->Text = "Please select COM Port before initializing.";
				 } else {
					 try {
						 if(! this->serialPort1->IsOpen) {
							 this->serialPort1->PortName = cbComPort->Text;
							 this->serialPort1->BaudRate = 4800;
							 this->serialPort1->Open();
							 this->pbCOMPortStatus->Value=100;
							 this->rtbGPSOutput->Text = "GPS Output will appear here.";
							 this->btnOpenCOMPort->Enabled = false;
							 this->btnCloseCOMPort->Enabled = true;
						 } // if serial port not open

					 } // try
					 catch(UnauthorizedAccessException^) {
						 this->rtbGPSOutput->Text = "Failed to open port. Sorry about that.";
					 }
				 } 

			 }

			 // Close the COM port
	private: System::Void btnCloseCOMPort_Click(System::Object^  sender, System::EventArgs^  e) {

				 this->serialPort1->Close();
				 this->pbCOMPortStatus->Value=0;
				 this->btnCloseCOMPort->Enabled = false;
				 this->btnOpenCOMPort->Enabled = true;
			 }

			 // Initialize the GPS unit
	private: System::Void btnStartGPS_Click(System::Object^  sender, System::EventArgs^  e) {

				 bgwMonitorGPS->RunWorkerAsync();
				 btnStartGPS->Enabled = false;
				 btnStopGPS->Enabled = true;

				 
				String^ current = DateTime::Now.ToString("O");
				current = current->Replace(":","_");
				current = "GPSRaw_" + current + ".csv";

				 try {
					 din = File::AppendText(current);
				 } catch (Exception^ e) {
					 if (dynamic_cast<FileNotFoundException^>(e))
						 Console::WriteLine("file '{0}' not found", current);
					 else
						 Console::WriteLine("problem reading file '{0}'", current);

				 }
			 };

			 void bgwMonitorGPS_DoWork(Object^ sender, DoWorkEventArgs^ e ) {
				 // Read every line. If it's a position line, update the screen. Otherwise, dump everything to a file.

				 // Get the BackgroundWorker that raised this event.
				 BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);
				 String^ nextLine = String::Empty;
				
				 while (1) {
				
					 worker->ReportProgress(100, nextLine); // You have to have an int as the first argument you can send other stuff. http://bytes.com/topic/net/answers/486511-example-userstate-backgroundworker


					 if(worker->CancellationPending) {
						 e->Cancel = true;
						 break;
					 } else {
						 try {
							 nextLine = this->serialPort1->ReadLine();
							 din->WriteLine(nextLine);
							 //rtbGPSOutput->Text = nextLine; //rtbGPSOutput->AppendText(nextLine);
						 } catch(TimeoutException^) {
							 this->rtbGPSOutput->AppendText("GPS Timed Out");
						 }

					 } // else: Not cancelling
				 }

				 // Assign the result of the computation 
				 // to the Result property of the DoWorkEventArgs 
				 // object. This is will be available to the  
				 // RunWorkerCompleted eventhandler.
				 //e->Result = ComputeFibonacci( safe_cast<Int32>(e->Argument), worker, e );

			 } // end bgwMonitorGPS_DoWork
			 
			 void bgwMonitorGPS_RunWorkerCompleted( Object^ /*sender*/, RunWorkerCompletedEventArgs^ e ) {
				 // Close all files you need and stuff

				 // Reset button status
				 btnStartGPS->Enabled = true;
				 btnStopGPS->Enabled = false;

			 } // end bgwMonitorGPS_RunWorkerCompleted
   
			 void bgwMonitorGPS_ProgressChanged(  Object^ /*sender*/, ProgressChangedEventArgs^ e) {

				 // This function does the heavy lifting, and lives in the .cpp
				 handleGPSOutput( (String^)e->UserState );
				 din->Flush();
				 //this->rtbGPSOutput->AppendText( (String^)e->UserState);
				 // Note that we get the RTB to scroll properly by setting HideSelection to True when we initialized it. http://stackoverflow.com/questions/9416608/rich-text-box-scroll-to-the-bottom-when-new-data-is-written-to-it
				 // Parse lines based on this: http://www.gpsinformation.org/dale/nmea.htm
				 // Use a big case statement, and hopefully some built-in bits to do comma-separated fields
			 }

			 // Send the cancel signal to the background worker
	private: System::Void btnStopGPS_Click(System::Object^  sender, System::EventArgs^  e) {

				 this->bgwMonitorGPS->CancelAsync();
				 this->btnStopGPS->Enabled = false;
				 this->btnStartGPS->Enabled = true;
				 din->Close();

			 }
	};
}

#endif
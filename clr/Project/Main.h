#pragma once
#include "InfoForm.h"
#using <System.Net.Http.dll>

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Net;
	using namespace System::Net::Http;


	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:

		Main(void)
		{
			InitializeComponent();
			Console::WriteLine("Connecting to Azure SQL Database");
			database();


			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button2;






















	private: array< System::Object^ >^ towers;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
















	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;



	


	



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

		
		void database() {

				
				SqlConnectionStringBuilder ^builder = gcnew SqlClient::SqlConnectionStringBuilder ();
				builder->DataSource = "tonz.database.windows.net";
				builder->UserID = "tonz";
				builder->Password = "9893753436Raj";
				builder->InitialCatalog = "traffic";

				SqlConnection^ connection = gcnew SqlClient::SqlConnection(builder->ConnectionString);
				connection->Open();

				Console::WriteLine("Connected to Azure SQL Database");

				String^ sql = "SELECT TOP (1000) * FROM [dbo].[Towers]";

				SqlCommand ^command = gcnew SqlClient::SqlCommand(sql, connection);
				
				SqlDataReader ^reader = command->ExecuteReader();

				int i = 0;
				int Top = 20;
				int Left = 50;

				while (reader->Read())
				{
					String ^a;
					GroupBox^ groupBox1 = gcnew System::Windows::Forms::GroupBox();
					Label^ label5 = gcnew System::Windows::Forms::Label();
					Label^ label4 = gcnew System::Windows::Forms::Label();

				
				


					if (reader->GetInt32(2) >= 0 && reader->GetInt32(2) <= 100) {

						a = "Light Traffic";
						label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
							static_cast<System::Int32>(static_cast<System::Byte>(0)));
					
					}else if (reader->GetInt32(2) > 100 && reader->GetInt32(2) <= 200) {

						a = "Medium Traffic";
						label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
							static_cast<System::Int32>(static_cast<System::Byte>(0)));

					}else if (reader->GetInt32(2) > 200 && reader->GetInt32(2) <= 300) {

						a = "Heavy Traffic";
						label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
							static_cast<System::Int32>(static_cast<System::Byte>(0)));

					}
					else {
						a = "Very Heavy Traffic";
						label5->ForeColor = System::Drawing::Color::Red;
					}

					

					groupBox1->Controls->Add(label5);

					groupBox1->Controls->Add(label4);
					groupBox1->Location = System::Drawing::Point(Top, Left);
					groupBox1->Name = L"groupBox1";
					groupBox1->Size = System::Drawing::Size(287, 129);
					groupBox1->TabIndex = 0;
					groupBox1->TabStop = false;
					groupBox1->Text = L" TOWER " + reader->GetInt32(0) + " - " + reader->GetString(1);
					//groupBox1->SuspendLayout();
					//groupBox1->ResumeLayout(false);
					//groupBox1->PerformLayout();

					// 
					// label5
					// 
					label5->AutoSize = true;
					label5->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					label5->Location = System::Drawing::Point(29, 84);
					label5->Name = L"label5";
					label5->Size = System::Drawing::Size(86, 17);
					label5->TabIndex = 2;
					label5->Text = a;
					// 
					// label4
					// 
					label4->AutoSize = true;
					label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					label4->Location = System::Drawing::Point(29, 35);
					label4->Name = L"label4";
					label4->Size = System::Drawing::Size(32, 32);
					label4->TabIndex = 1;
					label4->Text = L"" + reader->GetInt32(2);
					label4->Click += gcnew System::EventHandler(this, &Main::label4_Click);

				
					//this->tabPage1->Controls->Add(label5);
					//this->tabPage1->Controls->Add(label4);
					this->tabPage1->Controls->Add(groupBox1);
					
					i = reader->GetInt32(0);
					Top = Top + 300;
				}


				this->towers = gcnew cli::array< System::Object^  >(2) {L"das", L"dasd"};

				
				for (int ii = 0; ii < i; ii++) {
					this->towers[ii] = (ii + 1);
				}

				this->comboBox1->Items->AddRange(this->towers);

				connection->Close();
				Console::WriteLine("Disconnected to Azure SQL Database");
				


			
		}

		Boolean sendmessage(int id, String ^message) {


			SqlConnectionStringBuilder^ builder = gcnew SqlClient::SqlConnectionStringBuilder();
			builder->DataSource = "tonz.database.windows.net";
			builder->UserID = "tonz";
			builder->Password = "9893753436Raj";
			builder->InitialCatalog = "traffic";

			SqlConnection^ connection = gcnew SqlClient::SqlConnection(builder->ConnectionString);
			connection->Open();

			String^ sql = "SELECT TOP (1000) * FROM [dbo].[TrafficAuthority] WHERE transmitterId = " + id;

			SqlCommand^ command = gcnew SqlClient::SqlCommand(sql, connection);

			SqlDataReader^ reader = command->ExecuteReader();

			HttpClient ^client = gcnew HttpClient();
			
			while (reader->Read())
			{
				String ^phone_number = reader->GetString(2);

			}


			connection->Close();
			return true;
		}


		void InitializeComponent(void)
		{
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(199, 61);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(102, 27);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Notify";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Main::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(199, 21);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(102, 33);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Tower Details";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Main::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 96);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"VEHICLES";
			this->label2->Click += gcnew System::EventHandler(this, &Main::label2_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1468, 591);
			this->tabControl1->TabIndex = 0;
			this->tabControl1->SelectedIndexChanged += gcnew System::EventHandler(this, &Main::tabControl1_SelectedIndexChanged);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(6, 150);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(243, 96);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(7, 82);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(242, 25);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Main::comboBox1_SelectedIndexChanged_1);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 130);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(65, 17);
			this->label5->TabIndex = 3;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(4, 62);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(107, 17);
			this->label4->TabIndex = 2;
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button3->Location = System::Drawing::Point(6, 323);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(243, 40);
			this->button3->TabIndex = 0;
			this->button3->Text = L"Refresh Data";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Main::button3_Click_1);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(6, 261);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(243, 41);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Send Message";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Main::button4_Click_1);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->button5);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1460, 562);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L" Towers ";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &Main::tabPage1_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(1340, 19);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(95, 31);
			this->button5->TabIndex = 0;
			this->button5->Text = L"Refresh";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Main::button5_Click);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1473, 591);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Main";
			this->Text = L"Smart Traffic & Manage System";
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void tabPage1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Main_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {	}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox4_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tabControl1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tabPage2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox4_Enter_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label15_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label14_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox3_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	InfoForm^ form = gcnew InfoForm();
	form->Show();
}
private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) {
	

}
private: System::Void progressBar1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox1_SelectedIndexChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button4_Click_1(System::Object^ sender, System::EventArgs^ e) {
	int selectedIndex = this->comboBox1->SelectedIndex + 1;

	String ^message = this->richTextBox1->Text;

	
	if (selectedIndex == 0 || message == nullptr || message == "") {
	
		MessageBox::Show("Please select the Tower ID and type message which you want sent to traffic authority", "Error");

	}
	else {
		Console::WriteLine("Sending Message");
		
		this->button4->Text = "Sending Message!";
		this->button4->Enabled = false;


		Boolean send = sendmessage(selectedIndex, message);

		this->button4->Enabled = true;
		this->button4->Text = "Send Message";

	}
	
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	this->button5->Enabled = false;
	this->Controls->Clear();
	InitializeComponent();
	Console::WriteLine("Refreshing Form!");
	this->database();
	this->button5->Enabled = true;

}
};
}

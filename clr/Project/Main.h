#pragma once

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;


	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
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
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;








	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button2;













	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Splitter^ splitter1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::ComboBox^ comboBox2;




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


				array<int^, 2>^ gc1 = gcnew array<int^, 2>{
					{11, 39},
					{24,136 },
					{6, 136},
					{22, 78},
					{ 48,272 },
					{ 12, 272 }
				};

				SqlConnectionStringBuilder ^builder = gcnew SqlClient::SqlConnectionStringBuilder ();
				builder->DataSource = "tonz.database.windows.net";
				builder->UserID = "tonz";
				builder->Password = "9893753436Raj";
				builder->InitialCatalog = "traffic";

				SqlConnection^ connection = gcnew SqlClient::SqlConnection(builder->ConnectionString);
				connection->Open();

				Console::WriteLine("\nQuery data example:");
				Console::WriteLine("=========================================\n");

				String^ sql = "SELECT TOP (1000) * FROM [dbo].[Towers]";

				SqlCommand ^command = gcnew SqlClient::SqlCommand(sql, connection);
				
				SqlDataReader ^reader = command->ExecuteReader();

				int i;

				array<GroupBox^>^ groupBox2 = gcnew array<GroupBox^>(2);

				while (reader->Read())
				{


					Console::WriteLine(reader->GetInt32(0));

					groupBox2[i] = (gcnew System::Windows::Forms::GroupBox());
					
					this->label3 = (gcnew System::Windows::Forms::Label());
					this->label1 = (gcnew System::Windows::Forms::Label());

					Console::WriteLine(groupBox2[i]);


					groupBox2[i]->Controls->Add(this->button2);
					groupBox2[i]->Controls->Add(this->label3);
					groupBox2[i]->Controls->Add(this->label2);
					groupBox2[i]->Controls->Add(this->label1);
					groupBox2[i]->Location = System::Drawing::Point(11, 39);
					groupBox2[i]->Name = L"groupBox2";
					groupBox2[i]->Size = System::Drawing::Size(317, 182);
					groupBox2[i]->TabIndex = 0;
					groupBox2[i]->TabStop = false;
					groupBox2[i]->Text = L"TOWER " + reader->GetInt32(0) + " - " + reader->GetString(1);
					groupBox2[i]->Enter += gcnew System::EventHandler(this, &Main::groupBox2_Enter);
					

					this->label3->AutoSize = true;
					this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					this->label3->Location = System::Drawing::Point(24, 136);
					this->label3->Name = L"label3";
					this->label3->Size = System::Drawing::Size(123, 24);
					this->label3->TabIndex = 2;
					this->label3->Text = L"Traffic is OK";
					this->label3->Click += gcnew System::EventHandler(this, &Main::label3_Click);
					

					this->label1->AutoSize = true;
					this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Yi Baiti", 28.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0)));
					this->label1->Location = System::Drawing::Point(6, 136);
					this->label1->Name = L"label1";
					this->label1->Size = System::Drawing::Size(120, 48);
					this->label1->TabIndex = 2;
					this->label1->Text = L" " + reader->GetInt32(2);
					this->label1->Click += gcnew System::EventHandler(this, &Main::label1_Click_1);

					i++;
				}
			
		}


		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			
			this->label2 = (gcnew System::Windows::Forms::Label());
			
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1449, 567);
			this->tabControl1->TabIndex = 0;
			this->tabControl1->SelectedIndexChanged += gcnew System::EventHandler(this, &Main::tabControl1_SelectedIndexChanged);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1441, 538);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Towers";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &Main::tabPage1_Click);
			
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->button9);
			this->tabPage2->Controls->Add(this->button8);
			this->tabPage2->Controls->Add(this->button7);
			this->tabPage2->Controls->Add(this->comboBox2);
			this->tabPage2->Controls->Add(this->label17);
			this->tabPage2->Controls->Add(this->label16);
			this->tabPage2->Controls->Add(this->textBox1);
			this->tabPage2->Controls->Add(this->label15);
			this->tabPage2->Controls->Add(this->label14);
			this->tabPage2->Controls->Add(this->label13);
			this->tabPage2->Controls->Add(this->label12);
			this->tabPage2->Controls->Add(this->label11);
			this->tabPage2->Controls->Add(this->splitter1);
			this->tabPage2->Controls->Add(this->tableLayoutPanel1);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1144, 538);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"History";
			this->tabPage2->UseVisualStyleBackColor = true;
			this->tabPage2->Click += gcnew System::EventHandler(this, &Main::tabPage2_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(378, 501);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(78, 31);
			this->button9->TabIndex = 12;
			this->button9->Text = L"Last";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(282, 501);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(78, 31);
			this->button8->TabIndex = 11;
			this->button8->Text = L"Next";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(186, 501);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(78, 31);
			this->button7->TabIndex = 10;
			this->button7->Text = L"Previous";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(20, 104);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(144, 24);
			this->comboBox2->TabIndex = 9;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(23, 84);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(47, 17);
			this->label17->TabIndex = 8;
			this->label17->Text = L"Tower";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(23, 20);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(109, 17);
			this->label16->TabIndex = 7;
			this->label16->Text = L"Search ENGINE";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(20, 41);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(144, 22);
			this->textBox1->TabIndex = 0;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(402, 6);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(117, 17);
			this->label15->TabIndex = 6;
			this->label15->Text = L"IN-COMING TIME";
			this->label15->Click += gcnew System::EventHandler(this, &Main::label15_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(696, 6);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(120, 17);
			this->label14->TabIndex = 5;
			this->label14->Text = L"OUTGOING TIME";
			this->label14->Click += gcnew System::EventHandler(this, &Main::label14_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(899, 6);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(77, 17);
			this->label13->TabIndex = 4;
			this->label13->Text = L"TOWER ID";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(1019, 6);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(68, 17);
			this->label12->TabIndex = 3;
			this->label12->Text = L"ACTIONS";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(186, 6);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(77, 17);
			this->label11->TabIndex = 2;
			this->label11->Text = L"ENGINE ID";
			this->label11->Click += gcnew System::EventHandler(this, &Main::label11_Click);
			// 
			// splitter1
			// 
			this->splitter1->Location = System::Drawing::Point(3, 3);
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(177, 532);
			this->splitter1->TabIndex = 1;
			this->splitter1->TabStop = false;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 5;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				22.50263F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				30.91483F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				21.55626F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.51314F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.51314F)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(186, 3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 6;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(952, 492);
			this->tableLayoutPanel1->TabIndex = 0;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Main::tableLayoutPanel1_Paint);
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
			// label3
			// 
			
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
			// label1
			// 
			
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
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
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
};
}

#pragma once
#include "stdafx.h"

namespace ten2two {

	extern vector<wchar_t> tenth;
	/// <summary>
	/// subform에 대한 요약입니다.
	/// </summary>
	public ref class subform : public System::Windows::Forms::Form
	{
	public:
		subform(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~subform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  EndButton;



	protected: 

	private: System::Windows::Forms::DataGridView^  Grid;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^  a;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  b;
	private: System::Windows::Forms::Button^  removebutton;
	private: System::Windows::Forms::Button^  SaveButton;
	private: System::Windows::Forms::Button^  InputButton;
	private: System::Windows::Forms::Button^  OutPut;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Label^  version;





	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다.
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(subform::typeid));
			this->EndButton = (gcnew System::Windows::Forms::Button());
			this->Grid = (gcnew System::Windows::Forms::DataGridView());
			this->a = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->b = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->removebutton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->InputButton = (gcnew System::Windows::Forms::Button());
			this->OutPut = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->version = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Grid))->BeginInit();
			this->SuspendLayout();
			// 
			// EndButton
			// 
			this->EndButton->Location = System::Drawing::Point(333, 258);
			this->EndButton->Name = L"EndButton";
			this->EndButton->Size = System::Drawing::Size(75, 23);
			this->EndButton->TabIndex = 0;
			this->EndButton->Text = L"취소";
			this->EndButton->UseVisualStyleBackColor = true;
			this->EndButton->Click += gcnew System::EventHandler(this, &subform::EndButton_Click);
			// 
			// Grid
			// 
			this->Grid->AllowUserToResizeColumns = false;
			this->Grid->AllowUserToResizeRows = false;
			this->Grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Grid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->a, this->b});
			this->Grid->EnableHeadersVisualStyles = false;
			this->Grid->Location = System::Drawing::Point(12, 12);
			this->Grid->Name = L"Grid";
			this->Grid->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->Grid->RowHeadersVisible = false;
			this->Grid->RowTemplate->Height = 23;
			this->Grid->Size = System::Drawing::Size(117, 269);
			this->Grid->TabIndex = 1;
			this->Grid->DefaultValuesNeeded += gcnew System::Windows::Forms::DataGridViewRowEventHandler(this, &subform::DefaultValuesNeeded);
			// 
			// a
			// 
			this->a->HeaderText = L"수";
			this->a->Name = L"a";
			this->a->ReadOnly = true;
			this->a->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->a->Width = 30;
			// 
			// b
			// 
			this->b->HeaderText = L"문자";
			this->b->MaxInputLength = 1;
			this->b->Name = L"b";
			this->b->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->b->Width = 60;
			// 
			// removebutton
			// 
			this->removebutton->Location = System::Drawing::Point(135, 258);
			this->removebutton->Name = L"removebutton";
			this->removebutton->Size = System::Drawing::Size(23, 23);
			this->removebutton->TabIndex = 2;
			this->removebutton->Text = L"-";
			this->removebutton->UseVisualStyleBackColor = true;
			this->removebutton->Click += gcnew System::EventHandler(this, &subform::removebutton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(414, 258);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(75, 23);
			this->SaveButton->TabIndex = 3;
			this->SaveButton->Text = L"확인";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &subform::SaveButton_Click);
			// 
			// InputButton
			// 
			this->InputButton->Location = System::Drawing::Point(171, 258);
			this->InputButton->Name = L"InputButton";
			this->InputButton->Size = System::Drawing::Size(75, 23);
			this->InputButton->TabIndex = 4;
			this->InputButton->Text = L"불러오기..";
			this->InputButton->UseVisualStyleBackColor = true;
			this->InputButton->Click += gcnew System::EventHandler(this, &subform::InputButton_Click);
			// 
			// OutPut
			// 
			this->OutPut->Location = System::Drawing::Point(252, 258);
			this->OutPut->Name = L"OutPut";
			this->OutPut->Size = System::Drawing::Size(75, 23);
			this->OutPut->TabIndex = 5;
			this->OutPut->Text = L"내보내기..";
			this->OutPut->UseVisualStyleBackColor = true;
			this->OutPut->Click += gcnew System::EventHandler(this, &subform::OutPut_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->DefaultExt = L"*.txt";
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"텍스트 파일|*.txt|모든 파일|*.*";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"*.txt";
			this->saveFileDialog1->Filter = L"텍스트 파일|*.txt|모든 파일|*.*";
			// 
			// version
			// 
			this->version->AutoSize = true;
			this->version->ForeColor = System::Drawing::SystemColors::GrayText;
			this->version->Location = System::Drawing::Point(135, 243);
			this->version->Name = L"version";
			this->version->Size = System::Drawing::Size(78, 12);
			this->version->TabIndex = 6;
			this->version->Text = L"ten2two 1.2.1";
			// 
			// subform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(501, 293);
			this->Controls->Add(this->version);
			this->Controls->Add(this->OutPut);
			this->Controls->Add(this->InputButton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->removebutton);
			this->Controls->Add(this->Grid);
			this->Controls->Add(this->EndButton);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"subform";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"설정";
			this->Load += gcnew System::EventHandler(this, &subform::subform_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Grid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void subform_Load(System::Object^ sender, System::EventArgs^ e) {
				for(int i=0;i<(int)tenth.size();i++){
					Grid->Rows->Add(i, tenth[i]);
				}
				Grid_CellNumberUpdate();
			}
	private: System::Void removebutton_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(Grid->Rows->Count > 3) Grid->Rows->RemoveAt(Grid->Rows->Count - 2);
				 Grid->Update();
			 }
private: System::Void DefaultValuesNeeded(System::Object^  sender, System::Windows::Forms::DataGridViewRowEventArgs^  e) {
			Grid_CellNumberUpdate();
		 }
private: System::Void Grid_CellNumberUpdate(){
			 for(int i=0;i<Grid->Rows->Count - 1; i++){
				 Grid->Rows[i]->Cells[0]->Value = i;
			 }
		 }
private: System::Void EndButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 tenth.clear();
			 for(int i=0;i<Grid->Rows->Count-1; i++){
				 System::String^ abc = (Grid->Rows[i]->Cells[1]->FormattedValue->ToString());
				 tenth.push_back(abc[0]);
			 }

			 this->Close();
		 }
private: System::Void OutPut_Click(System::Object^  sender, System::EventArgs^  e) {
			 saveFileDialog1->ShowDialog();
            if (saveFileDialog1->FileNames->Length > 0)
			{
				string path = "",
				createText = "";
				StreamWriter^ outfile;
				for(int i=0;i<saveFileDialog1->FileNames->Length;i++){
					outfile = gcnew StreamWriter(saveFileDialog1->FileNames[i]);
				}
				outfile->Write(version->Text);
				for(int i=0;i<Grid->Rows->Count-1; i++){
					outfile->Write("\r\n");
					outfile->Write(Grid->Rows[i]->Cells[1]->FormattedValue);
				}
				outfile->Close();
            }
	}
private: System::Void InputButton_Click(System::Object^  sender, System::EventArgs^  e) {
			if(openFileDialog1->ShowDialog() == ::DialogResult::OK){
            StreamReader^ sr = gcnew StreamReader(openFileDialog1->FileName);
			int i=0;
			sr->ReadLine();
			tenth.clear();
			while(!sr->EndOfStream){
				String^ a = gcnew String(sr->ReadLine());
				tenth.push_back(a[0]);
			}
			sr->Close();
			Grid->Rows->Clear();
			Grid->Refresh();
            Grid->ColumnCount = 2; 
            Grid->Columns[0]->Name = "수"; 
				Grid->Columns[1]->Name = "문자"; 
				for(int i=0;i<(int)tenth.size();i++){
					Grid->Rows->Add(i, tenth[i]);
				}
				Grid_CellNumberUpdate();
			}
		}
	};
}
/*

*/
#pragma once
#include "subform.h"
#include "stdafx.h"

namespace ten2two {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	wchar_t tenn[] = {L'0',L'1',L'2',L'3',L'4',L'5',L'6',L'7',L'8',L'9',L'a',L'b',L'c',L'd',L'e',L'f',L'g',L'h',L'i',L'j',L'k',L'l',L'm',L'n',L'o',L'p',L'q',L'r',L's',L't',L'u',L'v',L'w',L'x',L'y',L'z'};
	vector<wchar_t> tenth(std::begin(tenn),std::end(tenn));
	
	

	void MarshalString ( String ^ s, string& os ) {
    using namespace Runtime::InteropServices;
    const char* chars =
    (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	void MarshalString ( String ^ s, wstring& os ) {
    using namespace Runtime::InteropServices;
    const wchar_t* chars =
    (const wchar_t*)(Marshal::StringToHGlobalUni(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	}


	wstring Todisplay(int ten, int size){ ///
	vector<wchar_t> ntenth;
    int i = ten;
    while(i >= 1){
        ntenth.insert(ntenth.begin(),tenth[i % size]);
        i /= size;
	}
	wstring s(ntenth.begin(),ntenth.end());
	return s;

	}
	int ToTen(string str,int size){ /// 이제 사용하지 않음.
		int returnum = 0;
		int age = 1;
		string test(&tenth[size-1],&tenth[size]);
		if(size > (int)tenth.size()) throw invalid_argument("진법 계수가 너무 높습니다.");
		for(int i=(int)str.size() - 1; i > -1 ;i--){ // 각 문자마다 반복
			for(int j=0;j<size;j++){ //각 숫자마다 반복
				if(str[i] == tenth[j]){
					returnum += age * j;
					age *= size;
					goto oneloop;
				}
			}
			throw invalid_argument(
				str[i] + string(" : 숫자가 아닌 값이 포함되어 있습니다. ") + 
				test + string(" 까지만 받습니다")
				); 
			oneloop:;
		}
		return returnum;
	}
	int ToTen(wstring str,int size){ ///
		int returnum = 0;
		int age = 1;
		string test(&tenth[size-1],&tenth[size]), best;
		if(size > (int)tenth.size()) throw invalid_argument("진법 계수가 너무 높습니다.");
		for(int i=(int)str.size() - 1; i > -1 ;i--){ // 각 문자마다 반복
			for(int j=0;j<size;j++){ //각 숫자마다 반복
				if(str[i] == tenth[j]){
					returnum += age * j;
					age *= size;
					goto oneloop;
				}
			}
			best = string(&str[i],&str[i+1]);
			throw invalid_argument(
				best + string(" : 숫자가 아닌 값이 포함되어 있습니다. ") + 
				test + string(" 까지만 받습니다")
				); 
			oneloop:;
		}
		return returnum;
	}
	/// <summary>
	/// Form1에 대한 요약입니다.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  Input;
	protected: 
	private: System::Windows::Forms::Label^  Array;
	private: System::Windows::Forms::TextBox^  OutPut;
	private: System::Windows::Forms::Button^  Start;
	public: System::Windows::Forms::NumericUpDown^  inputNum;
	public: System::Windows::Forms::NumericUpDown^  outputNum;
	private: System::Windows::Forms::Button^  config;



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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->Input = (gcnew System::Windows::Forms::TextBox());
			this->Array = (gcnew System::Windows::Forms::Label());
			this->OutPut = (gcnew System::Windows::Forms::TextBox());
			this->Start = (gcnew System::Windows::Forms::Button());
			this->inputNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->outputNum = (gcnew System::Windows::Forms::NumericUpDown());
			this->config = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->inputNum))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->outputNum))->BeginInit();
			this->SuspendLayout();
			// 
			// Input
			// 
			this->Input->Location = System::Drawing::Point(12, 12);
			this->Input->Multiline = true;
			this->Input->Name = L"Input";
			this->Input->Size = System::Drawing::Size(143, 97);
			this->Input->TabIndex = 6;
			// 
			// Array
			// 
			this->Array->AutoSize = true;
			this->Array->Location = System::Drawing::Point(161, 53);
			this->Array->Name = L"Array";
			this->Array->Size = System::Drawing::Size(19, 12);
			this->Array->TabIndex = 1;
			this->Array->Text = L"->";
			// 
			// OutPut
			// 
			this->OutPut->Location = System::Drawing::Point(186, 12);
			this->OutPut->Multiline = true;
			this->OutPut->Name = L"OutPut";
			this->OutPut->ReadOnly = true;
			this->OutPut->Size = System::Drawing::Size(145, 97);
			this->OutPut->TabIndex = 2;
			// 
			// Start
			// 
			this->Start->Location = System::Drawing::Point(254, 143);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(75, 23);
			this->Start->TabIndex = 3;
			this->Start->Text = L"시작!";
			this->Start->UseVisualStyleBackColor = true;
			this->Start->Click += gcnew System::EventHandler(this, &Form1::Start_Click);
			// 
			// inputNum
			// 
			this->inputNum->Location = System::Drawing::Point(12, 115);
			this->inputNum->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {36, 0, 0, 0});
			this->inputNum->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->inputNum->Name = L"inputNum";
			this->inputNum->Size = System::Drawing::Size(143, 21);
			this->inputNum->TabIndex = 4;
			this->inputNum->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			// 
			// outputNum
			// 
			this->outputNum->Location = System::Drawing::Point(186, 115);
			this->outputNum->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {36, 0, 0, 0});
			this->outputNum->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			this->outputNum->Name = L"outputNum";
			this->outputNum->Size = System::Drawing::Size(143, 21);
			this->outputNum->TabIndex = 5;
			this->outputNum->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			// 
			// config
			// 
			this->config->Location = System::Drawing::Point(12, 144);
			this->config->Name = L"config";
			this->config->Size = System::Drawing::Size(93, 21);
			this->config->TabIndex = 7;
			this->config->Text = L"문자 수정...";
			this->config->UseVisualStyleBackColor = true;
			this->config->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(341, 178);
			this->Controls->Add(this->config);
			this->Controls->Add(this->outputNum);
			this->Controls->Add(this->inputNum);
			this->Controls->Add(this->Start);
			this->Controls->Add(this->OutPut);
			this->Controls->Add(this->Array);
			this->Controls->Add(this->Input);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"10진수 2진수 변환기";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->inputNum))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->outputNum))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion
	private: System::Void Start_Click(System::Object^  sender, System::EventArgs^  e) {
			try{
				wstring InTex;
				MarshalString(Input->Text,InTex);
				wstring synTex = Todisplay(ToTen(InTex, Decimal::ToInt32(inputNum->Value)),Decimal::ToInt32(outputNum->Value));
				String^ string2 = gcnew String(synTex.c_str());

				OutPut->Text = gcnew String(synTex.c_str());
			}
			catch (invalid_argument& e){
				OutPut->Text = gcnew String(e.what());
			}
		}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 subform^ fo = gcnew subform;
				 fo->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Form1::subform_closed);
				 fo->ShowDialog();
			 }
			 private:System::Void subform_closed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e){
			 inputNum->Maximum = tenth.size();
			 inputNum->Maximum = tenth.size();
					 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 setlocale(LC_ALL, "ko_KR.UTF-8");
		 }
};
}
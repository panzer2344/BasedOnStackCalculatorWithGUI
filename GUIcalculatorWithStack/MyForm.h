#pragma once
#include <string>
#include <msclr/marshal_cppstd.h>
#include "../../lab3stack/ClassCalculator/TCalculator.h"
#include "../../lab3stack/ClassCalculator/TCalculator.cpp"

namespace GUIcalculatorWithStack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  Expression;
	private: System::Windows::Forms::Label^  ExpressionLabel;
	protected:

	protected:

	protected:

	private: System::Windows::Forms::Label^  AnsLabel;
	private: System::Windows::Forms::Label^  AnswerField;


	private: System::Windows::Forms::Label^  EqualSign;


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
			this->Expression = (gcnew System::Windows::Forms::TextBox());
			this->ExpressionLabel = (gcnew System::Windows::Forms::Label());
			this->AnsLabel = (gcnew System::Windows::Forms::Label());
			this->AnswerField = (gcnew System::Windows::Forms::Label());
			this->EqualSign = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Expression
			// 
			this->Expression->Location = System::Drawing::Point(12, 29);
			this->Expression->Name = L"Expression";
			this->Expression->Size = System::Drawing::Size(538, 20);
			this->Expression->TabIndex = 0;
			this->Expression->Text = L"print your expression there";
			this->Expression->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Expression_MouseClick);
			this->Expression->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::Expression_KeyPress);
			this->Expression->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Expression_MouseDoubleClick);
			// 
			// ExpressionLabel
			// 
			this->ExpressionLabel->AutoSize = true;
			this->ExpressionLabel->Location = System::Drawing::Point(12, 9);
			this->ExpressionLabel->Name = L"ExpressionLabel";
			this->ExpressionLabel->Size = System::Drawing::Size(85, 13);
			this->ExpressionLabel->TabIndex = 1;
			this->ExpressionLabel->Text = L"Your expression:";
			// 
			// AnsLabel
			// 
			this->AnsLabel->AutoSize = true;
			this->AnsLabel->Location = System::Drawing::Point(587, 9);
			this->AnsLabel->Name = L"AnsLabel";
			this->AnsLabel->Size = System::Drawing::Size(42, 13);
			this->AnsLabel->TabIndex = 2;
			this->AnsLabel->Text = L"Answer";
			// 
			// AnswerField
			// 
			this->AnswerField->AutoSize = true;
			this->AnswerField->Location = System::Drawing::Point(587, 32);
			this->AnswerField->Name = L"AnswerField";
			this->AnswerField->Size = System::Drawing::Size(0, 13);
			this->AnswerField->TabIndex = 3;
			// 
			// EqualSign
			// 
			this->EqualSign->AutoSize = true;
			this->EqualSign->Location = System::Drawing::Point(556, 32);
			this->EqualSign->Name = L"EqualSign";
			this->EqualSign->Size = System::Drawing::Size(13, 13);
			this->EqualSign->TabIndex = 4;
			this->EqualSign->Text = L"=";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(791, 87);
			this->Controls->Add(this->EqualSign);
			this->Controls->Add(this->AnswerField);
			this->Controls->Add(this->AnsLabel);
			this->Controls->Add(this->ExpressionLabel);
			this->Controls->Add(this->Expression);
			this->Name = L"MyForm";
			this->Text = L"Calculator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: std::string mainfunc() {
	std::string infix;
	TCalculator tc;
	std::string result;

	if (Expression->Text == "") return "";
	infix = msclr::interop::marshal_as<std::string>(Expression->Text);
	try {
		tc = TCalculator(infix);
		tc.Check();
		result = std::to_string(tc.Calculate());
	}
	catch (char* Exception) {
		result = Exception;
	}

	return result;
}

private: System::Void Expression_TextChanged(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void Expression_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	Expression->Text = "";
}
private: System::Void Expression_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	Expression->Text = "";
}
private: System::Void Expression_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	if (e->KeyChar == wchar_t(Keys::Enter)) AnswerField->Text = gcnew String(mainfunc().c_str());
}
};
}

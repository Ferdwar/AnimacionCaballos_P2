#pragma once
#include"Controlador.h"
#include"File.h"

namespace ClaseCaballos {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			gr = this->CreateGraphics();
			buffer = BufferedGraphicsManager::Current->Allocate(gr, this->ClientRectangle);
			imgPersonaje = gcnew Bitmap("Imagenes\\caballo.png");
			imgFondo = gcnew Bitmap("Imagenes\\fondo.jpg");
			control = new Controlador();
			file = new File();
			file->readData();
			n = 0;
			
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timerMain;
	private: System::Windows::Forms::Timer^ timerTime;
	private: System::Windows::Forms::Timer^ timerPersonaje;


	protected:

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Graphics^ gr;
		BufferedGraphics^ buffer;
		Bitmap^ imgPersonaje;
		Bitmap^ imgFondo;
		Controlador* control;
		File* file;
		int n;
	private: System::Windows::Forms::Label^ lbl_time;

		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timerMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerTime = (gcnew System::Windows::Forms::Timer(this->components));
			this->timerPersonaje = (gcnew System::Windows::Forms::Timer(this->components));
			this->lbl_time = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timerMain
			// 
			this->timerMain->Enabled = true;
			this->timerMain->Tick += gcnew System::EventHandler(this, &MyForm::timerMain_Tick);
			// 
			// timerTime
			// 
			this->timerTime->Enabled = true;
			this->timerTime->Interval = 1000;
			this->timerTime->Tick += gcnew System::EventHandler(this, &MyForm::timerTime_Tick);
			// 
			// timerPersonaje
			// 
			this->timerPersonaje->Enabled = true;
			this->timerPersonaje->Tick += gcnew System::EventHandler(this, &MyForm::timerPersonaje_Tick);
			// 
			// lbl_time
			// 
			this->lbl_time->AutoSize = true;
			this->lbl_time->Location = System::Drawing::Point(250, 186);
			this->lbl_time->Name = L"lbl_time";
			this->lbl_time->Size = System::Drawing::Size(48, 16);
			this->lbl_time->TabIndex = 0;
			this->lbl_time->Text = L"tiempo";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(542, 410);
			this->Controls->Add(this->lbl_time);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timerMain_Tick(System::Object^ sender, System::EventArgs^ e) {
		//buffer->Graphics->Clear(Color::whiteSmoke);
		if (imgFondo!= nullptr)
		buffer->Graphics->DrawImage(imgFondo, 0, 0, imgFondo->Width * 2.2, imgFondo->Height * 1.6);
		control->moverPersonaje(buffer->Graphics);
		control->dibujarPersonaje(buffer->Graphics, imgPersonaje);
		buffer->Render(gr);
	}
	private: System::Void timerTime_Tick(System::Object^ sender, System::EventArgs^ e) {
		n++;
		lbl_time->Text = Convert::ToString(n);
	}
	private: System::Void timerPersonaje_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (control->getPersonaje() < 8) {
			control->addPersonaje(new Personaje(imgPersonaje->Width / 4, imgPersonaje->Height / 4,
				file->getX(), file->getY()));
		}
	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	int interval = file->getN() * 500;
	if (interval > 0) {
		timerPersonaje->Interval = interval;
	}
	else {
		// Handle the invalid interval case, e.g., set a default value or log an error
		timerPersonaje->Interval = 500; // Default value
	}

}
};
}

#pragma once

#include <cliext/vector>
#include <vector>
#include <string>
#include <algorithm>
#include "Point.h"

namespace AlgorithmCyrusBeck {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			m_Points = new std::vector<LM::Point>;
			m_Points->push_back(LM::Point(300.0f, 100.0f));
			m_Points->push_back(LM::Point(300.0f, 300.0f));
			m_Points->push_back(LM::Point(100.0f, 300.0f));
			m_Points->push_back(LM::Point(100.0f, 100.0f));
			
			m_Lines = new std::vector<LM::Line>;
			m_Lines->push_back(LM::Line(LM::Point(80.0f, 100.0f), LM::Point(450.0f, 200.0f)));
			m_Lines->push_back(LM::Line(LM::Point(150.0f, 150.0f), LM::Point(250.0f, 200.0f)));
		
			Recalculate();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			//delete m_Points;
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;





	protected:

	protected:

	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(480, 480);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(897, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(897, 38);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"label2";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Polygon", L"Line" });
			this->comboBox1->Location = System::Drawing::Point(508, 12);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(667, 12);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 4;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"A", L"B" });
			this->comboBox3->Location = System::Drawing::Point(667, 64);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(121, 21);
			this->comboBox3->TabIndex = 5;
			this->comboBox3->Visible = false;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox3_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(508, 118);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"AddPoint";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(508, 159);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"DeletePoint";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(508, 118);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 8;
			this->button3->Text = L"AddLine";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(508, 159);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 9;
			this->button4->Text = L"DeleteLine";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(508, 203);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 10;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(614, 203);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 11;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(944, 501);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

	private: 
		void Recalculate()
		{
			// Draw polygon
			std::vector<LM::Point> &Points= *m_Points;
			Bitmap^ bmp = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			Graphics^ graph = Graphics::FromImage(bmp);
			Pen^ pen = gcnew Pen(Color::Blue);
			pen->Width = 2.0f;
			for (int i = 0, j = Points.size() - 1; i < Points.size(); j = i++)
			{
				graph->DrawLine(pen, Points[i].x, Points[i].y, Points[j].x, Points[j].y);
			}

			// Check for convex polygon
			int positive = 0;
			int negative = 0;
			for (int i = 0, j = 1; i < Points.size(); i++, j++)
			{
				LM::Point v1 = Points[j % Points.size()] - Points[i];
				LM::Point v2 = Points[(j + 1) % Points.size()] - Points[(i + 1) % Points.size()];
				float crossProduct = LM::cross(v1, v2);
				if (crossProduct < 0.0f)
					negative++;
				else if (crossProduct > 0.0f)
					positive++;
			}

			float kn = 1.0f;
			if ((positive) && (negative))
			{
				pen->Color = Color::Red;
				for (const auto& line : *m_Lines)
				{
					graph->DrawLine(pen, line.A.x, line.A.y, line.B.x, line.B.y);
				}
				pictureBox1->Image = bmp;
				return;
			}
			else if (positive)
			{
				kn = -1.0f;
			}

			for (const auto &line : *m_Lines)
			{

				float t0 = 0.0f;
				float t1 = 1.0f;
				bool visible = true;
				LM::Point D = line.B - line.A;
				for (int i = 0, j = Points.size() - 1; i < Points.size(); j = i++)
				{
					LM::Point n = Points[j] - Points[i];
					n = LM::cross(n);
					n /= length(n);
					n *= kn;

					LM::Point w = line.A - Points[j];
					float dotDN = LM::dot(D, n);
					float dotWN = LM::dot(w, n);

					if ((dotDN == 0.0f) && (dotWN < 0.0f))
					{
						visible = false;
						break;
					}

					float t = -dotWN / dotDN;
					if (dotDN < 0.0f)
					{
						if (t < t0)
						{
							visible = false;
							break;
						}
						t1 = std::min(t1, t);
					}
					else
					{
						if (t > t1)
						{
							visible = false;
							break;
						}
						t0 = std::max(t0, t);
					}
				}

				if (visible && (t0 < t1))
				{
					LM::Point p1 = line.A + (D * t0);
					LM::Point p2 = line.A + (D * t1);

					pen->Color = Color::Red;
					graph->DrawLine(pen, line.A.x, line.A.y, p1.x,     p1.y);
					graph->DrawLine(pen, p2.x,     p2.y,     line.B.x, line.B.y);

					pen->Color = Color::Green;
					graph->DrawLine(pen, p1.x, p1.y, p2.x, p2.y);
				}
				else
				{
					pen->Color = Color::Red;
					graph->DrawLine(pen, line.A.x, line.A.y, line.B.x, line.B.y);
				}
			}
			pictureBox1->Image = bmp;

		}

		System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
		{
			switch (comboBox1->SelectedIndex)
			{
			case 0:
				if (comboBox2->SelectedIndex != -1)
				{
					(*m_Points)[comboBox2->SelectedIndex].x = e->X;
					(*m_Points)[comboBox2->SelectedIndex].y = e->Y;
				}
				break;
			case 1:
				if (comboBox2->SelectedIndex != -1)
				{
					if (comboBox3->SelectedIndex != -1)
					{
						(*m_Lines)[comboBox2->SelectedIndex][comboBox3->SelectedIndex].x = e->X;
						(*m_Lines)[comboBox2->SelectedIndex][comboBox3->SelectedIndex].y = e->Y;
					}
				}
				break;
			}
			label1->Text = gcnew System::String(std::to_string(e->X).c_str());
			label2->Text = gcnew System::String(std::to_string(e->Y).c_str());

			cb2();
			cb3();

			//(*m_Points)[0].x = e->X;
			//(*m_Points)[0].y = e->Y;

			Recalculate();
		}

		System::Void comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
		{
			cb3();
		}

		void cb3()
		{
			if (comboBox1->SelectedIndex != -1)
			{
				if (comboBox2->SelectedIndex != -1)
				{
					if (comboBox3->SelectedIndex != -1)
					{
						switch (comboBox1->SelectedIndex)
						{
						case 1:
							textBox1->Text = gcnew System::String(std::to_string((*m_Lines)[comboBox2->SelectedIndex][comboBox3->SelectedIndex].x).c_str());
							textBox2->Text = gcnew System::String(std::to_string((*m_Lines)[comboBox2->SelectedIndex][comboBox3->SelectedIndex].y).c_str());
							break;
						}
					}
				}
			}
		}

		System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
		{
			cb2();
		}

		void cb2()
		{
			if (comboBox1->SelectedIndex != -1)
			{
				if (comboBox2->SelectedIndex != -1)
				{
					switch (comboBox1->SelectedIndex)
					{
					case 0:
						textBox1->Text = gcnew System::String(std::to_string((*m_Points)[comboBox2->SelectedIndex].x).c_str());
						textBox2->Text = gcnew System::String(std::to_string((*m_Points)[comboBox2->SelectedIndex].y).c_str());
						break;
					case 1:
						cb3();
						break;
					}
				}
			}
		}

		System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) 
		{
			//label2->Text = gcnew System::String(std::to_string(comboBox1->SelectedIndex).c_str());
			UpdateComboBox();
		}

		void UpdateComboBox()
		{
			comboBox2->Items->Clear();
			switch (comboBox1->SelectedIndex)
			{
			case 0:
				for (int i = 0; i < m_Points->size(); i++)
					comboBox2->Items->Add(gcnew System::String(std::to_string(i).c_str()));
				comboBox3->Visible = false;
				button1->Visible = true;
				button2->Visible = true;
				button3->Visible = false;
				button4->Visible = false;
				break;
			case 1:
				for (int i = 0; i < m_Lines->size(); i++)
					comboBox2->Items->Add(gcnew System::String(std::to_string(i).c_str()));
				comboBox3->Visible = true;
				button1->Visible = false;
				button2->Visible = false;
				button3->Visible = true;
				button4->Visible = true;
				break;
			default:
				button1->Visible = false;
				button2->Visible = false;
				button3->Visible = false;
				button4->Visible = false;
				comboBox3->Visible = false;
				break;
			}
		}

		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			m_Points->insert(m_Points->begin() + (comboBox2->SelectedIndex + 1), LM::Point(100.0f));

			UpdateComboBox();
			Recalculate();
		}

		System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (comboBox2->SelectedIndex != -1)
			{
				if (m_Points->size() > 3)
				{
					m_Points->erase(m_Points->begin() + comboBox2->SelectedIndex);
				}
			}
			UpdateComboBox();
			Recalculate();
		}

		System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			m_Lines->push_back(LM::Line(LM::Point(100.0f), LM::Point(300.0f)));
			UpdateComboBox();
			Recalculate();
		}

		System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (comboBox2->SelectedIndex != -1)
			{
				m_Lines->erase(m_Lines->begin() + comboBox2->SelectedIndex);
			}
			UpdateComboBox();
			Recalculate();
		}

		System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) 
		{
			System::String ^text = textBox1->Text;
			std::string str;
			for (int i = 0; i < text->Length; i++)
				str.push_back(text[i]);

			float v = 0.0f;
			try
			{
				v = std::stof(str);
			}
			catch (...)
			{

			}

			switch (comboBox1->SelectedIndex)
			{
			case 0:
				if (comboBox2->SelectedIndex != -1)
				{
					(*m_Points)[comboBox2->SelectedIndex].x = v;
				}
				break;
			case 1:
				if (comboBox2->SelectedIndex != -1)
				{
					if (comboBox3->SelectedIndex != -1)
					{
						(*m_Lines)[comboBox2->SelectedIndex][comboBox3->SelectedIndex].x = v;
					}
				}
				break;
			}

			Recalculate();
		}
		
		System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) 
		{
			System::String ^text = textBox2->Text;
			std::string str;
			for (int i = 0; i < text->Length; i++)
				str.push_back(text[i]);

			float v = 0.0f;
			try
			{
				v = std::stof(str);
			}
			catch (...)
			{

			}

			switch (comboBox1->SelectedIndex)
			{
			case 0:
				if (comboBox2->SelectedIndex != -1)
				{
					(*m_Points)[comboBox2->SelectedIndex].y = v;
				}
				break;
			case 1:
				if (comboBox2->SelectedIndex != -1)
				{
					if (comboBox3->SelectedIndex != -1)
					{
						(*m_Lines)[comboBox2->SelectedIndex][comboBox3->SelectedIndex].y = v;
					}
				}
				break;
			}

			Recalculate();
		}

	protected:
		std::vector<LM::Point> *m_Points;
		std::vector<LM::Line>* m_Lines;
};
}

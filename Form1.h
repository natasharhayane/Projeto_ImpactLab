#pragma once
#include <string>
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <iomanip> // Para std::setprecision
#include "filtros/filtersCpu.cpp"
#include "filtros/filtersCpuMultithread.cpp"#pragma once

using namespace std::chrono;

namespace CppCLRWinFormsProject {

	
    extern "C" {
        //Load Images
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "include/stb/stb_image.h"
#include "include/stb/stb_image_write.h"
    }

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace std;

    /// <summary>
    /// Sum�rio para MainForm
    /// </summary>
    public ref class MainForm : public System::Windows::Forms::Form
    {
    public:
        MainForm(void)
        {
            InitializeComponent();
            //
            //TODO: Adicione o c�digo do construtor aqui
            //
        }

    protected:
        /// <summary>
        /// Limpar os recursos que est�o sendo usados.
        /// </summary>
        ~MainForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Button^ buttonOpen;
    private: System::Windows::Forms::Button^ buttonClean;
    private: System::Windows::Forms::ComboBox^ selectFilter;
    private: System::Windows::Forms::RadioButton^ radioButtonCpu;
    private: System::Windows::Forms::RadioButton^ radioButtonGpu;
    private: System::Windows::Forms::GroupBox^ groupBox1;
    private: System::Windows::Forms::GroupBox^ groupBox2;
    private: System::Windows::Forms::PictureBox^ pictureBoxInput;
    private: System::Windows::Forms::PictureBox^ pictureBoxResult;
    private: System::Windows::Forms::Button^ buttonApply;
    private: System::Windows::Forms::GroupBox^ groupBox3;
    private: System::Windows::Forms::RadioButton^ radioButtonCpuParallel;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ statusLabel;
    private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
    private: System::Windows::Forms::Label^ labelExecutionTime;
    private: System::Windows::Forms::GroupBox^ groupBox4;
    private: System::Windows::Forms::Label^ label3;




    private: System::ComponentModel::IContainer^ components;

    protected:

    private:
        /// <summary>
        /// Vari�vel de designer necess�ria.
        /// </summary>


#pragma region Windows Form Designer generated code
/// <summary>
/// M�todo necess�rio para suporte ao Designer - n�o modifique 
/// o conte�do deste m�todo com o editor de c�digo.
/// </summary>
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->buttonOpen = (gcnew System::Windows::Forms::Button());
            this->buttonClean = (gcnew System::Windows::Forms::Button());
            this->selectFilter = (gcnew System::Windows::Forms::ComboBox());
            this->radioButtonCpu = (gcnew System::Windows::Forms::RadioButton());
            this->radioButtonGpu = (gcnew System::Windows::Forms::RadioButton());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->radioButtonCpuParallel = (gcnew System::Windows::Forms::RadioButton());
            this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
            this->pictureBoxInput = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBoxResult = (gcnew System::Windows::Forms::PictureBox());
            this->buttonApply = (gcnew System::Windows::Forms::Button());
            this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->statusLabel = (gcnew System::Windows::Forms::Label());
            this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
            this->labelExecutionTime = (gcnew System::Windows::Forms::Label());
            this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
            this->groupBox1->SuspendLayout();
            this->groupBox2->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxInput))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxResult))->BeginInit();
            this->groupBox3->SuspendLayout();
            this->groupBox4->SuspendLayout();
            this->SuspendLayout();
            // 
            // buttonOpen
            // 
            this->buttonOpen->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
            this->buttonOpen->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->buttonOpen->ForeColor = System::Drawing::Color::Black;
            this->buttonOpen->Location = System::Drawing::Point(6, 37);
            this->buttonOpen->Name = L"buttonOpen";
            this->buttonOpen->Size = System::Drawing::Size(122, 40);
            this->buttonOpen->TabIndex = 0;
            this->buttonOpen->Text = L"Abrir arquivos";
            this->buttonOpen->UseVisualStyleBackColor = true;
            this->buttonOpen->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
            // 
            // buttonClean
            // 
            this->buttonClean->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
            this->buttonClean->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
            this->buttonClean->ForeColor = System::Drawing::Color::Black;
            this->buttonClean->Location = System::Drawing::Point(134, 37);
            this->buttonClean->Name = L"buttonClean";
            this->buttonClean->Size = System::Drawing::Size(122, 40);
            this->buttonClean->TabIndex = 1;
            this->buttonClean->Text = L"limpar";
            this->buttonClean->UseVisualStyleBackColor = true;
            this->buttonClean->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
            // 
            // selectFilter
            // 
            this->selectFilter->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
            this->selectFilter->FormattingEnabled = true;
            this->selectFilter->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
                L"Filtro Azul", L"Filtro Cinza", L"Sombra",
                    L"Sal e Pimenta"
            });
            this->selectFilter->Location = System::Drawing::Point(6, 30);
            this->selectFilter->Name = L"selectFilter";
            this->selectFilter->Size = System::Drawing::Size(248, 27);
            this->selectFilter->TabIndex = 2;
            this->selectFilter->Text = L"Selecionar";
            this->selectFilter->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBox1_SelectedIndexChanged);
            // 
            // radioButtonCpu
            // 
            this->radioButtonCpu->AutoSize = true;
            this->radioButtonCpu->Checked = true;
            this->radioButtonCpu->Location = System::Drawing::Point(6, 32);
            this->radioButtonCpu->Name = L"radioButtonCpu";
            this->radioButtonCpu->Size = System::Drawing::Size(57, 23);
            this->radioButtonCpu->TabIndex = 1;
            this->radioButtonCpu->TabStop = true;
            this->radioButtonCpu->Text = L"CPU";
            this->radioButtonCpu->UseVisualStyleBackColor = true;
            this->radioButtonCpu->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton1_CheckedChanged);
            // 
            // radioButtonGpu
            // 
            this->radioButtonGpu->AutoSize = true;
            this->radioButtonGpu->Location = System::Drawing::Point(6, 61);
            this->radioButtonGpu->Name = L"radioButtonGpu";
            this->radioButtonGpu->Size = System::Drawing::Size(57, 23);
            this->radioButtonGpu->TabIndex = 2;
            this->radioButtonGpu->Text = L"GPU";
            this->radioButtonGpu->UseVisualStyleBackColor = true;
            this->radioButtonGpu->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton2_CheckedChanged);
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->radioButtonCpuParallel);
            this->groupBox1->Controls->Add(this->radioButtonGpu);
            this->groupBox1->Controls->Add(this->radioButtonCpu);
            this->groupBox1->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
            this->groupBox1->ForeColor = System::Drawing::Color::GhostWhite;
            this->groupBox1->Location = System::Drawing::Point(12, 256);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(260, 124);
            this->groupBox1->TabIndex = 3;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Modo de Processamento";
            // 
            // radioButtonCpuParallel
            // 
            this->radioButtonCpuParallel->AutoSize = true;
            this->radioButtonCpuParallel->Location = System::Drawing::Point(6, 89);
            this->radioButtonCpuParallel->Name = L"radioButtonCpuParallel";
            this->radioButtonCpuParallel->Size = System::Drawing::Size(144, 23);
            this->radioButtonCpuParallel->TabIndex = 9;
            this->radioButtonCpuParallel->TabStop = true;
            this->radioButtonCpuParallel->Text = L"CPU Multithread";
            this->radioButtonCpuParallel->UseVisualStyleBackColor = true;
            this->radioButtonCpuParallel->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radioButton1_CheckedChanged_1);
            // 
            // groupBox2
            // 
            this->groupBox2->Controls->Add(this->selectFilter);
            this->groupBox2->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
            this->groupBox2->ForeColor = System::Drawing::Color::Azure;
            this->groupBox2->Location = System::Drawing::Point(12, 177);
            this->groupBox2->Name = L"groupBox2";
            this->groupBox2->Size = System::Drawing::Size(260, 69);
            this->groupBox2->TabIndex = 4;
            this->groupBox2->TabStop = false;
            this->groupBox2->Text = L"Filtros Disponiveis";
            this->groupBox2->Enter += gcnew System::EventHandler(this, &MainForm::groupBox2_Enter);
            // 
            // pictureBoxInput
            // 
            this->pictureBoxInput->BackColor = System::Drawing::SystemColors::ControlLight;
            this->pictureBoxInput->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->pictureBoxInput->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
            this->pictureBoxInput->Location = System::Drawing::Point(354, 98);
            this->pictureBoxInput->Name = L"pictureBoxInput";
            this->pictureBoxInput->Size = System::Drawing::Size(194, 213);
            this->pictureBoxInput->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBoxInput->TabIndex = 5;
            this->pictureBoxInput->TabStop = false;
            this->pictureBoxInput->Click += gcnew System::EventHandler(this, &MainForm::pictureBoxInput_Click);
            // 
            // pictureBoxResult
            // 
            this->pictureBoxResult->BackColor = System::Drawing::SystemColors::ControlLight;
            this->pictureBoxResult->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->pictureBoxResult->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
            this->pictureBoxResult->Location = System::Drawing::Point(602, 98);
            this->pictureBoxResult->Name = L"pictureBoxResult";
            this->pictureBoxResult->Size = System::Drawing::Size(194, 213);
            this->pictureBoxResult->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBoxResult->TabIndex = 6;
            this->pictureBoxResult->TabStop = false;
            // 
            // buttonApply
            // 
            this->buttonApply->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
            this->buttonApply->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
            this->buttonApply->ForeColor = System::Drawing::Color::Black;
            this->buttonApply->Location = System::Drawing::Point(382, 323);
            this->buttonApply->Name = L"buttonApply";
            this->buttonApply->Size = System::Drawing::Size(132, 46);
            this->buttonApply->TabIndex = 7;
            this->buttonApply->Text = L"Aplicar filtro";
            this->buttonApply->UseVisualStyleBackColor = true;
            this->buttonApply->Click += gcnew System::EventHandler(this, &MainForm::buttonApplyFilter);
            // 
            // groupBox3
            // 
            this->groupBox3->Controls->Add(this->label3);
            this->groupBox3->Controls->Add(this->buttonClean);
            this->groupBox3->Controls->Add(this->buttonOpen);
            this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->groupBox3->Location = System::Drawing::Point(12, 79);
            this->groupBox3->Name = L"groupBox3";
            this->groupBox3->Size = System::Drawing::Size(260, 92);
            this->groupBox3->TabIndex = 8;
            this->groupBox3->TabStop = false;
            this->groupBox3->Enter += gcnew System::EventHandler(this, &MainForm::groupBox3_Enter);
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
            this->label3->Location = System::Drawing::Point(52, 15);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(152, 19);
            this->label3->TabIndex = 16;
            this->label3->Text = L"Imagem de Entrada";
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
            this->label1->Location = System::Drawing::Point(670, 76);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(82, 19);
            this->label1->TabIndex = 9;
            this->label1->Text = L"Resultado";
            this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
            this->label2->Location = System::Drawing::Point(367, 76);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(160, 19);
            this->label2->TabIndex = 10;
            this->label2->Text = L"Imagem selecionada";
            this->label2->Click += gcnew System::EventHandler(this, &MainForm::label2_Click);
            // 
            // statusLabel
            // 
            this->statusLabel->AutoSize = true;
            this->statusLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->statusLabel->Location = System::Drawing::Point(12, 21);
            this->statusLabel->Name = L"statusLabel";
            this->statusLabel->Size = System::Drawing::Size(0, 14);
            this->statusLabel->TabIndex = 11;
            // 
            // contextMenuStrip1
            // 
            this->contextMenuStrip1->Name = L"contextMenuStrip1";
            this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
            // 
            // labelExecutionTime
            // 
            this->labelExecutionTime->AutoSize = true;
            this->labelExecutionTime->Font = (gcnew System::Drawing::Font(L"Verdana", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
            this->labelExecutionTime->Location = System::Drawing::Point(11, 46);
            this->labelExecutionTime->Name = L"labelExecutionTime";
            this->labelExecutionTime->Size = System::Drawing::Size(0, 14);
            this->labelExecutionTime->TabIndex = 14;
            this->labelExecutionTime->Click += gcnew System::EventHandler(this, &MainForm::label3_Click);
            // 
            // groupBox4
            // 
            this->groupBox4->Controls->Add(this->labelExecutionTime);
            this->groupBox4->Controls->Add(this->statusLabel);
            this->groupBox4->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 12));
            this->groupBox4->ForeColor = System::Drawing::Color::LavenderBlush;
            this->groupBox4->Location = System::Drawing::Point(563, 323);
            this->groupBox4->Name = L"groupBox4";
            this->groupBox4->Size = System::Drawing::Size(233, 94);
            this->groupBox4->TabIndex = 15;
            this->groupBox4->TabStop = false;
            this->groupBox4->Text = L"Desempenho";
            this->groupBox4->Enter += gcnew System::EventHandler(this, &MainForm::groupBox4_Enter);
            // 
            // MainForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(74)));
            this->ClientSize = System::Drawing::Size(808, 436);
            this->Controls->Add(this->groupBox4);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->groupBox3);
            this->Controls->Add(this->buttonApply);
            this->Controls->Add(this->pictureBoxResult);
            this->Controls->Add(this->pictureBoxInput);
            this->Controls->Add(this->groupBox2);
            this->Controls->Add(this->groupBox1);
            this->ForeColor = System::Drawing::Color::LavenderBlush;
            this->Name = L"MainForm";
            this->Text = L"App filtros";
            this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            this->groupBox2->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxInput))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxResult))->EndInit();
            this->groupBox3->ResumeLayout(false);
            this->groupBox3->PerformLayout();
            this->groupBox4->ResumeLayout(false);
            this->groupBox4->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

#pragma endregion
        // carrega a imagem no PictureBox 
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        OpenFileDialog^ ofd = gcnew OpenFileDialog();

        if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            pictureBoxInput->Image = System::Drawing::Image::FromFile(ofd->FileName);
        }
    }
    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        if (pictureBoxInput->Image != nullptr) {
            delete pictureBoxInput->Image;
            pictureBoxInput->Image = nullptr;
        }

        if (pictureBoxResult->Image != nullptr) {
            delete pictureBoxResult->Image;
            pictureBoxResult->Image = nullptr;
        }
    }
    private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void radioButton1_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
    }

           // Aplica o filtro na imagem do picture box
    private: System::Void buttonApplyFilter(System::Object^ sender, System::EventArgs^ e) {
        if (pictureBoxInput->Image != nullptr) {

            int mode = checkWhichExecutionModeWasSelected();
            int time = 0;

            if (selectFilter->SelectedIndex == 0) {
                // Blue
                statusLabel->Text = getOptionName(mode);
                auto start = high_resolution_clock::now();
                filterBlue(mode);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(end - start);
                time = duration.count();
            }

            if (selectFilter->SelectedIndex == 1) {
                // Gray
                statusLabel->Text = getOptionName(mode);
                auto start = high_resolution_clock::now();
                filterGrayScale(mode);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(end - start);
                time = duration.count();
            }

            if (selectFilter->SelectedIndex == 2) {
                // Darkness
                statusLabel->Text = getOptionName(mode);
                auto start = high_resolution_clock::now();
                filterDarkness(mode);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(end - start);
                time = duration.count();
            }

            if (selectFilter->SelectedIndex == 3) {
                // Salt and Pepper
                statusLabel->Text = getOptionName(mode);
                auto start = high_resolution_clock::now();
                filterSaltAndPepper(mode);
                auto end = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(end - start);
                time = duration.count();
            }

            double timeConverted = time / 1000000.0;

            labelExecutionTime->Text = "Dura��o: " + System::String::Format("{0:F6}", timeConverted) + " segundos";
        }
        else {
            MessageBox::Show("No image loaded in the input image box", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    private: System::Void splitContainer1_Panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void groupBox3_Enter(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void pictureBoxInput_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
    }

           /******************************************** Filters *******************************************/

    private: System::Void filterBlue(int executionMode) {
        // Salve a imagem carregada em um arquivo tempor�rio
        String^ tempFilePath = "temp_image.jpg";
        pictureBoxInput->Image->Save(tempFilePath, System::Drawing::Imaging::ImageFormat::Jpeg);

        // Verifica se existe alguma imagem no quadro de sa�da e deleta
        if (pictureBoxResult->Image != nullptr) {
            delete pictureBoxResult->Image;
        }

        // Carregue a imagem com stbi
        int width, height, channels;
        unsigned char* img = stbi_load("temp_image.jpg", &width, &height, &channels, 0);

        if (img != nullptr) {

            // CPU Normal
            if (executionMode == 1) {
                filterBlueSimple(img, width, height, channels);
            }

            // Parallel CPU
            if (executionMode == 2) {
                unsigned int numberOfElements = width * height * channels;

                // filterNumber, nbElements, width, height, channels, *img, use_threads
                filterMultithread(1, width, height, channels, img);
            }

            // Salve a imagem modificada
            stbi_write_jpg("output_filter_blue.jpg", width, height, channels, img, 100);

            // Libere a mem�ria da imagem original
            stbi_image_free(img);

            // Carregue a imagem modificada na quadro de sa�da
            pictureBoxResult->Image = Image::FromFile("output_filter_blue.jpg");

            // Delete the temporary file
            System::IO::File::Delete(tempFilePath);
        }
        else {
            MessageBox::Show("Failed to load image with stbi", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: System::Void filterGrayScale(int executionMode) {
        // Salve a imagem carregada em um arquivo tempor�rio
        String^ tempFilePath = "temp_image.jpg";
        pictureBoxInput->Image->Save(tempFilePath, System::Drawing::Imaging::ImageFormat::Jpeg);

        // Verifica se existe alguma imagem no quadro de sa�da e deleta
        if (pictureBoxResult->Image != nullptr) {
            delete pictureBoxResult->Image;
        }

        // Carregue a imagem com stbi
        int width, height, channels;
        unsigned char* img = stbi_load("temp_image.jpg", &width, &height, &channels, 0);

        if (img != nullptr) {

            // CPU Normal
            if (executionMode == 1) {
                // grayscale
                filterGrayScaleSimple(img, width, height, channels);
            }

            // Parallel CPU
            if (executionMode == 2) {
                unsigned int numberOfElements = width * height * channels;

                // filterNumber, nbElements, width, height, channels, *img, use_threads
                filterMultithread(2, width, height, channels, img);
            }

            // Salve a imagem modificada
            stbi_write_jpg("output_gray_scale.jpg", width, height, channels, img, 100);

            // Libere a mem�ria da imagem original
            stbi_image_free(img);

            // Carregue a imagem modificada na Output_Image_Box
            pictureBoxResult->Image = Image::FromFile("output_gray_scale.jpg");

            // Delete the temporary file
            System::IO::File::Delete(tempFilePath);
        }
        else {
            MessageBox::Show("Failed to load image with stbi", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: System::Void filterDarkness(int executionMode) {
        // Salve a imagem carregada em um arquivo tempor�rio
        String^ tempFilePath = "temp_image.jpg";
        pictureBoxInput->Image->Save(tempFilePath, System::Drawing::Imaging::ImageFormat::Jpeg);

        // Verifica se existe alguma imagem no quadro de sa�da e deleta
        if (pictureBoxResult->Image != nullptr) {
            delete pictureBoxResult->Image;
        }

        // Carregue a imagem com stbi
        int width, height, channels;
        unsigned char* img = stbi_load("temp_image.jpg", &width, &height, &channels, 0);

        if (img != nullptr) {
            // CPU Normal
            if (executionMode == 1) {
                // simple darkness
                filterDarknessSimple(img, width, height, channels);
            }

            // Parallel CPU
            if (executionMode == 2) {
                unsigned int numberOfElements = width * height * channels;

                // filterNumber, nbElements, width, height, channels, *img, use_threads
                filterMultithread(3, width, height, channels, img);
            }

            // Salve a imagem modificada
            stbi_write_jpg("simple_darkness.jpg", width, height, channels, img, 100);

            // Libere a mem�ria da imagem original
            stbi_image_free(img);

            // Carregue a imagem modificada na Output_Image_Box
            pictureBoxResult->Image = Image::FromFile("simple_darkness.jpg");

            // Delete the temporary file
            System::IO::File::Delete(tempFilePath);
        }
        else {
            MessageBox::Show("Failed to load image with stbi", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: System::Void filterSaltAndPepper(int executionMode) {
        // Salve a imagem carregada em um arquivo tempor�rio
        String^ tempFilePath = "temp_image.jpg";
        pictureBoxInput->Image->Save(tempFilePath, System::Drawing::Imaging::ImageFormat::Jpeg);

        // Verifica se existe alguma imagem no quadro de sa�da e deleta
        if (pictureBoxResult->Image != nullptr) {
            delete pictureBoxResult->Image;
        }

        // Carregue a imagem com stbi
        int width, height, channels;
        unsigned char* img = stbi_load("temp_image.jpg", &width, &height, &channels, 0);

        if (img != nullptr) {
            filterSaltAndPepperSimple(img, width, height, channels);

            // Salve a imagem modificada
            stbi_write_jpg("salt_and_pepper.jpg", width, height, channels, img, 100);

            // Libere a mem�ria da imagem original
            stbi_image_free(img);

            // Carregue a imagem modificada na Output_Image_Box
            pictureBoxResult->Image = Image::FromFile("salt_and_pepper.jpg");

            // Delete the temporary file
            System::IO::File::Delete(tempFilePath);
        }
        else {
            MessageBox::Show("Failed to load image with stbi", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

           /* Utils */
    private: int checkWhichExecutionModeWasSelected() {
        if (radioButtonCpu->Checked) {
            return 1; // CPU
        }
        else if (radioButtonCpuParallel->Checked) {
            return 2; // CPU Parallel
        }
        else {
            return 3; // GPU
        }
    }

    private: String^ getOptionName(int optionIndex) {
        switch (optionIndex) {
        case 1:
            return "CPU";
            break;
        case 2:
            return "CPU Multithread";
            break;
        case 3:
            return "GPU";
        default:
            return "";
        }
    }

    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void groupBox4_Enter(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
    }
};



}
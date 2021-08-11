#include "notepad.h"
#include "ui_notepad.h"
#include<QFile>
#include<QFileDialog>
#include<QTextStream>
#include<QMessageBox>
Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

Notepad::~Notepad()
{
    delete ui;
}


void Notepad::on_actionNew_triggered()
{
    file_path="";
    ui->textEdit->setText("");
}


void Notepad::on_actionOpen_triggered()
{
    QString file_name=QFileDialog::getOpenFileName(this,"Open this File");
    QFile file(file_name);
    file_path=file_name;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"..","file not open");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void Notepad::on_actionSave_triggered()
{

    QFile file(file_path);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","file not open");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}


void Notepad::on_actionSave_As_triggered()
{
    QString file_name=QFileDialog::getSaveFileName(this,"Open this File");
    QFile file(file_name);
    file_path=file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","file not open");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}


void Notepad::on_actionExit_triggered()
{
    QApplication::quit();
}


void Notepad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void Notepad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void Notepad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void Notepad::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void Notepad::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void Notepad::on_actionDelete_triggered()
{
    ui->textEdit->deleteLater();
}


void Notepad::on_actionAbout_triggered()
{
    QString about_text;
    about_text="This is Simple a text Editor, very much like Notepad. It is created using QT framework with C++.";
    QMessageBox::about(this,"About",about_text);
}


void Notepad::on_actionAuthor_triggered()
{
    QString about_text1;
    about_text1="Author : Vivek \n";
    QMessageBox::about(this,"Author ",about_text1);
}


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>

#include <QMainWindow>


#include <QMenuBar>
#include <QMenu>

#include <QTextEdit>

#include <QStatusBar>
#include <QLabel>


#include <QFileDialog>

#include <QMessageBox>


#include <QFile>

#include <QTextStream>

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow();
public slots:
    void open()
    {
        fileName = QFileDialog::getOpenFileName(this, "Open file", "");
        if (fileName.isEmpty())
        {
            QMessageBox::warning(this, "Error", "There is no file to open.");
        }
        else
        {
            file = new QFile(fileName);
            if (file->open(QIODevice::ReadOnly | QIODevice::Text))
            {
                output = new QTextStream(file);

                textBox->setPlainText(output->readAll());
                currentFileName->setText(fileName);

                delete output;
                file->close();

                QMessageBox::information(this, "Success", "The file has been successfully opened.");
            }
            else
            {
                QMessageBox::warning(this, "Error", "Could not open the file for reading.");
            }
            delete file;
        }
    }
    void save()
    {
        if (fileName.isEmpty())
        {
            QMessageBox::warning(this, "Error", "There is no file to save.");
        }
        else
        {
            file = new QFile(fileName);
            if (file->open(QIODevice::WriteOnly | QIODevice::Text))
            {
                input = new QTextStream(file);

                *input << textBox->toPlainText();

                delete input;
                file->close();

                QMessageBox::information(this, "Success", "The file has been successfully saved.");
            }
            else
            {
                QMessageBox::warning(this, "Error", "Could not open the file for saving.");
            }
            delete file;
        }
    }
    void saveAs()
    {
        fileName = QFileDialog::getSaveFileName(this, "Save file as", "");
        if (fileName.isEmpty())
        {
            QMessageBox::warning(this, "Error", "There is no path to save the file at.");
        }
        else
        {
            file = new QFile(fileName);
            if (file->open(QIODevice::WriteOnly | QIODevice::Text))
            {
                input = new QTextStream(file);

                *input << textBox->toPlainText();
                currentFileName->setText(fileName);

                delete input;                
                file->close();

                QMessageBox::information(this, "Success", "The file has been successfully saved.");
            }
            else
            {
                QMessageBox::warning(this, "Error", "Could not open the file for saving.");
            }
            delete file;
        }
    }
    void exit()
    {
        QApplication::instance()->quit();
    }
private:
    QMenuBar* menuBar;

    QMenu*    fileMenu;

    QAction*  openAction;
    QAction*  saveAction;
    QAction*  saveAsAction;
    QAction*  exitAction;

    QMenu*    viewMenu;

    QAction*  setStyleAction;

    QMenu*    setStyleSubMenu;


    QAction*  windowsAction;
    QAction*  macAction;
    QAction*  fusionAction;
    QAction*  plastiqueAction;
    QAction*  cdeAction;
    QAction*  cleanLooksAction;
    QAction*  gtkAction;


    QTextEdit* textBox;


    QStatusBar* statusBar;

    QLabel* currentFileName;


    QFile* file;

    QString fileName;

    QTextStream* output;
    QTextStream* input;

};

#endif

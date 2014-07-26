#include "dialog.h"
#include "ui_dialog.h"
#include "dialog.h"
#include "ui_dialog.h"
#include "Huffman.h"
#include "Huffman.c"
#include <QAbstractItemView>
#include <QFileDialog>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QGraphicsPixmapItem>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
     LineEditDir=ui->lineEdit;
  //   LineEditDir = ui->lineEdit_2;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_pressed()
{

    QString file_full, file_name, file_path;
    QFileInfo fi;

    QString root="/";
    QDir rootDir(root);


    file_full = QFileDialog::getOpenFileName(this, tr("open file"), "/home",  tr("Allfile(*.*);;mp3file(*.mp3)"));

    fi = QFileInfo(file_full);
    file_name = fi.fileName();
    file_path = fi.absolutePath();

   //->selectedText("nihao");

    //LineEditDir->setText("niao");
    QByteArray byteArray = file_path.toLocal8Bit();
    QByteArray byteArra  = file_name.toLocal8Bit();

    char * pc = byteArray.data();

    strcat(pc, "/");
    strcat(pc, byteArra);
    LineEditDir->setText(file_full);

   // LineEditDir->setText(fi);
   // printf("\n%s\n", pc);
}

void Dialog::on_pushButton_2_clicked()
{
    QString file_full, file_name, file_path;
    QFileInfo fi;

    QString root="/";
    QDir rootDir(root);


    file_full = QFileDialog::getOpenFileName(this, tr("open file"), "/home",  tr("Allfile(*.*);;mp3file(*.mp3)"));

    fi = QFileInfo(file_full);
    file_name = fi.fileName();
    file_path = fi.absolutePath();

   //->selectedText("nihao");

    //LineEditDir->setText("niao");
    QByteArray byteArray = file_path.toLocal8Bit();
    QByteArray byteArra  = file_name.toLocal8Bit();

    char * pc = byteArray.data();

    strcat(pc, "/");
    strcat(pc, byteArra);
    ui->lineEdit_2->setText(file_full);

   // LineEditDir->setText(fi);
    //printf("\n%s\n", pc);
}
void Dialog::on_lineEdit_textChanged(const QString &arg1)
{
    ;
}
void Dialog::on_lineEdit_2_textChanged(const QString &arg1)
{
    ;
}

void Dialog::on_pushButton_3_pressed()
{
    char tmp[100];

    QString filename = LineEditDir->text();
    QByteArray byteArray  = filename.toLocal8Bit();
    char * pc = byteArray.data();
    int count = 0;


    strcpy(tmp, pc);
    tmp[strlen(tmp)] = '\0';
    Compress(tmp);
}

void Dialog::on_pushButton_4_pressed()
{
    char tmp[100];
    char newname[100];
    char local_name[100];
    int i = 0;
    int j = 0;
    int where = 0;

    QString filename = ui->lineEdit_2->text();
    QByteArray byteArray  = filename.toLocal8Bit();
    char * pc = byteArray.data();

    QString str = ui->lineEdit_3->text();
    QByteArray byteArray_ = str.toLocal8Bit();
    char *name = byteArray_.data();
    strcpy(tmp, pc);
    tmp[strlen(tmp)] = '\0';

    while (i < strlen(tmp))
    {
        if (tmp[i] == '/')
        {
            where = i;
        }
        i++;
    }
    strncpy(local_name, tmp, where);

    printf("tmp = %s\nwhere = %d loc %s\n",tmp,  where);
    strcat(local_name, "/");
    strcat(local_name, name);
    tmp[strlen(tmp)] = '\0';
    newname[strlen(newname)] = '\0';
    local_name[strlen(local_name)] = '\0';
    printf("xianzai %s   tmp = \n", local_name, tmp);
    UnCompress(tmp, local_name);
}

void Dialog::on_pushButton_2_pressed()
{
    ;
}

void Dialog::on_lineEdit_3_textChanged(const QString &arg1)
{
    ;
}

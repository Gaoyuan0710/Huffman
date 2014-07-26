#ifndef DIALOG_H
#define DIALOG_H




#include <QDialog>
#include <QLineEdit>
#include <QListWidget>
#include <QFileInfoList>
#include <QDir>

#if QT_VERSION >= 0x050000
#include <QDialog>
#else
#include <QDialog>
#endif

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_pressed();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_2_pressed();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_4_pressed();

    void on_pushButton_2_clicked();

    void on_pushButton_3_pressed();

    void on_lineEdit_3_textChanged(const QString &arg1);

private:
    Ui::Dialog *ui;
    QLineEdit *LineEditDir;
    QListWidget *ListWidgetFile;
    QListWidgetItem item;
    int itemnum;
    int m;
    void showFileInfoList(QFileInfoList list);
    void slotShow(QDir dir);
};

#endif // DIALOG_H

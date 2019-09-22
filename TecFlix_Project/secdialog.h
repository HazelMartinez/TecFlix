#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>

namespace Ui {
class secDialog;
}

class secDialog : public QDialog
{
    Q_OBJECT

public:
    explicit secDialog(QWidget *parent = 0);
    void setText  (const QString &text);
    void setTextL2(const QString &text);
    void setTextL3(const QString &text);
    void lineEdit (const QString &text);
    void textString(const QString &same_text);
    ~secDialog();

private:
    Ui::secDialog *ui;
};

#endif // SECDIALOG_H

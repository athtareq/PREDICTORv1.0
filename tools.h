#ifndef TOOLS_H
#define TOOLS_H

#include <QDialog>

namespace Ui {
class tools;
}

class tools : public QDialog
{
    Q_OBJECT

public:
    explicit tools(QWidget *parent = nullptr);
    ~tools();

private slots:
    void on_calcpoisson_clicked();

    void on_league_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked(bool checked);

private:
    Ui::tools *ui;
};

#endif // TOOLS_H

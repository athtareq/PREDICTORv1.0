#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QtSql>
#include<QtDebug>
#include<QFileInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include<vector>
#include<iostream>
#include<math.h>
#include<dialog.h>
#include<dialog.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class dialog;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

protected:
    void resizeEvent(QResizeEvent* evt) override;
private slots:
    void on_hometeam_currentIndexChanged(const QString &arg1);
    void on_predict_clicked();
    void on_awayteam_currentIndexChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);
    void on_pushButton_clicked();
    void on_tools_clicked();
};


#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Airline.h"
#include "AirlineService.h"
#include "AbstractAircraft.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // 刷新下拉列表
    void refreshList();
    // 刷新顶部参数标签（自动计算总载客量，符合作业要求）
    void refreshInfoLabel();
    // 刷新下方大文本框机队详情
    void refreshFleetDisplay();

    void on_btnAdd_clicked();
    void on_btnEdit_clicked();
    void on_btnDelete_clicked();

private:
    Ui::MainWindow *ui;
    Airline m_airline;
    AirlineService m_service;

    // 新增：计算机队总载客量（作业强制要求自动更新参数）
    int calculateTotalPassenger();
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "rule.h"

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
    void on_powerOn_clicked();

    void on_pushButton_clicked();

    void on_cpuSlider_valueChanged(int value);

    void on_gpuSlider_valueChanged(int value);

    void on_diskSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QVector<Rule> rules_;

    QVector<Rule> genRules();
    QVector<qreal> fuzzi(QVector<Rule> rules, qint16 cpu, qint16 disk, qint16 gpu, bool power, qint16 temp);
};
#endif // MAINWINDOW_H

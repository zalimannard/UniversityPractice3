#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->powerOn->setChecked(true);
    ui->cpuText->setText(QString::number(ui->cpuSlider->value()));
    ui->gpuText->setText(QString::number(ui->gpuSlider->value()));
    ui->diskText->setText(QString::number(ui->diskSlider->value()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QVector<QVector<qreal> > MainWindow::fuzzi(QVector<Rule> rules, qint16 cpu, qint16 disk, qint16 gpu, bool power, qint16 temperature)
{
    QVector<QVector<qreal> > pastFuzzi;
    for (Rule rule : rules)
    {
        QVector<qreal> partFuzzi;
        partFuzzi.append(rule.fuzziCompareCpu(cpu));
        partFuzzi.append(rule.fuzziCompareDisk(disk));
        partFuzzi.append(rule.fuzziCompareGpu(gpu));
        partFuzzi.append(rule.fuzziComparePower((bool)power));
        partFuzzi.append(rule.fuzziCompareTemperature(temperature));
        pastFuzzi.append(partFuzzi);
    }
    return pastFuzzi;
}

QVector<qreal> MainWindow::agregate(QVector<QVector<qreal> > dataPastFuzzi)
{
    QVector<qreal> answer;
    for (QVector<qreal> partDataPastFuzzi : dataPastFuzzi)
    {
        qreal min = 999999999;
        for (qreal n : partDataPastFuzzi)
        {
            min = qMin(min, n);
        }
        answer.append(min);
    }
    return answer;
}

qreal MainWindow::defuzzi(QVector<qreal> data, QVector<Rule> rules)
{
    qreal sumNumerator = 0;
    qreal sumDenominator = 0;
    for (auto i = 0; i < data.size(); ++i)
    {
        sumNumerator += data.at(i) * rules[i].getFan();
        sumDenominator += data.at(i);
    }
    return sumNumerator / sumDenominator;
}

QVector<Rule> MainWindow::genRules()
{
    QVector<Rule> rules;

    //                cpu    disk   gpu    power      temperature
    rules.append(Rule("low", "low", "low", "enable", "low", 0));
    rules.append(Rule("low", "low", "low", "disable", "middle", 0));
    rules.append(Rule("low", "low", "low", "disable", "high", 0));
    rules.append(Rule("low", "low", "low", "enable", "low", 0));
    rules.append(Rule("low", "low", "low", "enable", "middle", 0));
    rules.append(Rule("low", "low", "low", "enable", "high", 0));
    rules.append(Rule("low", "low", "middle", "disable", "low", 20));
    rules.append(Rule("low", "low", "middle", "disable", "middle", 20));
    rules.append(Rule("low", "low", "middle", "disable", "high", 20));
    rules.append(Rule("low", "low", "middle", "enable", "low", 20));
    rules.append(Rule("low", "low", "middle", "enable", "middle", 20));
    rules.append(Rule("low", "low", "middle", "enable", "high", 20));
    rules.append(Rule("low", "low", "high", "disable", "low", 40));
    rules.append(Rule("low", "low", "high", "disable", "middle", 40));
    rules.append(Rule("low", "low", "high", "disable", "high", 40));
    rules.append(Rule("low", "low", "high", "enable", "low", 40));
    rules.append(Rule("low", "low", "high", "enable", "middle", 40));
    rules.append(Rule("low", "low", "high", "enable", "high", 40));

    rules.append(Rule("low", "high", "low", "disable", "low", 20));
    rules.append(Rule("low", "high", "low", "disable", "middle", 20));
    rules.append(Rule("low", "high", "low", "disable", "high", 20));
    rules.append(Rule("low", "high", "low", "enable", "low", 20));
    rules.append(Rule("low", "high", "low", "enable", "middle", 20));
    rules.append(Rule("low", "high", "low", "enable", "high", 20));
    rules.append(Rule("low", "high", "middle", "disable", "low", 40));
    rules.append(Rule("low", "high", "middle", "disable", "middle", 40));
    rules.append(Rule("low", "high", "middle", "disable", "high", 40));
    rules.append(Rule("low", "high", "middle", "enable", "low", 40));
    rules.append(Rule("low", "high", "middle", "enable", "middle", 40));
    rules.append(Rule("low", "high", "middle", "enable", "high", 40));
    rules.append(Rule("low", "high", "high", "disable", "low", 60));
    rules.append(Rule("low", "high", "high", "disable", "middle", 60));
    rules.append(Rule("low", "high", "high", "disable", "high", 60));
    rules.append(Rule("low", "high", "high", "enable", "low", 60));
    rules.append(Rule("low", "high", "high", "enable", "middle", 60));
    rules.append(Rule("low", "high", "high", "enable", "high", 60));



    rules.append(Rule("middle", "low", "low", "disable", "low", 20));
    rules.append(Rule("middle", "low", "low", "disable", "middle", 20));
    rules.append(Rule("middle", "low", "low", "disable", "high", 20));
    rules.append(Rule("middle", "low", "low", "enable", "low", 20));
    rules.append(Rule("middle", "low", "low", "enable", "middle", 40));
    rules.append(Rule("middle", "low", "low", "enable", "high", 40));
    rules.append(Rule("middle", "low", "middle", "disable", "low", 40));
    rules.append(Rule("middle", "low", "middle", "disable", "middle", 40));
    rules.append(Rule("middle", "low", "middle", "disable", "high", 60));
    rules.append(Rule("middle", "low", "middle", "enable", "low", 60));
    rules.append(Rule("middle", "low", "middle", "enable", "middle", 60));
    rules.append(Rule("middle", "low", "middle", "enable", "high", 60));
    rules.append(Rule("middle", "low", "high", "disable", "low", 60));
    rules.append(Rule("middle", "low", "high", "disable", "middle", 60));
    rules.append(Rule("middle", "low", "high", "disable", "high", 80));
    rules.append(Rule("middle", "low", "high", "enable", "low", 80));
    rules.append(Rule("middle", "low", "high", "enable", "middle", 80));
    rules.append(Rule("middle", "low", "high", "enable", "high", 80));

    rules.append(Rule("middle", "high", "low", "disable", "low", 20));
    rules.append(Rule("middle", "high", "low", "disable", "middle", 20));
    rules.append(Rule("middle", "high", "low", "disable", "high", 20));
    rules.append(Rule("middle", "high", "low", "enable", "low", 20));
    rules.append(Rule("middle", "high", "low", "enable", "middle", 20));
    rules.append(Rule("middle", "high", "low", "enable", "high", 40));
    rules.append(Rule("middle", "high", "middle", "disable", "low", 40));
    rules.append(Rule("middle", "high", "middle", "disable", "middle", 40));
    rules.append(Rule("middle", "high", "middle", "disable", "high", 60));
    rules.append(Rule("middle", "high", "middle", "enable", "low", 60));
    rules.append(Rule("middle", "high", "middle", "enable", "middle", 60));
    rules.append(Rule("middle", "high", "middle", "enable", "high", 80));
    rules.append(Rule("middle", "high", "high", "disable", "low", 60));
    rules.append(Rule("middle", "high", "high", "disable", "middle", 60));
    rules.append(Rule("middle", "high", "high", "disable", "high", 80));
    rules.append(Rule("middle", "high", "high", "enable", "low", 80));
    rules.append(Rule("middle", "high", "high", "enable", "middle", 80));
    rules.append(Rule("middle", "high", "high", "enable", "high", 80));



    rules.append(Rule("high", "low", "low", "disable", "low", 20));
    rules.append(Rule("high", "low", "low", "disable", "middle", 20));
    rules.append(Rule("high", "low", "low", "disable", "high", 20));
    rules.append(Rule("high", "low", "low", "enable", "low", 20));
    rules.append(Rule("high", "low", "low", "enable", "middle", 40));
    rules.append(Rule("high", "low", "low", "enable", "high", 40));
    rules.append(Rule("high", "low", "middle", "disable", "low", 40));
    rules.append(Rule("high", "low", "middle", "disable", "middle", 40));
    rules.append(Rule("high", "low", "middle", "disable", "high", 40));
    rules.append(Rule("high", "low", "middle", "enable", "low", 60));
    rules.append(Rule("high", "low", "middle", "enable", "middle", 60));
    rules.append(Rule("high", "low", "middle", "enable", "high", 60));
    rules.append(Rule("high", "low", "high", "disable", "low", 80));
    rules.append(Rule("high", "low", "high", "disable", "middle", 80));
    rules.append(Rule("high", "low", "high", "disable", "high", 80));
    rules.append(Rule("high", "low", "high", "enable", "low", 80));
    rules.append(Rule("high", "low", "high", "enable", "middle", 80));
    rules.append(Rule("high", "low", "high", "enable", "high", 80));

    rules.append(Rule("high", "high", "low", "disable", "low", 80));
    rules.append(Rule("high", "high", "low", "disable", "middle", 80));
    rules.append(Rule("high", "high", "low", "disable", "high", 80));
    rules.append(Rule("high", "high", "low", "enable", "low", 80));
    rules.append(Rule("high", "high", "low", "enable", "middle", 80));
    rules.append(Rule("high", "high", "low", "enable", "high", 80));
    rules.append(Rule("high", "high", "middle", "disable", "low", 80));
    rules.append(Rule("high", "high", "middle", "disable", "middle", 100));
    rules.append(Rule("high", "high", "middle", "disable", "high", 100));
    rules.append(Rule("high", "high", "middle", "enable", "low", 100));
    rules.append(Rule("high", "high", "middle", "enable", "middle", 100));
    rules.append(Rule("high", "high", "middle", "enable", "high", 100));
    rules.append(Rule("high", "high", "high", "disable", "low", 100));
    rules.append(Rule("high", "high", "high", "disable", "middle", 100));
    rules.append(Rule("high", "high", "high", "disable", "high", 100));
    rules.append(Rule("high", "high", "high", "enable", "low", 100));
    rules.append(Rule("high", "high", "high", "enable", "middle", 100));
    rules.append(Rule("high", "high", "high", "enable", "high", 100));

    return rules;
}

void MainWindow::on_pushButton_clicked()
{
    bool power = ui->powerOn->isChecked();
    qreal cpu = ui->cpuSlider->value();
    qreal gpu = ui->gpuSlider->value();
    qreal disk = ui->diskSlider->value();
    qreal temperature = ui->temperatureSpinBox->value();

    QVector<Rule> rules = genRules();
    QVector<QVector<qreal> > pastFuzzi = fuzzi(rules, cpu, disk, gpu, power, temperature);
    QVector<qreal> pastAgreg = agregate(pastFuzzi);
    qreal answer = defuzzi(pastAgreg, rules);
    QMessageBox::about(this, tr("О MapDesigner"),
                QString::number(answer));
}


void MainWindow::on_cpuSlider_valueChanged(int value)
{
    ui->cpuText->setText(QString::number(value));
}


void MainWindow::on_gpuSlider_valueChanged(int value)
{
    ui->gpuText->setText(QString::number(value));
}


void MainWindow::on_diskSlider_valueChanged(int value)
{
    ui->diskText->setText(QString::number(value));
}


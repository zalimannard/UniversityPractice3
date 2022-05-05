#include "resultwindow.h"
#include "ui_resultwindow.h"

#include <QtCharts>

ResultWindow::ResultWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResultWindow)
{
    ui->setupUi(this);
}

ResultWindow::~ResultWindow()
{
    delete ui;
}

void ResultWindow::on_pushButton_clicked()
{
    this->close();
}

void ResultWindow::setResult(QString value)
{
    ui->label->setText(value);
}

void ResultWindow::setGraphValue(QVector<QPair<QString, qreal> > values)
{
    QBarSeries *series = new QBarSeries();

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Влияние отдельных частей");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;

    QBarSet *barSet = new QBarSet("Значения");
    for (QPair<QString, qreal> value : values)
    {
        *barSet << value.second;
        categories << value.first;
    }
    series->append(barSet);
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->scrollArea->setWidget(chartView);
}

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

    for (QPair<QString, qreal> value : values)
    {
        QBarSet *barSet = new QBarSet(value.first);
        *barSet << value.second;
        series->append(barSet);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Влияние отдельных частей");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "01.01.2014";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->scrollArea->setWidget(chartView);
}

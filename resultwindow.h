#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QWidget>

namespace Ui {
class ResultWindow;
}

class ResultWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ResultWindow(QWidget *parent = nullptr);
    ~ResultWindow();

    void setResult(QString value);
    void setGraphValue(QVector<QPair<QString, qreal> > values);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ResultWindow *ui;
};

#endif // RESULTWINDOW_H

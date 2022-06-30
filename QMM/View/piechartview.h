#ifndef PIECHARTVIEW_H
#define PIECHARTVIEW_H

#include "view.h"

class PieChartView : public View
{
    Q_OBJECT

private:
    void connectWidgets() const override;

public:
    explicit PieChartView(const QSize& size = QSize(720, 480), const QString& title = QString("QMM"), View* parent = nullptr);
};

#endif // PIECHARTVIEW_H

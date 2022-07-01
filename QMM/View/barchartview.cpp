#include "barchartview.h"

void BarChartView::connectWidgets() const {}

BarChartView::BarChartView(const QSize& size, const QString& title, View* parent)
    : View(size, title, parent)
{
    auto layout = new QVBoxLayout();

    auto chartView = createChart();

    layout->addWidget(chartView);

    setLayout(layout);

    connectWidgets();
}

QChartView* BarChartView::createChart() {
    barChart = new QChart();
    barChart->setTitle("Uscite mensili per categoria");
    barChart->setAnimationOptions(QChart::SeriesAnimations);
    barChart->legend()->setAlignment(Qt::AlignBottom);

    bars = new QBarSeries();

    auto view = new QChartView(barChart, this);
    view->setRenderHint(QPainter::Antialiasing);
    return view;

}

void BarChartView::defineSets(const std::vector<Category>& categories) {
    for(auto c : categories) {
        sets.insert({c, new QBarSet(enumToString.at(c))});
    }
}

void BarChartView::insertInSet(const Category set, const double value) {
    sets.find(set)->second->append(value);
}

void BarChartView::insertSeries() {
    for(auto s : sets) {
        bars->append(s.second);
    }

    barChart->addSeries(bars);
}

void BarChartView::defineAxis() {

    QStringList months;
    months<< "Gen" << "Feb" << "Mar" << "Apr" << "Mag" << "Giu"
          << "Lug" << "Ago" << "Set" << "Ott" << "Nov" << "Dic";

    auto axisX = new QBarCategoryAxis();
    axisX->append(months);
    barChart->addAxis(axisX, Qt::AlignBottom);
    bars->attachAxis(axisX);

    auto axisY = new QValueAxis();
    barChart->addAxis(axisY, Qt::AlignLeft);
    bars->attachAxis(axisY);

}

#include "scatterchartview.h"

void ScatterChartView::connectWidgets() const {}

ScatterChartView::ScatterChartView(const QSize& size, const QString& title, View* parent) :
    View(size, title, parent)
{
    auto layout = new QVBoxLayout();

    auto chartView = createChart();

    layout->addWidget(chartView);

    setLayout(layout);

    connectWidgets();
}

QChartView* ScatterChartView::createChart() {
    scatterChart = new QChart();

    scatterChart->setTitle("Transazioni");
    scatterChart->legend()->setMarkerShape(QLegend::MarkerShapeFromSeries);

    auto view = new QChartView(scatterChart, this);
    view->setRenderHint(QPainter::Antialiasing);
    return view;
}

void ScatterChartView::defineSeries(const std::vector<Category>& categories) {
    bool markerChanger = false;
    for(auto c : categories) {
        auto serie = new QScatterSeries();
        serie->setName(enumToString.at(c));
        auto marker = markerChanger ? QScatterSeries::MarkerShapeCircle :
                                      QScatterSeries::MarkerShapeRectangle;
        serie->setMarkerShape(marker);
        markerChanger = !markerChanger;

        series.insert({c, serie});
    }
}

void ScatterChartView::insertInSerie(const Category serie, const QDate &date, const double value)
{
    QDateTime dateTime; dateTime.setDate(date); dateTime.setTime(QTime());
    series.find(serie)->second->append(dateTime.toMSecsSinceEpoch(), value);
}

void ScatterChartView::insertSeries()
{
    for(auto s : series) scatterChart->addSeries(s.second);
}

void ScatterChartView::defineAxis(const std::pair<int, int>& time, const std::pair<double, double>& value) {

    auto axisX = new QDateTimeAxis();
    axisX->setFormat("dd-MM");
    axisX->setRange(QDateTime(QDate(time.first, 1, 1), QTime()), QDateTime(QDate(time.second, 12, 31), QTime()));
    scatterChart->addAxis(axisX, Qt::AlignBottom);

    auto axisY = new QValueAxis();
    axisY->setRange(value.first, value.second);
    scatterChart->addAxis(axisY, Qt::AlignLeft);

    for(auto s : series) {
        s.second->attachAxis(axisX);
        s.second->attachAxis(axisY);
    }
}

#include "areachartview.h"

void AreaChartView::connectWidgets() const {}

AreaChartView::AreaChartView(const QSize &size, const QString &title, View *parent)
    : View(size, title, parent)
{
    auto layout = new QVBoxLayout();

    auto chartView = createChart();

    layout->addWidget(chartView);

    setLayout(layout);
}

Category AreaChartView::selectCategory(const std::vector<Category> categories) const {
    QStringList catList;
    for(auto c : categories) catList.append(enumToString.at(c));
    bool ok = false;
    QString dialogResult = QInputDialog::getItem(const_cast<AreaChartView*>(this),
                                             "Seleziona categoria",
                                             "Categoria",
                                             catList, 0, false, &ok);
    Category selected;
    if(ok && !dialogResult.isEmpty())
        selected = categories.at(catList.indexOf(dialogResult));
    else selected = *categories.begin(); // default prima disponibile

    return selected;
}

QChartView* AreaChartView::createChart() {
    areaChart = new QChart();
    areaChart->setTitle("Uscite mensili per categoria");

    auto view = new QChartView(areaChart, this);
    view->setRenderHint(QPainter::Antialiasing);
    return view;
}

void AreaChartView::defineSeries() {
    upper = new QLineSeries();
    lower = new QLineSeries();
    for(int i=1; i<=12; i++) lower->append(i, 0);

}

void AreaChartView::insertInSerie(const int month, const double value)
{
    upper->append(month, value);
}

void AreaChartView::insertSerie(const Category cat) {
    serie = new QAreaSeries(upper, lower);
    serie->setName(enumToString.at(cat));
    areaChart->addSeries(serie);
}

void AreaChartView::defineAxis(const double max) const {
    auto axisX = new QValueAxis();
    axisX->setTitleText("Mese");
    axisX->setRange(1, 12);
    axisX->setTickCount(12);
    axisX->setLabelFormat("%d");
    areaChart->addAxis(axisX, Qt::AlignBottom);
    serie->attachAxis(axisX);

    auto axisY = new QValueAxis();
    axisY->setTitleText("Uscite");
    axisY->setRange(0, max);
    areaChart->addAxis(axisY, Qt::AlignLeft);
    serie->attachAxis(axisY);
}

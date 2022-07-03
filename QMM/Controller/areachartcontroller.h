#ifndef AREACHARTCONTROLLER_H
#define AREACHARTCONTROLLER_H

#include "controller.h"
#include "View/areachartview.h"
#include "Model/areachartmodel.h"

class AreaChartController : public Controller
{
    Q_OBJECT

private:
    void connectView() const override;
public:
    explicit AreaChartController(AreaChartView* v,
                                 Model* m,
                                 Controller* parent = nullptr);

    AreaChartView* getView() const override;
    AreaChartModel* getModel() const override;

public slots:
    void onCloseView() const override;
};

#endif // AREACHARTCONTROLLER_H

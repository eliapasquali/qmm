#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QSize>
#include <QCloseEvent>

class View : public QWidget {

    Q_OBJECT

private:

    virtual void connectWidgets() const = 0;

public:

    /**
     * @brief Costruttore base di View, con valori di default
     * @param size QSize definito di default a 720x480
     * @param parent Necessario per ogni QWidget, di default nullo
     */
    explicit View(const QSize& size = QSize(1024, 768), const QString& title = QString("QMM"), View* parent = nullptr);
    /**
     * @brief Distruttore, definito virtuale nella classe base
     *  Lavora insieme al meccanismo di default della libreria QT
     */
    virtual ~View();

    /**
     * @brief Metodo di supporto per la modifica della grandezza della finestra
     * @param size QSize con la nuova grandezza da impostare
     */
    void setSize(const QSize& size);
    /**
     * @brief Metodo di supporto per impostare il titolo della finestra
     * @param title QString contenente il titolo voluto
     */
    void setTitle(const QString& title);

    /**
     * @brief Quando si richiede la chiusura della finestra viene inviato il
     *  segnale closeView dalla View al Controller
     * @param closeEvent QCloseEvent raccolto alla richiesta di chiusura
     */
    void closeEvent(QCloseEvent* closeEvent) override;

signals:
    void closeView() const;

public slots:

};

#endif //VIEW_H


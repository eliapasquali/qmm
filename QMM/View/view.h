#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QSize>
#include <QCloseEvent>
#include <QMessageBox>
#include <QInputDialog>

class View : public QWidget {

    Q_OBJECT

private:
    /**
     * @brief Metodo di supporto per la connessione di signal e slot dei vari widget
     *          presenti all'interno della view
     */
    virtual void connectWidgets() const = 0;

    int year; // Anno di riferimento per grafici e componenti view

public:
    static void errorMessage(QString s); // per avere messaggi di errore personalizzati in base all errore che viene fuori

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
     * @brief Metodo di supporto per la selezione dell'anno da utilizare nei vari
     *          componenti delle View
     */
    void setYear(std::pair<int, int> range);

    /**
     * @brief Ritorna l'anno selezionato dal QDialog
     * @return int anno
     */
    int getYear() const;
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


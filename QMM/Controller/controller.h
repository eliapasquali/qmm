#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>

#include "View/view.h"
#include "Model/model.h"

class Controller : public QWidget
{
    Q_OBJECT
public:

    View* view;
    Model* model;

    /**
     * @brief Costruisce il controller collegando View e Model
     * @param v View gestita dal Controller
     * @param m Model da cui il Controller può ottenere i dati
     * @param parent Padre del controller, legato a QT
     */
    explicit Controller(View* v,
                        Model* m,
                        QWidget *parent = nullptr);
    /**
     * @brief Distruttore virtuale alla base della gerarchia
     */
    virtual ~Controller();

    /**
     * @brief Metodo virtuale puro che permette di ottenere la View gestita
     * @return Puntatore alla view
     */
    virtual View* getView() const = 0;
    /**
     * @brief Metodo virtuale puro che permette di ottenere il Model
     * @return Puntatore al model
     */
    virtual Model* getModel() const = 0;
    /**
     * @brief Metodo virtuale che rende visibile la View gestita
     */
    virtual void makeVisibile() const;

private:
    /**
     * @brief Metodo virtuale puro che si occupa di connettere i segnali della
     *          View al Controller
     */
    virtual void connectView() const;

signals:

public slots:
    /**
     * @brief Metodo virtuale puro che gestisce le operazioni alla segnale della View
     */
    virtual void onCloseView() const = 0;
};

#endif // CONTROLLER_H

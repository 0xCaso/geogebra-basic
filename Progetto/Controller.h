#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QString>
#include "Model.h"
#include "Interfaccia.h"

class Controller : public QObject {
    Q_OBJECT
private:
    Model* model;
    Interfaccia* view;

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller() =default;

    void setModel(Model* m);
    void setView(Interfaccia* v);

    void refreshInfoDisegni() const;
    void showInfoDisegni() const;

public slots:

    void addPunto() const;
    void addSegmento() const;
    void addRetta() const;
    void addCirconferenza() const;
    void addEllisse() const;
    void addRegolare() const;
    void addPoligono() const;
    /*
    */
    void removeDisegno() const;
    void cancellaTutto() const;
    WorkSpace *getWorkspace() const;
    
    void write(QJsonObject&) const;
    void read(const QJsonObject&) const;
    bool saveToFile() const;
    void loadFromFile() const;
};

#endif // CONTROLLER_H

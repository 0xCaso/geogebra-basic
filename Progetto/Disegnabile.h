#ifndef DISEGNABILE_H
#define DISEGNABILE_H

#include "string"
#include <unordered_map>
#include <QColor>
#include <QJsonObject>
#include <QJsonArray>

using std::string;

#include <QPainter>

class Disegnabile {
protected:
    Disegnabile(string = "Disegno", QColor = Qt::black);

private:
    string nome;
    QColor colore;

public:
    string getNome() const;
    QColor getColore() const;

    virtual Disegnabile* clone() const =0;
    virtual void disegna(QPainter*, int) const =0;
    virtual std::unordered_map<string,string> getInfo() const =0;
    virtual ~Disegnabile() =default;
    
    virtual void read(const QJsonObject&) = 0;
    virtual void write(QJsonObject&) const = 0;

    void setNome(string);
    void setColor(QString);
};

#endif // DISEGNABILE_H

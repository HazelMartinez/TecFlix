#ifndef PAGINA_ATRAS_H
#define PAGINA_ATRAS_H

#include <QMainWindow>

namespace Ui {
class pagina_atras;
}

class pagina_atras : public QMainWindow
{
    Q_OBJECT

public:
    explicit pagina_atras(QWidget *parent = 0);
    ~pagina_atras();

private:
    Ui::pagina_atras *ui;
};

#endif // PAGINA_ATRAS_H

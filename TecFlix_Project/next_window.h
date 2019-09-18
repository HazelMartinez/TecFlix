#ifndef NEXT_WINDOW_H
#define NEXT_WINDOW_H

#include <QMainWindow>

namespace Ui {
class next_window;
}

class next_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit next_window(QWidget *parent = 0);
    ~next_window();

private:
    Ui::next_window *ui;
};

#endif // NEXT_WINDOW_H

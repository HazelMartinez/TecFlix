#include "testapp.h"

testapp::testapp()
{

}

testApp::testApp(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
    ui.setupUi(this);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            QPushButton* panelButton = new QPushButton();
            panelButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            ui.PanelButtonGridLayout->addWidget(panelButton,i,j);
        }
    }
}

testApp::~testApp()
{

}

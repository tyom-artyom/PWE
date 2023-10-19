#include "mainwindow.h"

int main(int argc, char** argv)
{
    QApplication application(argc, argv);

    MainWindow main_window;

    application.setStyle(main_window.settings.value("style", "Fusion").toString());

    main_window.show();

    return application.exec();
}

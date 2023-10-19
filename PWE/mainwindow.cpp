#include "mainwindow.h"

MainWindow::MainWindow() : QMainWindow()
{
    setMinimumSize(300, 300);

    //{{{   menuBar
        //{{{   initializations
            menuBar          = new QMenuBar(this);

            fileMenu         = new QMenu   ("File",       menuBar);

            openAction       = new QAction ("Open",       fileMenu);
            saveAction       = new QAction ("Save",       fileMenu);
            saveAsAction     = new QAction ("Save as",    fileMenu);
            exitAction       = new QAction ("Exit",       fileMenu);

            viewMenu         = new QMenu   ("View",       menuBar);

            setStyleAction   = new QAction ("Set style",  viewMenu);

            setStyleSubMenu  = new QMenu   (              viewMenu);

            if (QStyleFactory::keys().contains("Windows"))
            {
                windowsAction    = new QAction ("Windows",    setStyleSubMenu);
            }
            if (QStyleFactory::keys().contains("Mac"))
            {
                macAction        = new QAction ("Mac",        setStyleSubMenu);
            }
            if (QStyleFactory::keys().contains("Fusion"))
            {
                fusionAction     = new QAction ("Fusion",     setStyleSubMenu);
            }
            if (QStyleFactory::keys().contains("Plastique"))
            {
                plastiqueAction  = new QAction ("Plastique",  setStyleSubMenu);
            }
            if (QStyleFactory::keys().contains("CDE"))
            {
                cdeAction        = new QAction ("CDE",        setStyleSubMenu);
            }
            if (QStyleFactory::keys().contains("CleanLooks"))
            {
                cleanLooksAction = new QAction ("CleanLooks", setStyleSubMenu);
            }
            if (QStyleFactory::keys().contains("Gtk"))
            {
                gtkAction        = new QAction ("Gtk",        setStyleSubMenu);
            }
        //}}}

        //{{{   connections
            QObject::connect(openAction,       SIGNAL(triggered()), this, SLOT(open()));
            QObject::connect(saveAction,       SIGNAL(triggered()), this, SLOT(save()));
            QObject::connect(saveAsAction,     SIGNAL(triggered()), this, SLOT(saveAs()));
            QObject::connect(exitAction,       SIGNAL(triggered()), this, SLOT(exit()));

            if (QStyleFactory::keys().contains("Windows"))
            {
                QObject::connect(windowsAction,    &QAction::triggered, this, [&](){setApplicationStyle("Windows");});
            }
            if (QStyleFactory::keys().contains("Mac"))
            {
                QObject::connect(macAction,        &QAction::triggered, this, [&](){setApplicationStyle("Mac");});
            }
            if (QStyleFactory::keys().contains("Fusion"))
            {
                QObject::connect(fusionAction,     &QAction::triggered, this, [&](){setApplicationStyle("Fusion");});
            }
            if (QStyleFactory::keys().contains("Plastique"))
            {
                QObject::connect(plastiqueAction,  &QAction::triggered, this, [&](){setApplicationStyle("Plastique");});
            }
            if (QStyleFactory::keys().contains("CDE"))
            {
                QObject::connect(cdeAction,        &QAction::triggered, this, [&](){setApplicationStyle("CDE");});
            }
            if (QStyleFactory::keys().contains("CleanLooks"))
            {
                QObject::connect(cleanLooksAction, &QAction::triggered, this, [&](){setApplicationStyle("CleanLooks");});
            }
            if (QStyleFactory::keys().contains("Gtk"))
            {
                QObject::connect(gtkAction,        &QAction::triggered, this, [&](){setApplicationStyle("Gtk");});
            }
        //}}}

        //{{{   adding actions to the subMenu
            if (QStyleFactory::keys().contains("Windows"))
            {
                setStyleSubMenu->addAction(windowsAction);
            }
            if (QStyleFactory::keys().contains("Mac"))
            {
                setStyleSubMenu->addAction(macAction);
            }
            if (QStyleFactory::keys().contains("Fusion"))
            {
                setStyleSubMenu->addAction(fusionAction);
            }
            if (QStyleFactory::keys().contains("Plastique"))
            {
                setStyleSubMenu->addAction(plastiqueAction);
            }
            if (QStyleFactory::keys().contains("CDE"))
            {
                setStyleSubMenu->addAction(cdeAction);
            }
            if (QStyleFactory::keys().contains("CleanLooks"))
            {
                setStyleSubMenu->addAction(cleanLooksAction);
            }
            if (QStyleFactory::keys().contains("Gtk"))
            {
                setStyleSubMenu->addAction(gtkAction);
            }
        //}}}

        //{{{   setting the subMenu to the action
            setStyleAction->setMenu(setStyleSubMenu);
        //}}}

        //{{{   adding all the actions to the menus
            fileMenu->addAction       (openAction);
            fileMenu->addAction       (saveAction);
            fileMenu->addAction       (saveAsAction);

            fileMenu->addSeparator    ();

            fileMenu->addAction       (exitAction);


            viewMenu->addAction       (setStyleAction);
        //}}}


        //{{{   adding all the menus
            menuBar->addMenu          (fileMenu);
            menuBar->addMenu          (viewMenu);
        //}}}

        //{{{   setting the menuBar
            setMenuBar                (menuBar);
        //}}}
    //}}}

    //{{{   textBox
        //{{{   initialization
            textBox = new QTextEdit(this);
        //}}}

        //{{{   setting textBox
            setCentralWidget(textBox);
        //}}}
    //}}}

    //{{{   statusBar
        //{{{   initializations
            statusBar = new QStatusBar(this);

            currentFileName = new QLabel(fileName, statusBar);
        //}}}

        //{{{   adding the label to the statusBar
            statusBar->addWidget(currentFileName);
        //}}}

        //{{{   setting statusBar
            setStatusBar(statusBar);
        //}}}
    //}}}
}

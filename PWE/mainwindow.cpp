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

            windowsAction    = new QAction ("Windows",    setStyleSubMenu);
            macAction        = new QAction ("Mac",        setStyleSubMenu);
            fusionAction     = new QAction ("Fusion",     setStyleSubMenu);
            plastiqueAction  = new QAction ("Plastique",  setStyleSubMenu);
            cdeAction        = new QAction ("CDE",        setStyleSubMenu);
            cleanLooksAction = new QAction ("CleanLooks", setStyleSubMenu);
            gtkAction        = new QAction ("Gtk",        setStyleSubMenu);
        //}}}

        //{{{   connections
            QObject::connect(openAction,   SIGNAL(triggered()), this, SLOT(open()));
            QObject::connect(saveAction,   SIGNAL(triggered()), this, SLOT(save()));
            QObject::connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));
            QObject::connect(exitAction,   SIGNAL(triggered()), this, SLOT(exit()));
        //}}}

        //{{{   adding actions to the subMenu
            setStyleSubMenu->addAction(windowsAction);
            setStyleSubMenu->addAction(macAction);
            setStyleSubMenu->addAction(fusionAction);
            setStyleSubMenu->addAction(plastiqueAction);
            setStyleSubMenu->addAction(cdeAction);
            setStyleSubMenu->addAction(cleanLooksAction);
            setStyleSubMenu->addAction(gtkAction);
        //}}}

        //{{{   setting the subMenu
            setStyleAction->setMenu(setStyleSubMenu);
        //}}}

        //{{{   adding all the actions
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

#include "needhelp.h"



QString NEEDHELP::ButtonEditor()
{
                return "QPushButton {"
                "   background: none;"
                "   background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0.99005, y2:1, stop:0.298507 rgba(206, 130, 175, 255), stop:1 rgba(255, 255, 255, 255));"
                "   Border: none;"
                "   border-radius:19px;"
                "   font-family: 'After Cheret' ;"
                "   font-size: 16px;"
                "}"
               "QPushButton::hover {"
                "   background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.99005, y2:1, stop:0.298507 rgba(247, 156, 211, 255), stop:1 rgba(255, 255, 255, 255));"
                "}"
               "QPushButton::pressed{"
                "   background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.99005, y2:1, stop:0.298507 rgba(177, 112, 151, 255), stop:1 rgba(255, 255, 255, 255));"
                "}";
}

QString NEEDHELP::Cats_dogsStyle()
{
                return "QWidget {"
                "background-color: rgb(246, 238, 231);"
                       "}";
}

QString NEEDHELP::LabelEditor()
{

                return "QLabel {"
               "   font-family: 'After Cheret' ;"
               "   font-size: 50px;"
               "}";
}

QString NEEDHELP::LButtonEditor()
{
                return "QPushButton {"
                "background-color:rgb(230, 192, 236);"
                "background-image: url(:/pic/pngwing.com-11.png);"
                "background-repeat: no-repeat;"
                "background-position: center center;"
                "border: 1px solid #333;"
                "border-top-left-radius: 5px;"
                "border-bottom-left-radius: 5px;"
                "}";

}

QString NEEDHELP::RButtonEditor()
{
                return "QPushButton {"
                "background-color:rgb(230, 192, 236);"
                "background-image: url(:/pic/pngwing.com-6.png);"
                "background-repeat: no-repeat;"
                "background-position: center center;"
                "border: 1px solid #333;"
                "border-top-right-radius: 5px;"
                "border-bottom-right-radius: 5px;"
                "}";
}

QString NEEDHELP::LButtonActEditor()
{

            return "QPushButton {"
            "background-color:rgb(210, 176, 219);"
            "background-image: url(:/pic/pngwing.com-11.png);"
            "background-repeat: no-repeat;"
            "background-position: center center;"
            "border: 1px solid #333;"
            "border-top-left-radius: 5px;"
            "border-bottom-left-radius: 5px;"
            "}";
}

QString NEEDHELP::RButtonActEditor()
{
                return "QPushButton {"
                "background-color:rgb(210, 176, 219);"
                "background-image: url(:/pic/pngwing.com-6.png);"
                "background-repeat: no-repeat;"
                "background-position: center center;"
                "border: 1px solid #333;"
                "border-top-right-radius: 5px;"
                "border-bottom-right-radius: 5px;"
                       "}";
}

QString NEEDHELP::Label3Editor()
{
    return "QLabel {"
   "   font-family: 'Dynasty';"
   "   font-size: 22px;"
           "}";
}

QString NEEDHELP::TabButtons()
{
    return "QTabWidget::pane {"
            "border: none;"
            "border: 1px solid #222; "
            "}"
            "QWidget#tab_2 {"
            "background-color: rgb(33,  40,  50);"
           "}";
}

QString NEEDHELP::BeforeGame()
{
    return "QPushButton {"
            "border: none;"
            "background: rgb(233, 208, 180);"
            "}"
            "QPushButton::hover {"
            "background: rgb(233, 208, 170);"
           "}";
}

QString NEEDHELP::MessagePlay()
{
    return "QLabel {"
            "font-family: 'After Cheret';"
            "font-size: 14px;"
            "background:none;"
            "color:#222;"
            "}";
}

QString NEEDHELP::MessageWin()
{
    return "QLabel {"
            "font-family: 'After Cheret';"
            "font-size: 14px;"
            "border-radius: 4px;"
            "background:rgb(178, 227, 235);"
            "border: 1px solid #222;"
            "color:#222;"
            "}";
}

QString NEEDHELP::MessageLose()
{
    return "QLabel {"
            "font-family: 'After Cheret';"
            "font-size: 14px;"
            "border-radius: 4px;"
            "background:rgb(230, 186, 193);"
            "border: 1px solid #222;"
            "color:#222;"
           "}";
}

QString NEEDHELP::MessageCatsPlay()
{
    return "QLabel {"
            "font-family: 'After Cheret';"
            "font-size: 14px;"
            "background:none;"
            "color:#222;"
            "}";
}

QString NEEDHELP::MessageCatsWin()
{
    return "QLabel {"
            "font-family: 'After Cheret';"
            "font-size: 14px;"
            "border-radius: 4px;"
            "background:rgb(178, 227, 235);"
            "border: 1px solid #222;"
            "color:#222;"
            "}";
}


QString NEEDHELP::MessageCatsLose()
{
    return "QLabel {"
            "font-family: 'After Cheret';"
            "font-size: 14px;"
            "border-radius: 4px;"
            "background:rgb(230, 186, 193);"
            "border: 1px solid #222;"
            "color:#222;"
           "}";
}

QString NEEDHELP::DogsPlay()
{
    return "QPushButton {"
            "border: none;"
            "background: rgb(233, 208, 180) url(:/pic/pngwing.com-11.png) no-repeat center center;"
           "}";
}

 QString NEEDHELP::DogsWin()
{
    return "QPushButton {"
            "border: none;"
            "background-color: rgb(178, 227, 234);"
            "background-image:  url(:/pic/pngwing.com-11.png);"
            "background-repeat: no-repeat;"
            "background-position: center center;"
            "}";
}

QString NEEDHELP::Dogslose()
{
    return "QPushButton {"
            "border: none;"
            "background-color: rgb(230, 186, 193);"
            "background-image:  url(:/pic/pngwing.com-11.png);"
            "background-repeat: no-repeat;"
            "background-position: center center;"
            "}";
}


QString NEEDHELP::CatsPlay()
{
    return "QPushButton {"
            "border: none;"
            "background: rgb(233, 208, 180) url(:/pic/pngwing.com-6.png) no-repeat center center;"
            "}";
}

QString NEEDHELP::CatsWin()
{
    return "QPushButton {"
            "border: none;"
            "background-color: rgb(178, 227, 234);"
            "background-image:  url(:/pic/pngwing.com-6.png);"
            "background-repeat: no-repeat;"
            "background-position: center center;"
            "}";
}

QString NEEDHELP::Catslose()
{
    return "QPushButton {"
            "border: none;"
            "background-color: rgb(230, 186, 193);"
            "background-image:  url(:/pic/pngwing.com-6.png);"
            "background-repeat: no-repeat;"
            "background-position: center center;"
            "}";
}

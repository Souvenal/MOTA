#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QSvgWidget>

#include "component/components.h"

void RegisterAllComponents() {
    ComponentFactory &factory = ComponentFactory::GetComponentFactory();

    factory.RegisterComponent<Transform>();

    factory.RegisterComponent<BoxCollider>();

    factory.RegisterComponent<RigidBody>();

    factory.RegisterComponent<SvgRenderer, QString>();
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "MOTA_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    Q_INIT_RESOURCE(resources);

    RegisterAllComponents();

    MainWindow w;
    w.show();

    return app.exec();
}

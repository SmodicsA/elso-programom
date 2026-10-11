#include <QCoreApplication>
#include <QTextStream>
#include <stdio.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Biztosítja, hogy a Windows konzol helyesen kezelje a kimenetet
    QTextStream out(stdout);
    out << "Hello World!" << Qt::endl;

    // Konzolos alkalmazásoknál megállítjuk a futást, hogy ne záródjon be azonnal az ablak
    out << "\nA kilepeshez nyomj Entert!" << Qt::endl;
    out.flush();
    getchar();

    return 0; // Egyszerű konzolos teszthez nem kell elindítani az a.exec() eseményhurkot

}

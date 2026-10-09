#include <QCoreApplication>
#include <QTextStream>
#include <conio.h> // Ez a Windows-specifikus könyvtár kell a _getch() használatához

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Biztosítja, hogy a Windows konzol helyesen kezelje a kimenetet
    QTextStream out(stdout);
    out << "Hello World!" << Qt::endl;

    // Konzolos alkalmazásoknál megállítjuk a futást, hogy ne záródjon be azonnal az ablak
    out << "\nA kilepeshez nyomj meg egy gombot..." << Qt::endl;
    out.flush();
    _getch();

    return 0; // Egyszerű konzolos teszthez nem kell elindítani az a.exec() eseményhurkot


}

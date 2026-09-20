#include <iostream> 
#include <string> 

struct KC
{
    std::string nameKC;
    int kolvozehKC;
    int zehrabotKC; 
    int clasKC;
};
struct Pipe
{
    std::string namepipe;
    double dlinapipe;
    int mmpipe;
    bool remontpipe;
};

//Для каждой структуры реализовать функции : 
//сохранение данных в файл, загрузка данных из файла.

void redactpipe(Pipe& pipe)
{
    std::string vodremont;
    do
    {
        std::cout << "\nV Remonte? 'Yes' / 'No': ";
        std::cin >> vodremont;
    } while ((vodremont != "Yes") && (vodremont != "No") && (vodremont != "yes") && (vodremont != "no"));
    if ((vodremont == "Yes") || (vodremont == "yes"))
    {
        pipe.remontpipe = 1;
    }
    else
    {
        pipe.remontpipe = 0;
    }
}
void redactkc(KC& kc)
{
    std::cout << "\nRead kol-vo rabot ZEH in KC: ";
    while (!(std::cin >> kc.zehrabotKC) || (kc.zehrabotKC < 0) || (kc.zehrabotKC > kc.kolvozehKC) || (std::cin.peek() != '\n'))
    {
        std::cout << "No! Read Kol-vo ZEH v Pabote: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}
void readconsolkc(KC& kc)
{
    std::cout << "\nRead name KC: ";
    std::cin >> kc.nameKC;
    
    std::cout << "\nRead Kol-vo ZEH in KC: ";
    while (!(std::cin >> kc.kolvozehKC) || (kc.kolvozehKC <= 0) || (std::cin.peek() != '\n'))
    {
        std::cout << "No! Read Kol-vo ZEH: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    
    redactkc(kc);
    std::cout << "\nRead Class KC: ";
    while (!(std::cin >> kc.clasKC) || (kc.clasKC <= 0) || (std::cin.peek() != '\n'))
    {
        std::cout << "No! Class - int >0, input: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}
void readconsolpipe(Pipe& pipe)
{
    std::cout << "\nRead Name Pipe: ";
    std::cin >> pipe.namepipe;
    
    std::cout << "\nRead dlina(km) pipe: ";
    while (!(std::cin >> pipe.dlinapipe) || (pipe.dlinapipe <= 0) || (std::cin.peek() != '\n'))
    {
        std::cout << "No! Read dlina in KM: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::cout << "\nRead diametr(mm) pipe: ";
    while (!(std::cin >> pipe.mmpipe ) || (pipe.mmpipe <= 0) || (std::cin.peek() != '\n'))
    {
        std::cout << "No! Read diametr in mm: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    redactpipe(pipe);
}
void coutconsol3(Pipe& pipe)
{
    std::cout << "\n---Pipe---\n" << "Name:" << pipe.namepipe << "\n";
    std::cout << "Dlina(km): " << pipe.dlinapipe << "\n";
    std::cout << "Diametr(mm): " << pipe.mmpipe << "\n";
    if (pipe.remontpipe == 0)
    {
        std::cout << "B PeMoHTe:  HeT!\n";
    }
    else
    {
        std::cout << "B PeMoHTe: Da!\n";
    }
}
void coutconsol3kc(KC& kc)
{
    std::cout << "\n---KC---\n" << "Name: " << kc.nameKC << "\n";
    std::cout << "Kol-vo zehov:" << kc.kolvozehKC << "\n";
    std::cout << "Kol-vo zehov B PaboTe :" << kc.zehrabotKC << "\n";
    std::cout << "Class CTaHzuu:" << kc.clasKC << "\n";
}
void menu()
{
    std::cout << "\n1.Add Pipe\n";
    std::cout << "2.Add KC\n";
    std::cout << "3.Chek objects\n";
    std::cout << "4.Redact Pipe\n";
    std::cout << "5.Redact KC\n";
    std::cout << "6.Save\n";
    std::cout << "7.Download\n";
    std::cout << "0.Exit\n";
}
int main()
{
    Pipe pipe{};
    KC KC{};
    char vvod;
    while (true)
    {
        menu();
        do
        {
            std::cout << "\nInput: ";
            std::cin >> vvod;
            if ((vvod < '0') || (vvod > '7') || (std::cin.peek() != '\n'))
            {
                std::cout << "Input int 0-7: ";
                std::cin.ignore(10000, '\n');
            }

        }
        while ((vvod < '0') || (vvod > '7') || (std::cin.peek() != '\n'));
    
        switch (vvod)
        {
        case '1':
        {
            readconsolpipe(pipe);
            break;
        }
        case '2':
        {
            readconsolkc(KC);
            break;
        }
        case '3':
        {
            coutconsol3(pipe);
            coutconsol3kc(KC);
            break;
        }
        case '4':
        {
            redactpipe(pipe);
            break;
        }
        case '5':
        {
            redactkc(KC);
            break;
        }
        case '0':
        {
            return 0;
        }
        default:
        {
            std::cout << "No command, input OT 0 do 7.\n";
            break;
        }
        }

    }
}
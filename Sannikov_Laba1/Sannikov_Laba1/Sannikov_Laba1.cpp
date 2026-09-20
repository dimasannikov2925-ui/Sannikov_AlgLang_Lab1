//Создать консольное приложение, описывающее базовые сущности трубопроводного транспорта газа или нефти: 
//труба и КС или НПС(в сильно упрощенном варианте). +
//Свойства трубы : километровая отметка(название), длина(в км), диаметр(в мм), признак "в ремонте".+
//Свойства КС : название, количество цехов, количество цехов в работе, класс станции(некий показатель,+
//обобщающий различные специфические характеристики)+ 
// 
//При запуске программы выводится меню, запрашивающее в бесконечном цикле действие от пользователя.+
//Пример меню : 1. Добавить трубу 2. Добавить КС 3. Просмотр всех объектов 4. Редактировать трубу+
//5. Редактировать КС 6. Сохранить 7. Загрузить 0. Выход+

//Поддержка русского языка не обязательна.+
//В программе идет работа с одной трубой и одной КС.+
//Обязательно : проверка корректности совершаемых действий.Программа должна быть устойчива к любым действиям пользователя.
//Повод для снижения балла : неосмысленное наименование переменных и функций, необоснованное использование глобальных переменных,
//неструктурированный код.
//Код выполнения работы фиксируется коммитами в github(с осмысленными комментариями).К ответу прикрепляется ссылка на финальный коммит!
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
//считывание с консоли, вывод на консоль+, редактирование признака "в ремонте" для трубы+, 
//запуск и останов цеха в КС, сохранение данных в файл, загрузка данных из файла.
// ЯЯ   Предусмотреть ошибку при / в строке + числ знач в каждой переменной     !!
// ЯЯ   Предусмотреть ввод неверного типа данных при числах                     !!
// допустим класс станций - А В С + 0 1 2, (А1, А2, А3) исправить               !!
// 10abc - исправить ошибку                                                     !!

void readconsolkc(KC& kc)
{
    std::cout << "\nRead name KC: ";
    std::cin >> kc.nameKC;
    std::cout << "\nRead Kol-vo ZEH in KC: ";
    while (!(std::cin >> kc.kolvozehKC) || (kc.kolvozehKC < 0))
    {
        std::cout << "No! Read Kol-vo ZEH: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::cout << "\nRead kol-vo rabot ZEH in KC: ";
    while (!(std::cin >> kc.zehrabotKC) || (kc.zehrabotKC < 0) || (kc.zehrabotKC > kc.kolvozehKC))
    {
        std::cout << "No! Read Kol-vo ZEH v Pabote: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::cout << "\nRead class KC: ";
    while (!(std::cin >> kc.clasKC) || (kc.clasKC < 0))
    {
        std::cout << "No! Read class KC: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}
void readconsolpipe(Pipe& pipe)
{
    std::cout << "\nRead Name Pipe: ";
    std::cin >> pipe.namepipe;
    std::cout << "\nRead dlina(km) pipe: ";
    while (!(std::cin >> pipe.dlinapipe) || (pipe.dlinapipe < 0))
    {
        std::cout << "No! Read dlina in KM: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::cout << "\nRead diametr(mm) pipe: ";
    while (!(std::cin >> pipe.mmpipe ) || (pipe.mmpipe < 0) )
    {
        std::cout << "No! Read diametr in mm: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::string vodremont;
    do
    {
        std::cout << "\nV Remonte? 'Yes' / 'No': ";
        std::cin >> vodremont;
    } while ((vodremont != "Yes") && (vodremont != "No") && (vodremont != "yes") && (vodremont != "no")); 
}
void coutconsol3(Pipe& pipe, KC& KC)
{
    std::cout << "Pipe:\n" << "Name:" << pipe.namepipe << "\n";
    std::cout << "Dlina(km): " << pipe.dlinapipe << "\n";
    std::cout << "Diametr(mm): " << pipe.mmpipe << "\n";
    //std::cout << "B PeMoHTe: " << pipe.remontpipe << "\n";
    if (pipe.remontpipe == 0)
    {
        std::cout << "B PeMoHTe:  HeT!\n";
    }
    else
    {
        std::cout << "B PeMoHTe: Da!\n";
    }
    std::cout << "KC\n" << "Name: " << KC.nameKC << "\n";
    std::cout << "Kol-vo zehov:" << KC.kolvozehKC << "\n";
    std::cout << "Kol-vo zehov B PaboTe :" << KC.zehrabotKC << "\n";
    std::cout << "Class CTaHzuu:" << KC.clasKC << "\n";
}
void redactpipe(Pipe& pipe)
{
    std::string vodremont;
    do
    {
        std::cout << "\nV Remonte? 'Yes' / 'No': ";
        std::cin >> vodremont;
    } while ((vodremont != "Yes") && (vodremont != "No") && (vodremont != "yes") && (vodremont != "no"));
}
void redactkc(KC& kc)
{
    std::cout << "\nRead kol-vo rabot ZEH in KC: ";
    while (!(std::cin >> kc.zehrabotKC) || (kc.zehrabotKC < 0) || (kc.zehrabotKC > kc.kolvozehKC))
    {
        std::cout << "No! Read Kol-vo ZEH v Pabote: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}
int main()
{
    Pipe pipe{};
    KC KC{};
    std::cout << "1.Add Pipe\n";
    std::cout << "2.Add KC\n";
    std::cout << "3.Chek objects\n";
    std::cout << "4.Redact Pipe\n";
    std::cout << "5.Redact KC\n";
    std::cout << "6.Save\n";
    std::cout << "7.Download\n";
    std::cout << "0.Exit\n";
    readconsolpipe(pipe);
    readconsolkc(KC);
    coutconsol3(pipe, KC);

}
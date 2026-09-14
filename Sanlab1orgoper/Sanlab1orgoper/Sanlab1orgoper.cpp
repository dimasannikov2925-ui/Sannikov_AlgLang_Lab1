#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

void writeError(const string& message)
{
    ofstream errorFile("error.txt", ios::app);

    if (errorFile.is_open())
    {
        errorFile << message << endl;
        errorFile.close();
    }
}

int main(int argc, char* argv[])
{
    // Если программа запущена без параметров
    if (argc == 1)
    {
        writeError("Error: command line parameters are not specified.");
        return 1;
    }

    // Обработка параметров командной строки
    for (int i = 1; i < argc; i++)
    {
        string key = argv[i];

        if (key == "-a" ||
            key == "-b" ||
            key == "-c" ||
            key == "-e")
        {
            cout << "Program name: " << argv[0]
                << ". Key " << key
                << " is processed." << endl;
        }
        else if (key == "-d")
        {
            time_t now = time(nullptr);
            tm localTime{};

            localtime_s(&localTime, &now);

            cout << "Current date and time: "
                << put_time(&localTime, "%d.%m.%Y %H:%M:%S")
                << endl;
        }
        else
        {
            writeError("Error: unknown key " + key);
        }
    }

    return 0;
}
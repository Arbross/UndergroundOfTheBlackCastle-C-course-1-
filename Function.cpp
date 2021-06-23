#include "Function.h"

void SetColor(int col)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

void Size_Console(int x, int y)
{
    HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD crd = { x, y };
    SMALL_RECT src = { 0, 0, crd.X , crd.Y };
    SetConsoleWindowInfo(out_handle, true, &src);
    SetConsoleScreenBufferSize(out_handle, crd);
}

void SetPos(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int isMenu(string menu_items[], int size, int counter)
{
    int key = 0, code = 0;

    do {
        key = (key + size) % size;
        for (int i = 0; i < size; i++)
        {
            SetPos(45, counter + i);
            if (key == i)
            {
                cout << " "; SetColor(8); cout << menu_items[i]; SetColor(3); cout << " " << endl; SetColor(15);
            }
            else
            {
                cout << " "; cout << menu_items[i]; cout << " " << endl;
            }
        }
        code = _getch();
        if (code == 224)
        {
            code = _getch();
            if (code == 80)
            {
                key++;
            }
            if (code == 72)
            {
                key--;
            }
        }
    } while (code != 13);
    return key;
}

struct Properties
{
    void Print()
    {

    }
};


struct Combat
{
    int m_impact_force = 0;
    int p_impact_force = 0;

    int m_endurance = 0;
    int p_endurance = 0;
}; 

struct Spells
{
public:
    string spells[50];
    int count_of_spells[10];

    void SelectSpells()
    {
        string path = "C:\\Users\\victor\\source\\repos\\Underground_of_the_black_castle\\Underground_of_the_black_castle\\Spells\\database_of_spells.txt";

        ifstream is_fin_spells;
        is_fin_spells.open(path);

        int counter = 0;
        if (is_fin_spells.is_open())
        {
            string currentLine;

            while (getline(is_fin_spells, currentLine))
            {
                counter++;
            }
        }

        int choose_skill = 0;
        for (int i = 0; i < 10; i++)
        {
            choose_skill = isMenu(spells, counter, 3);
            this->count_of_spells[i] = choose_skill;
        }
        
        is_fin_spells.close();
    }

    void DatabaseOfSpells()
    {
        string path = "C:\\Users\\victor\\source\\repos\\Underground_of_the_black_castle\\Underground_of_the_black_castle\\Spells\\database_of_spells.txt";

        ifstream fin_spells;
        fin_spells.open(path);

        char symbol;
        int i = 0;
        while (fin_spells.get(symbol))
        {
            if (symbol != '>')
            {
                spells[i] += symbol;
            }
            else if (symbol == '>')
            {
                i++;
            }
        }

        fin_spells.close();
    }

    void Print()
    {
        for (int i = 0; i < 50; i++)
        {
            if (spells[i] == "")
            {
                break;
            }

            cout << count_of_spells[i];
        }
    }
private:
};

struct Inventory
{
public:
    int gold = 0;
    string bag[8];
    string items[255];

    void Print()
    {
        cout << "Inventory:" << endl;

        for (int i = 1; i <= 7; i++)
        {
            cout << i << ". " << bag[i] << endl;
        }
        cout << "Gold: " << gold << endl;
        cout << endl;
    }
private:
};

struct Сharacteristics
{
public:
    int starter_skills = 0;
    int starter_endurans = 0;
    int starter_luck = 0;

    int mastery = 0;
    int endurans = 0;
    int luck = 0;

    void Print()
    {
        cout << "Mastery: " << "" << mastery << ", ";
        cout << "Endurans: " << "" << endurans << ", ";
        cout << "Luck: " << "" << luck << endl;
    }
private:
};

void ThroughOut(Inventory* inv, int item_inv_num)
{
    inv->bag[item_inv_num] = "";
}

void AddItem(Inventory* inv, int item_inv_num, int item_num)
{
    inv->bag[item_inv_num] = inv->items[item_num];
}

void ShowInv(Inventory* inv, Сharacteristics* charac)
{
    for (int i = 0; i < 9; i++)
    {
        cout << endl;
    }

    inv->Print();
    charac->Print();
}

void Starter_pack(Inventory* inv)
{
    inv->bag[1] = "Испытанный меч";
    inv->bag[2] = "Фляга с водой";

    inv->gold = 15;
}

void GenerateСharacteristics(Inventory* inv, Сharacteristics* charac)
{
    // Starter weapon
    Starter_pack(inv);

    // Skills
    charac->mastery += rand() % 6;
    charac->mastery += 6;

    charac->starter_skills += charac->mastery;

    // Endurans
    charac->endurans += rand() % 6;
    charac->endurans += rand() % 6;
    charac->endurans += 12;

    charac->starter_endurans += charac->endurans;

    // Luck
    charac->luck += rand() % 6;
    charac->luck += 6;

    charac->starter_luck += charac->luck;
}

void Menu()
{
    Inventory inv;
    Сharacteristics charac; 
    Spells spl;

    int choose = 0;
    string menu_items[5];

    menu_items[0] = "Adventure Start";
    menu_items[1] = "------Exit-----";
    choose = isMenu(menu_items, 2, 12);

    GenerateСharacteristics(&inv, &charac);

    switch (choose)
    {
    case 0: {
        system("cls");

        spl.DatabaseOfSpells();
        spl.SelectSpells();

        string firstname = "C:\\Users\\victor\\source\\repos\\Underground_of_the_black_castle\\Underground_of_the_black_castle\\Database\\#n_", number = "0", secondname = ".txt";
        spl.DatabaseOfSpells();

        while (true)
        {
            system("cls");

            string full;
            string is_temp[5];
            string temp[5];
            string upper_letters[5];

            ifstream fin;
            full = firstname + number + secondname;
            fin.open(full);

            int counter = 0;

            if (fin.is_open())
            {
                string currentLine;

                while (getline(fin, currentLine))
                {
                    counter++;
                }
            }

            if (!fin.is_open())
            {
                cout << "Ошибка открытия файла!" << endl;
            }
            else {
                char ch;

                int i = 0, j = 0;
                bool check = false;
                bool answers = false;
                fin.close();
                fin.open(full);
                while (fin.get(ch))
                {
                    if (isdigit(ch) && answers == true)
                    {
                        is_temp[j] += ch;
                    }
                    else if (isupper(ch) && i >= 1)
                    {
                        upper_letters[i] += ch;

                        //if (temp[i])
                        //{
                            for (int n = 0; n < 10; n++)
                            {
                                if (upper_letters[i] == spl.spells[spl.count_of_spells[n]])
                                {

                                }
                            }
                        //}
                    }

                    if (ch != '>' && ch != '@')
                    {
                        if (ch == '#' || ch == '>')
                        {
                            if (ch == '#')
                            {
                                j++;
                            }

                            continue;
                        }
                        else {
                            if (check == false)
                            {
                                temp[i] += ch;
                                SetColor(7); cout << ch; SetColor(15);
                            }
                            else if (check == true)
                            {
                                temp[i] += ch;
                            }
                        }
                    }
                    else if (ch == '@' || ch == '>')
                    {
                        i++;
                        check = true;
                        answers = true;
                    }
                }
            }
            fin.close();

            int j = 1, is_size = 0, check = 0;
            for (int i = 0; i < 5; i++)
            {
                if (menu_items[i] == "" && temp[j] == "")
                {
                    break;
                }

                menu_items[i] = temp[j];
                j++;
                is_size++;
            }

            if (number != "0" && number != "01" && number != "02" && number != "03" && number != "04" && number != "05" && number != "06")
            {
                ShowInv(&inv, &charac);
                spl.Print();
            }

            check = isMenu(menu_items, is_size, counter);

            for (int i = 0; i < 5; i++)
            {
                if (check == 0)
                {
                    number = is_temp[0];
                    break;
                }
                else if (check == 1)
                {
                    number = is_temp[1];
                    break;
                }
                else if (check == 2)
                {
                    number = is_temp[2];
                    break;
                }
                else if (check == 3)
                {
                    number = is_temp[3];
                    break;
                }
                else if (check == 4)
                {
                    number = is_temp[4];
                    break;
                }
            }
        }
    } break;
    case 1: {
        system("pause");
        //system("cls");
    } break;
    default: {

    } break;
    }
}

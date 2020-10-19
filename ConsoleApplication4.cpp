// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <vector>

bool my_find(const std::vector<int>& v, int i)
{
    const auto v_size = v.size();

    signed int current_number_l = 0;
    signed int current_number_r = signed int(v_size - 1);

    if (v.at(current_number_r) < i || v.at(current_number_l) > i)
    {
        return false;
    }

    for (; current_number_r >= current_number_l;)
    {
        if (v.at(current_number_r) > i && v.at(current_number_l) < i)
        {
            signed int current_middle = current_number_l + (current_number_r - current_number_l) / 2;

            if (i > v.at(current_middle))
            {
                current_number_l = current_middle;
                //current_number_r = current_middle;
            }
            else
            {
                if (i < v.at(current_middle))
                {
                    //current_number_l = current_middle;
                    current_number_r = current_middle;
                }
                else
                {
                    return true;
                }
            }
        }

        if (v.at(current_number_l) == i || v.at(current_number_r) == i)
        {
            return true;
        }

        if (current_number_r == current_number_l)
        {
            break;
        }
    }

    return false;
}

int main()
{
    std::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(11);
    v.push_back(21);
    v.push_back(31);
    v.push_back(32);
    v.push_back(41);
    v.push_back(42);
    v.push_back(51);
    v.push_back(52);

    v.push_back(101);
    v.push_back(102);
    v.push_back(111);
    v.push_back(121);
    v.push_back(131);
    v.push_back(132);
    v.push_back(141);
    v.push_back(142);
    v.push_back(151);
    v.push_back(152);


    std::cout << my_find(v, 0) << std::endl;
    std::cout << my_find(v, 1) << std::endl;

    std::cout << my_find(v, 52) << std::endl;
    std::cout << my_find(v, 101) << std::endl;

    std::cout << my_find(v, 152) << std::endl;
    std::cout << my_find(v, 153) << std::endl;


    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

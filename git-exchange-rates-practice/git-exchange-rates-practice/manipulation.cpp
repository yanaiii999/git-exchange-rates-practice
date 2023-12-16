#include <iostream>

using namespace std;

#include "rates_structures.h"
#include "file_reader.h"
#include "constant.h"
#include <manipulations.h>

void print_data(rates* subscriptions[], int id)
{
    cout << subscriptions[id]->bank << ' ';
    cout << subscriptions[id]->buy_price << ' ';
    cout << subscriptions[id]->sell_price << ' ';
    cout << subscriptions[id]->adress << ' ';
    cout << '\n';
}

void only_Belarusbank(rates* subscriptions[], int size)
{


    for (int i = 0; i < size; i++)
    {
        if (strstr(subscriptions[i]->bank, "Belarusbank") != NULL)
        {
            print_data(subscriptions, i);
        }
    }
}

void low_volume(rates* subscriptions[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (subscriptions[i]->sell_price < 2.5)
        {
            print_data(subscriptions, i);
        }
    }
}
bool SortCase(int sort_id, rates* subscriptions[], int size, int id, int id2)
{
    switch (sort_id)
    {
    case 1:
    {
        if (abs(subscriptions[id]->sell_price - subscriptions[id]->buy_price) < abs(subscriptions[id2]->sell_price - subscriptions[id2]->buy_price))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    case 2:
    {if (strcmp(subscriptions[id]->bank, subscriptions[id2]->bank) < 0)
    {
        return true;
    }
    if (strcmp(subscriptions[id]->bank, subscriptions[id2]->bank) == 0)
    {
        if (strcmp(subscriptions[id]->adress, subscriptions[id2]->adress) < 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (strcmp(subscriptions[id]->bank, subscriptions[id2]->bank) > 0)
    {
        return false;
    }
    }
    }
}
void BubbleSort(rates* subscriptions[], int size, int sort_id) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (SortCase(sort_id, subscriptions, size, j + 1, j))
                swap(subscriptions[j + 1], subscriptions[j]);
        }
    }
    for (int d = 0; d < size; d++)
    {
        print_data(subscriptions, d);
    }
}
  



   

  


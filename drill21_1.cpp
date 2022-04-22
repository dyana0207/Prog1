#include "std_lib_facilities.h"

struct Item
{
    Item() : name(), iid(), value() {}
    Item(string item_name, int item_iid, double item_value) : name(item_name), iid(item_iid), value(item_value) {}
    
    string name;
    int iid;
    double value;
};

istream& operator>>(istream& is, Item& it)
{
    string nn;
    int ii;
    double vv;
    
    is >> nn >> ii >> vv;

    Item read {nn, ii, vv};
    it = read;

    return is;
}

ostream& operator<<(ostream&os, Item& it)
{
    return os << it.name << ' ' << it.iid << ' ' << it.value << '\n';
}

template<typename T>
void print(T& t)
{
    for (auto p = t.begin(); p!= t.end(); ++p)
    {
        cout << *p;
    }
    cout << '\n';
}

int main()
{
    vector<Item> vi;
    ifstream ist {"data.txt"};

    for (Item temp; ist >> temp;) vi.push_back(temp);

    cout << "Adat:" <<endl;
    print(vi);

    string a;
    string b;

    cout << "Name sort\n";
    sort(vi.begin(), vi.end(), [](const Item& a, const Item& b){return a.name < b.name;});
    print(vi);

    cout << "iid sort:\n";
    sort(vi.begin(), vi.end(), [](const Item& a, const Item& b){return a.iid < b.iid;});
    print(vi);

    cout << "value sort (decreasing):\n";
    sort(vi.begin(), vi.end(), [](const Item& a, const Item& b){return a.value > b.value;});
    print(vi);

    Item horse_shoe {"horse shoe", 99, 12.34};
    Item canon_s400 {"Canon S400", 9988, 499.95};

    vi.insert(vi.begin(), horse_shoe);
    vi.insert(vi.begin(), canon_s400);

    cout << "Inserted Items 'horse shoe' and 'Canon S400':\n";
    print(vi);

    string name = "körte";

    cout << "Name 'körte' removed:\n";
    vi.erase(find_if(vi.begin(),vi.end(), [name](const Item& a){return a.name == name;}));
    print(vi);

    int iid = 4;

    cout << "iid '4' removed:\n";
    vi.erase(find_if(vi.begin(), vi.end(), [iid](const Item& a){return a.iid == iid;}));
    print(vi);

    return 0;
}

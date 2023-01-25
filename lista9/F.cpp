#include <iostream>
#include <vector>
#include <algorithm>

struct city
{
    int population;
    int boxes;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int nCities, boxes;
    std::cin >> nCities >> boxes;

    auto cmp = [](const city &l, const city &r)
        {return (l.population + l.boxes - 1) / l.boxes < (r.population + r.boxes - 1) / r.boxes;};

    while (nCities != -1)
    {
        std::vector<city> cities(nCities);
        for (int i = 0; i < nCities; i++)
        {
            std::cin >> cities[i].population;
            cities[i].boxes = 1;
        }
        boxes -= nCities;
        while (boxes > 0)
        {
            auto m = std::max_element(cities.begin(), cities.end(), cmp);
            m->boxes++;
            boxes--;
        }
        auto m = std::max_element(cities.begin(), cities.end(), cmp);
        std::cout << (m->population + m->boxes - 1) / m->boxes << '\n';

        std::cin >> nCities >> boxes;
    }
    
    return 0;
}

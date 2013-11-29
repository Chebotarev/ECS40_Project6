#ifndef SPECIES_H
#define SPECIES_H

class Species
{
public:
    Species();
    ~Species();

    int getPopulation();


private:
    int population;
    int time;
    double birth_rate;

};

#endif // SPECIES_H

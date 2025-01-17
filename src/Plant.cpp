#include "Plant.h"

Plant::Plant()
    : Organism{}, m_regrowCoef{}, m_energyPts{}, m_regrowTimer{}, m_isEaten{} {}
Plant::Plant(int x, int y, char id, int regrowCoef, int energyPts)
    : Organism{x,y,id}, m_regrowCoef{regrowCoef}, m_energyPts{energyPts}, m_regrowTimer{0}, m_isEaten{false} {}

int Plant::getRegrowCoef() const { return m_regrowCoef; }
int Plant::getEnergyPts() const { return m_energyPts; }
int Plant::getRegrowTimer() const { return m_regrowTimer; }
bool Plant::isEaten() const { return m_isEaten; }
void Plant::grow() {
    m_regrowTimer++;
    if (m_regrowTimer>=m_regrowCoef) { //finished growing
        m_regrowTimer = 0;
        m_isEaten = false;
    }
}
void Plant::wasEaten() { m_isEaten = true; }

Plant* Plant::clone() const {
    return new Plant(getX(),getY(),getID(),getRegrowCoef(),getEnergyPts());
}
SpeciesType Plant::getSpeciesType() { return plant; }

bool Plant::isDead() { return false; }
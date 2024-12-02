#include "simulation.hpp"
#include <vector>
#include <utility>

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int value)
{
    grid.SetValue(row, column, value);
}

int Simulation::CountLiveNeighbors(int row, int column)
{
    int liveNeighbors = 0;
    std::vector<std::pair<int, int>> neighborOffsets =
    {
        {-1, 0},  // Cell above
        {1, 0},   // Cell below
        {0, -1},  // Cell to the right
        {0, 1},   // Cell to the left
        {-1, -1}, // Cell diagonal upper left
        {-1, 1},  // Cell diagonal upper right
        {1, -1},  // Cell diagonal lower left
        {1, 1},   // Cell diagonal  lower right
    };

    for(const auto& offset : neighborOffsets)
    {
        int neighborRow = row + offset.first;
        int neighborColumn = column + offset.second;
        liveNeighbors += grid.GetValue(neighborRow, neighborColumn);
    }

    return liveNeighbors;
}

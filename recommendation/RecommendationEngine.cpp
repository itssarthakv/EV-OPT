
#include "RecommendationEngine.h"

#include <algorithm>
#include <cmath>

double RecommendationEngine::calculateDistanceScore(
    double travelTime)
{
    if (travelTime < 0)
        return 0.0;

    return std::max(0.0, 100.0 - travelTime);
}

double RecommendationEngine::calculateWaitingScore(
    double waitingTime)
{
    if (waitingTime < 0)
        return 0.0;

    return std::max(0.0, 100.0 - waitingTime);
}

double RecommendationEngine::calculateAvailabilityScore(
    bool available)
{
    return available ? 100.0 : 0.0;
}

double RecommendationEngine::calculateLoadScore(
    double stationLoad)
{
    stationLoad = std::max(
        0.0,
        std::min(100.0, stationLoad)
    );

    return 100.0 - stationLoad;
}

double RecommendationEngine::calculateCostScore(
    double chargingCost)
{
    if (chargingCost < 0)
        return 0.0;

    return std::max(0.0, 100.0 - chargingCost);
}

double RecommendationEngine::calculateUrgencyScore(
    double travelTime,
    double waitingTime,
    int urgencyLevel)
{
    urgencyLevel = std::max(
        1,
        std::min(5, urgencyLevel)
    );

    double totalDelay = travelTime + waitingTime;

    return std::max(
        0.0,
        100.0 - (totalDelay * urgencyLevel * 2.0)
    );
}

StationRecommendation RecommendationEngine::calculateScore(
    const StationMetrics& station)
{
    StationRecommendation result{};

    result.stationId = station.stationId;
    result.stationName = station.stationName;

    result.distanceScore =
        calculateDistanceScore(station.travelTime);

    result.waitingScore =
        calculateWaitingScore(station.waitingTime);

    result.availabilityScore =
        calculateAvailabilityScore(
            station.chargerAvailable
        );

    result.loadScore =
        calculateLoadScore(station.stationLoad);

    result.costScore =
        calculateCostScore(station.chargingCost);

    result.urgencyScore =
        calculateUrgencyScore(
            station.travelTime,
            station.waitingTime,
            station.urgencyLevel
        );

    result.totalScore =
          result.distanceScore * 0.20
        + result.waitingScore * 0.20
        + result.availabilityScore * 0.15
        + result.loadScore * 0.15
        + result.costScore * 0.15
        + result.urgencyScore * 0.15;

    return result;
}

std::vector<StationRecommendation>
RecommendationEngine::rankStations(
    const std::vector<StationMetrics>& stations)
{
    std::vector<StationRecommendation> results;

    for (const StationMetrics& station : stations)
    {
        if (!station.chargerAvailable)
            continue;

        results.push_back(calculateScore(station));
    }

    std::sort(
        results.begin(),
        results.end(),
        [](const StationRecommendation& a,
           const StationRecommendation& b)
        {
            if (a.totalScore != b.totalScore)
                return a.totalScore > b.totalScore;
            return a.stationId < b.stationId;
        }
    );

    return results;
}


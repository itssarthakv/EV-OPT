
#include "RecommendationEngine.h"

#include <algorithm>
#include <cmath>

// 1. Calculate score based on travel time.
// Less travel time = higher score.
double RecommendationEngine::calculateDistanceScore(
    double travelTime)
{
    if (travelTime < 0)
        return 0.0;

    return std::max(0.0, 100.0 - travelTime);
}

// 2. Calculate score based on waiting time.
// Less waiting time = higher score.
double RecommendationEngine::calculateWaitingScore(
    double waitingTime)
{
    if (waitingTime < 0)
        return 0.0;

    return std::max(0.0, 100.0 - waitingTime);
}

// 3. Check charger availability.
double RecommendationEngine::calculateAvailabilityScore(
    bool available)
{
    return available ? 100.0 : 0.0;
}

// 4. Calculate score based on station load.
// Lower load = higher score.
// stationLoad is expected to be between 0 and 100.
double RecommendationEngine::calculateLoadScore(
    double stationLoad)
{
    stationLoad = std::max(
        0.0,
        std::min(100.0, stationLoad)
    );

    return 100.0 - stationLoad;
}

// 5. Calculate score based on charging cost.
// Lower cost = higher score.
double RecommendationEngine::calculateCostScore(
    double chargingCost)
{
    if (chargingCost < 0)
        return 0.0;

    return std::max(0.0, 100.0 - chargingCost);
}

// 6. Calculate urgency score.
// Urgent EVs are penalized more for long delays,
// so lower travel and waiting times are preferred.
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

// Calculate the overall score for one station.
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

    // Weighted total: all weights add up to 1.00 (100%).
    result.totalScore =
          result.distanceScore * 0.20
        + result.waitingScore * 0.20
        + result.availabilityScore * 0.15
        + result.loadScore * 0.15
        + result.costScore * 0.15
        + result.urgencyScore * 0.15;

    return result;
}

// Rank stations from highest score to lowest score.
std::vector<StationRecommendation>
RecommendationEngine::rankStations(
    const std::vector<StationMetrics>& stations)
{
    std::vector<StationRecommendation> results;

    for (const StationMetrics& station : stations)
    {
        // A station without an available charger
        // is not eligible for recommendation.
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

            // If scores tie, use station ID for consistency.
            return a.stationId < b.stationId;
        }
    );

    return results;
}


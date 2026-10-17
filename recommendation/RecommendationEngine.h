
#ifndef RECOMMENDATION_ENGINE_H
#define RECOMMENDATION_ENGINE_H

#include <string>
#include <vector>

struct StationMetrics
{
    int stationId;
    std::string stationName;

    double travelTime;
    double waitingTime;

    bool chargerAvailable;
    double stationLoad;
    double chargingCost;

    int urgencyLevel;
};

struct StationRecommendation
{
    int stationId;
    std::string stationName;

    double distanceScore;
    double waitingScore;
    double availabilityScore;
    double loadScore;
    double costScore;
    double urgencyScore;

    double totalScore;
};

class RecommendationEngine
{
private:
    double calculateDistanceScore(double travelTime);
    double calculateWaitingScore(double waitingTime);
    double calculateAvailabilityScore(bool available);
    double calculateLoadScore(double stationLoad);
    double calculateCostScore(double chargingCost);
    double calculateUrgencyScore(
        double travelTime,
        double waitingTime,
        int urgencyLevel
    );

public:
    StationRecommendation calculateScore(
        const StationMetrics& station
    );

    std::vector<StationRecommendation> rankStations(
        const std::vector<StationMetrics>& stations
    );
};

#endif



# EV-OPT Recommendation Engine — Scoring Logic

## 1. Objective

The Recommendation Engine evaluates eligible EV charging
stations and ranks them according to a weighted scoring system.

The station with the highest total score is recommended.

The nearest station is not always the best choice. Travel time,
waiting time, charger availability, station load, charging cost,
and EV urgency are considered before making a recommendation.

## 2. Recommendation Factors and Weights

| Factor | Weight | Preferred Condition |
|---|---:|---|
| Travel Time | 20% | Lower travel time |
| Waiting Time | 20% | Lower waiting time |
| Charger Availability | 15% | Charger is available |
| Station Load | 15% | Lower station load |
| Charging Cost | 15% | Lower estimated cost |
| Urgency Score | 15% | Less delay for urgent EVs |
| Total | 100% | Highest score wins |

## 3. Scoring Method

Each factor contributes to an overall score using a weighted sum.

Total Score =

(Travel Time Score × 0.20) +

(Waiting Time Score × 0.20) +

(Availability Score × 0.15) +

(Load Score × 0.15) +

(Cost Score × 0.15) +

(Urgency Score × 0.15)

Each individual score is intended to range from 0 to 100.
The maximum possible total score is 100.

## 4. Individual Factor Rules

### 4.1 Travel Time Score

Stations with shorter travel times receive higher scores.

The current implementation uses:

Travel Time Score = max(0, 100 - Travel Time)

This is a simplified formula and assumes travel time is
expressed on a suitable scale.

### 4.2 Waiting Time Score

Stations with shorter waiting times receive higher scores.

Waiting Time Score = max(0, 100 - Waiting Time)

The formula is illustrative and should be calibrated to the
units and expected range of waiting time.

### 4.3 Charger Availability Score

- Available charger: 100 points
- Unavailable charger: 0 points

Stations without an available charger are excluded before
ranking, so unavailable stations are not recommended.

### 4.4 Station Load Score

Station load represents the percentage of station capacity
currently in use, from 0 to 100.

Load Score = 100 - Station Load

A less-loaded station receives a higher score.

### 4.5 Charging Cost Score

Stations with lower estimated charging costs receive higher
scores.

The current implementation uses:

Cost Score = max(0, 100 - Charging Cost)

This simplified formula requires calibration against the
actual cost units and expected price range.

### 4.6 Urgency Score

The urgency level ranges from 1 to 5.

The current implementation calculates a delay-based score:

Total Delay = Travel Time + Waiting Time

Urgency Score = max(0, 100 - (Total Delay × Urgency Level × 2))

A longer delay reduces the score more strongly for higher
urgency levels. This formula is a preliminary approach and
can be improved to prioritize urgent EVs more explicitly.

## 5. Station Eligibility

Before ranking, the engine checks whether a station has an
available charger.

- Eligible stations are scored and ranked.
- Stations without an available charger are excluded.
- Future integration can check connector compatibility,
  charging power, and other EV charging requirements.

## 6. Ranking Algorithm

1. Receive the list of candidate stations.
2. Exclude stations without available chargers.
3. Calculate the six factor scores for each eligible station.
4. Calculate the weighted total score.
5. Sort stations in descending order of total score.
6. Recommend the highest-scoring station.

If two stations have the same total score, the station with
the lower station ID is placed first.

## 7. Assumptions and Limitations

- The current formulas are starter formulas, not calibrated
  real-world prediction models.
- Travel time and waiting time must use consistent units.
- Charging cost must use a defined currency and cost basis.
- Station load is represented as a percentage from 0 to 100.
- Urgency level is represented by an integer from 1 to 5.
- The current implementation does not calculate live traffic,
  real-time tariffs, or actual station waiting times.
- Integration with the EV-OPT scheduler and actual station
  data is required for a complete working recommendation flow.

## 8. Future Improvements

- Normalize travel time, waiting time, and charging cost
  against realistic minimum and maximum values.
- Give urgent EV requests higher priority through urgency-aware
  weights or a clearly defined priority adjustment.
- Integrate real-time charger status and station occupancy.
- Consider connector compatibility and charging power.
- Test the algorithm with sample stations and compare rankings.

## 9. Conclusion

The Recommendation Engine uses multiple factors rather than
distance alone to rank charging stations.

Its goal is to recommend a suitable station by balancing
travel time, waiting time, availability, station load, cost,
and urgency.


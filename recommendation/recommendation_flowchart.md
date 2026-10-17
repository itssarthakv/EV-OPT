
# EV-OPT Recommendation Flowchart

## Recommendation Process

```mermaid
flowchart TD
    A([Start]) --> B[Receive EV charging request]
    B --> C[Collect candidate stations]
    C --> D[Check charger availability]
    D --> E{Any eligible stations?}

    E -- No --> F[Return no eligible station]
    E -- Yes --> G[Calculate travel time score]
    G --> H[Calculate waiting time score]
    H --> I[Calculate availability score]
    I --> J[Calculate station load score]
    J --> K[Calculate charging cost score]
    K --> L[Calculate urgency score]

    L --> M[Calculate weighted total score]
    M --> N[Sort stations by total score]
    N --> O[Recommend highest-scoring station]

    F --> P([End])
    O --> P
```

## Explanation

1. The engine receives an EV charging request.
2. Candidate charging stations are collected.
3. Stations without available chargers are excluded.
4. The engine calculates scores using six recommendation factors.
5. A weighted total score is calculated for each eligible station.
6. Stations are sorted from highest score to lowest score.
7. The highest-scoring station is recommended.

## Important Note

The current scoring formulas use simplified assumptions.
Real-world integration requires suitable travel-time,
waiting-time, charging-cost, and station-load data.

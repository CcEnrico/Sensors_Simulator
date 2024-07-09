#!/bin/bash

# BASE_DIR="base dir"

# Define the data directory
DATA_DIR="$BASE_DIR/data"

# API_KEY= your token

CITIES=(
  "Roma:41.8947:12.4839" 
  "Milano:45.4643:9.1895" 
  "Napoli:40.8333:14.25" 
  "Torino:45.1333:7.3667" 
  "Palermo:37.8167:13.5833" 
  "Genova:44.5:9.0667" 
  "Bologna:44.4667:11.4333" 
  "Firenze:43.7667:11.25" 
  "Bari:41.1177:16.8512" 
  "Catania:37.5021:15.0872" 
  "Venezia:45.4386:12.3267" 
  "Verona:45.4167:11.0333" 
  "Messina:38.1933:15.5497" 
  "Padova:45.4152:11.8818" 
  "Trieste:45.6486:13.78" 
  "Taranto:40.6167:17.25"  
  "Brescia:45.6333:10.3" 
  "Parma:44.8027:10.329"
  "Prato:43.8843:11.0909" 
  "Modena:44.5:10.9"  
)


for city_info in "${CITIES[@]}"; do
    IFS=':' read -r CITY LAT LON <<< "$city_info"

    weather_data=$(curl -s "http://api.openweathermap.org/data/2.5/weather?q=${CITY}&appid=${API_KEY}")
    if [ -z "$weather_data" ]; then
        echo "Failed to fetch weather data for $CITY"
        continue
    fi

    timestamp=$(echo $weather_data | jq -r '.dt')
    if [ -z "$timestamp" ]; then
        echo "Failed to extract timestamp for $CITY"
        continue
    fi

    pollution_data=$(curl -s "http://api.openweathermap.org/data/2.5/air_pollution?lat=${LAT}&lon=${LON}&appid=${API_KEY}")
    if [ -z "$pollution_data" ]; then
        echo "Failed to fetch pollution data for $CITY"
        continue
    fi

    combined_data=$(jq -n --argjson weather "$weather_data" --argjson pollution "$pollution_data" \
                    '{weather: $weather, pollution: $pollution}')
    
    filename="$DATA_DIR/${CITY}_$(date -d @$timestamp +'%Y-%m-%d_%H-%M-%S').json"
    
    echo $combined_data | jq . > "$filename"

    echo "Data saved to $filename"
done


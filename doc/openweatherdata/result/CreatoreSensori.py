import json
import os
import argparse
import glob

file_pattern = '*_stats_results.json'
file_dati_list = glob.glob(file_pattern)

def genera_sensori(file_dati):
    city_name = os.path.basename(file_dati).split('_')[0]

    with open(file_dati) as f:
        dati = json.load(f)

    sensori = [
        {
            "Initial Temperature K°": dati['temperature_mean'],
            "Simulation Scale": "k",
            "dataNumber": 100,
            "id": 1,
            "initial Maximum Temp K°": dati['temp_max_mean'],
            "initial Minimum Temp K°": dati['temp_min_mean'],
            "name": f"{city_name}_Temp",
            "standardDeviation Temp K°": dati['temperature_std_dev'],
            "Collection per day": 24,
            "type": "temperature_sensor"
        },
        {
            "Rain Probability": dati["rain_probability"],
            "dataNumber": 100,
            "id": 2,
            "initial Relative Humidity": dati["humidity_mean"],
            "name": f"{city_name}_Hum",
            "standardDeviation Relative Humidity": dati["humidity_std_dev"],
            "type": "humidity_sensor"
        },
        {
            "dataNumber": 100,
            "id": 3,
            "initialN02 micro_g/m3": dati["no2_mean"],
            "initialPm10 micro_g/m3": dati["pm10_mean"],
            "name": f"{city_name}_AQ",
            "standardDeviationN02 micro_g/m3": dati["no2_std_dev"],
            "standardDeviationPm10 micro_g/m3": dati["pm10_std_dev"],
            "type": "air_quality_sensor"
        }
    ]





    os.makedirs('sensori', exist_ok=True)

    output_file = f'sensori/{city_name}.json'
    with open(output_file, 'w') as f:
        json.dump(sensori, f, indent=4, ensure_ascii=False)

    print(f"File {output_file} generato correttamente.")

for file_dati in file_dati_list:
    genera_sensori(file_dati)

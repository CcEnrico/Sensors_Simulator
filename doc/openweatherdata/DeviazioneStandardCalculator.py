import os
import json
import numpy as np

directory = './data'  # path dati
city_list = ['Roma',
             'Milano', 
             'Napoli', 
             'Torino', 
             'Palermo', 
             'Genova', 
             'Bologna',
             'Firenze', 
             'Bari', 
             'Catania', 
             'Venezia', 
             'Verona', 
             'Messina', 
             'Padova', 
             'Trieste', 
             'Taranto', 
             'Brescia', 
             'Parma', 
             'Prato', 
             'Modena' 
             ]

result_directory = 'result/'

if not os.path.exists(result_directory):
    os.makedirs(result_directory)

for city in city_list:
    temperatures = []
    temp_mins = []
    temp_maxs = []
    humidity_values = []
    rain_probabilities = []
    no2_values = []
    pm10_values = []

    for filename in os.listdir(directory):
        if filename.endswith('.json') and city in filename:
            with open(os.path.join(directory, filename), 'r') as file:
                data = json.load(file)

                weather = data['weather']['main']
                pollution = data['pollution']['list'][0]['components']

                temperature = weather['temp']
                temp_min = weather['temp_min']
                temp_max = weather['temp_max']
                humidity = weather['humidity']

                temperatures.append(temperature)
                temp_mins.append(temp_min)
                temp_maxs.append(temp_max)
                humidity_values.append(humidity)

                rain = data['weather'].get('rain', {}).get('1h', 0)
                rain_probabilities.append(1 if rain > 0 else 0)

                no2 = pollution['no2']
                pm10 = pollution['pm10']
                no2_values.append(no2)
                pm10_values.append(pm10)

    temperature_mean = np.mean(temperatures)
    temp_min_mean = np.mean(temp_mins)
    temp_max_mean = np.mean(temp_maxs)
    humidity_mean = np.mean(humidity_values)
    rain_probability = np.mean(rain_probabilities)
    no2_mean = np.mean(no2_values)
    pm10_mean = np.mean(pm10_values)

    temperature_std_dev = np.std(temperatures)
    temp_min_std_dev = np.std(temp_mins)
    temp_max_std_dev = np.std(temp_maxs)
    humidity_std_dev = np.std(humidity_values)
    no2_std_dev = np.std(no2_values)
    pm10_std_dev = np.std(pm10_values)

    result = {
        'temperature_mean': temperature_mean,
        'temp_min_mean': temp_min_mean,
        'temp_max_mean': temp_max_mean,
        'humidity_mean': humidity_mean,
        'rain_probability': rain_probability,
        'no2_mean': no2_mean,
        'pm10_mean': pm10_mean,
        'temperature_std_dev': temperature_std_dev,
        'temp_min_std_dev': temp_min_std_dev,
        'temp_max_std_dev': temp_max_std_dev,
        'humidity_std_dev': humidity_std_dev,
        'no2_std_dev': no2_std_dev,
        'pm10_std_dev': pm10_std_dev
    }

    output_filename = os.path.join(result_directory, city + '_stats_results.json')
    with open(output_filename, 'w') as json_file:
        json.dump(result, json_file, indent=4)

    print(f"Statistics saved to {output_filename}")

#include "Full.h"

#include "QtWidgets/QLabel"
#include "QtWidgets/QVBoxLayout"
#include "QtWidgets/QHBoxLayout"
#include "QtGui/QPixmap"
#include "QtWidgets/QPushButton"
#include "QtWidgets/QGroupBox"
#include <QComboBox>

#include "QtCharts/QChart"
#include "QtCharts/QChartView"
#include "QtCharts/QLineSeries"

#include "Sensor/Airqualitysensor.h"
#include "Sensor/Humiditysensor.h"
#include "Sensor/TemperatureSensor.h"


namespace View::GraphRenderer {

    Full::Full(){
    }

    void Full::visit(const Sensor::AirQualitySensor& air_quality){
        widget = new QWidget();
        QGridLayout* grid = new QGridLayout();

        QWidget* first = new QWidget();
        QVBoxLayout* first_column = new QVBoxLayout();
        QLabel* type = new QLabel("AIR QUALITY SENSOR");
        name = new QLabel("Name: " + QString::fromStdString(air_quality.getName()));
        id = new QLabel("ID: " + QString::number(air_quality.getIdentifier()));
        data_num = new QLabel("Data Num: " + QString::number(air_quality.getDataNum()));
        variance = new QLabel("Variance: " + QString::number(air_quality.getVariance()));
        first_column->addWidget(type);
        first_column->addWidget(name);
        first_column->addWidget(id);
        first_column->addWidget(data_num);
        first_column->addWidget(variance);
        first->setLayout(first_column);


        QWidget* second = new QWidget();
        QVBoxLayout* second_column = new QVBoxLayout();
        QLabel* initial_pm_10 = new QLabel("Initial PM10: " + QString::number(air_quality.getInitialPm10()));
        QLabel* initial_n02 = new QLabel("Initial NO2: " + QString::number(air_quality.getInitialNO2()));
        QLabel* std_dev_pm_10 = new QLabel("Standard Deviation PM10: " + QString::number(air_quality.getStdDeviationPm10()));
        QLabel* std_dev_n02 = new QLabel("Standard Deviation NO2: " + QString::number(air_quality.getStdDeviationNO2()));
        QLabel* target_pm_10 = new QLabel("Target PM10: " + QString::number(air_quality.getTargetPm10()));
        QLabel* target_n02 = new QLabel("Target NO2: " + QString::number(air_quality.getTargetNO2()));
        second_column->addWidget(initial_pm_10);
        second_column->addWidget(initial_n02);
        second_column->addWidget(std_dev_pm_10);
        second_column->addWidget(std_dev_n02);
        second_column->addWidget(target_pm_10);
        second_column->addWidget(target_n02);
        second->setLayout(second_column);

        QWidget* third = new QWidget();
        QVBoxLayout* third_column = new QVBoxLayout();
        simulate_button = new QPushButton("Simulate");
        edit_button = new QPushButton("Edit");
        clear_button = new QPushButton("Clear"); 
        third_column->addWidget(simulate_button);
        third_column->addWidget(edit_button);
        third_column->addWidget(clear_button);
        third->setLayout(third_column);


        chart = new QChart();

        axisX = new QValueAxis();
        axisX->setTitleText("Data Num");
        axisX->setRange(0, 100);
        chart->addAxis(axisX, Qt::AlignBottom);
        axisY = new QValueAxis();
        axisY->setRange(0, 100);
        chart->addAxis(axisY, Qt::AlignLeft);

        view_chart = new QChartView(chart);
        view_chart->setRenderHint(QPainter::Antialiasing);


        grid->addWidget(first, 0, 0);
        grid->addWidget(second, 0, 1);
        grid->addWidget(third, 0, 2);
        grid->addWidget(view_chart, 1, 0, 1, 3);

        widget->setLayout(grid);
    }
    void Full::visit(const Sensor::HumiditySensor& humidity){
        widget = new QWidget();
        QGridLayout* grid = new QGridLayout();

        QWidget* first = new QWidget();
        QVBoxLayout* first_column = new QVBoxLayout();
        QLabel* type = new QLabel("HUMIDITY SENSOR");
        name = new QLabel("Name: " + QString::fromStdString(humidity.getName()));
        id = new QLabel("ID: " + QString::number(humidity.getIdentifier()));
        data_num = new QLabel("Data Num: " + QString::number(humidity.getDataNum()));
        variance = new QLabel("Variance: " + QString::number(humidity.getVariance()));
        first_column->addWidget(type);
        first_column->addWidget(name);
        first_column->addWidget(id);
        first_column->addWidget(data_num);
        first_column->addWidget(variance);
        first->setLayout(first_column);


        QWidget* second = new QWidget();
        QVBoxLayout* second_column = new QVBoxLayout();
        QLabel* initial = new QLabel("Initial: " + QString::number(double(humidity.getHumInitial())) + "%");
        QLabel* std_dev = new QLabel("Standard Deviation: " + QString::number(double(humidity.getHumStdDeviation()))+ "%");
        QLabel* target = new QLabel("Rain Probability: " + QString::number(double(humidity.getRainProbability()))+ "%");
        second_column->addWidget(initial);
        second_column->addWidget(std_dev);
        second_column->addWidget(target);
        second->setLayout(second_column);

        QWidget* third = new QWidget();
        QVBoxLayout* third_column = new QVBoxLayout();
        simulate_button = new QPushButton("Simulate");
        edit_button = new QPushButton("Edit");
        clear_button = new QPushButton("Clear");
        third_column->addWidget(simulate_button);
        third_column->addWidget(edit_button);
        third_column->addWidget(clear_button);
        third->setLayout(third_column);


        chart = new QChart();

        axisX = new QValueAxis();
        axisX->setTitleText("Data Num");
        axisX->setRange(0, 100);
        chart->addAxis(axisX, Qt::AlignBottom);
        axisY = new QValueAxis();
        axisY->setRange(0, 100);
        chart->addAxis(axisY, Qt::AlignLeft);

        view_chart = new QChartView(chart);
        view_chart->setRenderHint(QPainter::Antialiasing);


        grid->addWidget(first, 0, 0);
        grid->addWidget(second, 0, 1);
        grid->addWidget(third, 0, 2);
        grid->addWidget(view_chart, 1, 0, 1, 3);

        widget->setLayout(grid);

    }
    void Full::visit(const Sensor::TemperatureSensor& temperature) {
        widget = new QWidget();
        QGridLayout *grid = new QGridLayout();

        QWidget *first = new QWidget();
        QVBoxLayout *first_column = new QVBoxLayout();
        QLabel *type = new QLabel("TEMPERATURE SENSOR");
        name = new QLabel("Name: " + QString::fromStdString(temperature.getName()));
        id = new QLabel("ID: " + QString::number(temperature.getIdentifier()));
        data_num = new QLabel("Data Num: " + QString::number(temperature.getDataNum()));
        variance = new QLabel("Variance: " + QString::number(temperature.getVariance()));
        first_column->addWidget(type);
        first_column->addWidget(name);
        first_column->addWidget(id);
        first_column->addWidget(data_num);
        first_column->addWidget(variance);
        first->setLayout(first_column);


        QWidget *second = new QWidget();
        QVBoxLayout *second_column = new QVBoxLayout();
        QLabel *min = new QLabel("Min: " + QString::number(temperature.getTempMin().getCelsius()) + "C° = " + QString::number(temperature.getTempMin().getFahrenheit()) + "F = " + QString::number(temperature.getTempMin().getKelvin()) + "K");
        QLabel *max = new QLabel("Max: " + QString::number(temperature.getTempMax().getCelsius()) + "C° = " + QString::number(temperature.getTempMax().getFahrenheit()) + "F = " + QString::number(temperature.getTempMax().getKelvin()) + "K");
        QLabel *initial = new QLabel("Initial: " + QString::number(temperature.getTempInitial().getCelsius()) + "C° = " + QString::number(temperature.getTempInitial().getFahrenheit()) + "F = " + QString::number(temperature.getTempInitial().getKelvin()) + "K");
        QLabel *std_dev = new QLabel("Standard Deviation: " + QString::number(temperature.getStdDeviation().getCelsius()) + "C° = " + QString::number(temperature.getStdDeviation().getFahrenheit()) + "F = " + QString::number(temperature.getStdDeviation().getKelvin()) + "K");
        QLabel *target = new QLabel("Target: " + QString::number(temperature.getTempTarget().getCelsius()) + "C° = " + QString::number(temperature.getTempTarget().getFahrenheit()) + "F = " + QString::number(temperature.getTempTarget().getKelvin()) + "K");
        min->setAlignment(Qt::AlignRight);
        max->setAlignment(Qt::AlignRight);
        initial->setAlignment(Qt::AlignRight);
        std_dev->setAlignment(Qt::AlignRight);
        target->setAlignment(Qt::AlignRight);
        second_column->addWidget(min);
        second_column->addWidget(max);
        second_column->addWidget(initial);
        second_column->addWidget(std_dev);
        second_column->addWidget(target);
        second->setLayout(second_column);

        QWidget *third = new QWidget();
        QVBoxLayout *third_column = new QVBoxLayout();
        simulate_button = new QPushButton("Simulate");
        edit_button = new QPushButton("Edit");
        clear_button = new QPushButton("Clear");
        third_column->addWidget(simulate_button);
        third_column->addWidget(edit_button);
        third_column->addWidget(clear_button);
        third->setLayout(third_column);


        chart = new QChart();

        axisX = new QValueAxis();
        axisX->setTitleText("Data Num");
        axisX->setRange(0, 100);
        chart->addAxis(axisX, Qt::AlignBottom);
        axisY = new QValueAxis();
        axisY->setRange(0, 100);
        chart->addAxis(axisY, Qt::AlignLeft);

        view_chart = new QChartView(chart);
        view_chart->setRenderHint(QPainter::Antialiasing);


        grid->addWidget(first, 0, 0);
        grid->addWidget(second, 0, 1);
        grid->addWidget(third, 0, 2);
        grid->addWidget(view_chart, 1, 0, 1, 3);

        widget->setLayout(grid);

    }


    QWidget* Full::getWidget() const{
        return widget;
    }
    QLabel* Full::getId()const{
        return id;
    }
    QLabel* Full::getName()const{
        return name;
    }
    QLabel* Full::getDataNum()const{
        return data_num;
    }
    QLabel* Full::getVariance()const{
        return variance;
    }
    QPushButton* Full::getSimulateButton() const{
        return simulate_button;
    }
    QPushButton* Full::getEditButton() const{
        return edit_button;
    }
    QPushButton* Full::getClearButton() const {
        return clear_button;
    }
    QChart* Full::getChart() const{
        return chart;
    }
    QValueAxis* Full::getXAxis(){
        return axisX;
    }
    QValueAxis* Full::getYAxis(){
        return axisY;
    }
    QChartView* Full::getChartView() const{
        return view_chart;
    }

}

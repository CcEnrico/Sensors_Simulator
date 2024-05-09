#include "SimulationVisitor.h"

#include "Sensor/Airqualitysensor.h"
#include "Sensor/Humiditysensor.h"
#include "Sensor/TemperatureSensor.h"


#include <vector>
#include <QLineSeries>
#include <QBarSet>
#include <QStackedBarSeries>
#include <QLegendMarker>



namespace View::GraphRenderer{

    SimulationVisitor::SimulationVisitor() {}

    void SimulationVisitor::visit(Sensor::AirQualitySensor& air_quality) {

        std::vector<double> pm10_data = air_quality.getAQDataPm10();
        std::vector<double> n02_data = air_quality.getAQDataN02();
        std::vector<double> IAQ_data = air_quality.getAQDataIAQ();
        double optimal = Sensor::AirQualitySensor::optimal.getIndexAQ();
        double good = Sensor::AirQualitySensor::good.getIndexAQ();
        double acceptable = Sensor::AirQualitySensor::acceptable.getIndexAQ();
        double mediocre = Sensor::AirQualitySensor::mediocre.getIndexAQ();
        double poor = Sensor::AirQualitySensor::poor.getIndexAQ();
        double veryBad = Sensor::AirQualitySensor::veryBad.getIndexAQ();

        double max = 0;
        unsigned int it_max;

        QLineSeries* series_pm10 = new QLineSeries();
        unsigned int i = 0;
        for (auto it = pm10_data.begin(); it != pm10_data.end(); ++it) {
            series_pm10->append(i, *it);
            if (max < *it) max = *it;
            i++;
        }

        QLineSeries* series_n02 = new QLineSeries();
        unsigned int j = 0;
        for (auto it = n02_data.begin(); it != n02_data.end(); ++it) {
            series_n02->append(j, *it);
            if (max < *it) max = *it;
            j++;
        }
        QLineSeries* series_IAQ = new QLineSeries();
        unsigned int k = 0;
        for (auto it = IAQ_data.begin(); it != IAQ_data.end(); ++it) {
            series_IAQ->append(k, *it);
            if (max < *it) max = *it;
            k++;
        }
        if(i > j) it_max = i;
        else{it_max = j; }

        QLineSeries *optimal_line = new QLineSeries();
        optimal_line->append(0, optimal);
        optimal_line->append(it_max, optimal);
        QLineSeries *good_line = new QLineSeries();
        good_line->append(0, good);
        good_line->append(it_max, good);
        QLineSeries *acceptable_line = new QLineSeries();
        acceptable_line->append(0, acceptable);
        acceptable_line->append(it_max, acceptable);
        QLineSeries *mediocre_line = new QLineSeries();
        mediocre_line->append(0, mediocre);
        mediocre_line->append(it_max, mediocre);
        QLineSeries *poor_line = new QLineSeries();
        poor_line->append(0, poor);
        poor_line->append(it_max, poor);
        QLineSeries *very_bad_line = new QLineSeries();
        very_bad_line->append(0, veryBad);
        very_bad_line->append(it_max, veryBad);

        chart->addSeries(optimal_line);
        chart->addSeries(good_line);
        chart->addSeries(acceptable_line);
        chart->addSeries(mediocre_line);
        chart->addSeries(poor_line);
        chart->addSeries(very_bad_line);

        chart->addSeries(series_pm10);
        chart->addSeries(series_n02);
        chart->addSeries(series_IAQ);

        optimal_line->attachAxis(axisX);
        optimal_line->attachAxis(axisY);
        good_line->attachAxis(axisX);
        good_line->attachAxis(axisY);
        acceptable_line->attachAxis(axisX);
        acceptable_line->attachAxis(axisY);
        mediocre_line->attachAxis(axisX);
        mediocre_line->attachAxis(axisY);
        poor_line->attachAxis(axisX);
        poor_line->attachAxis(axisY);
        very_bad_line->attachAxis(axisX);
        very_bad_line->attachAxis(axisY);

        series_pm10->attachAxis(axisX);
        series_pm10->attachAxis(axisY);
        series_n02->attachAxis(axisX);
        series_n02->attachAxis(axisY);
        series_IAQ->attachAxis(axisX);
        series_IAQ->attachAxis(axisY);

//        cerca max valore su cui fare la setRange
        qreal maxX = 0;
        qreal maxY = 0;
        for (QAbstractSeries *series : chart->series()) {
            QLineSeries *lineSeries = dynamic_cast<QLineSeries*>(series);
            if (lineSeries != nullptr){
                for (QPointF point : lineSeries->points()) {
                    maxX = qMax(maxX, point.x());
                    maxY = qMax(maxY, point.y());
                }
            }
        }

        axisX->setRange(0, maxX);
        axisY->setRange(0, maxY);

//        display e stili:

        optimal_line->setName("Optimal");
        good_line->setName("Good");
        acceptable_line->setName("Acceptable");
        mediocre_line->setName("Mediocre");
        poor_line->setName("Poor");
        very_bad_line->setName("Very Bad");

        series_pm10->setName("PM10 micro_g/m3");
        series_n02->setName("NQO2 micro_g/m3");
        series_IAQ->setName("IAQ");

        axisY->setTitleText("Air Quality");

        QColor blueColor = QColor(0, 0, 255);
        QColor skyBlueColor = QColor(135, 206, 235);
        QColor greenColor = QColor(0, 255, 0);
        QColor yellowColor = QColor(255, 255, 0);
        QColor redColor = QColor(255, 0, 0);
        QColor darkRedColor = QColor(139, 0, 0);

        QPen optimal_pen;
        optimal_pen.setColor(blueColor);
        optimal_pen.setStyle(Qt::DashLine);
        optimal_line->setPen(optimal_pen);

        QPen good_pen;
        good_pen.setColor(skyBlueColor);
        good_pen.setStyle(Qt::DashLine);
        good_line->setPen(good_pen);

        QPen acceptable_pen;
        acceptable_pen.setColor(greenColor);
        acceptable_pen.setStyle(Qt::DashLine);
        acceptable_line->setPen(acceptable_pen);

        QPen mediocre_pen;
        mediocre_pen.setColor(yellowColor);
        mediocre_pen.setStyle(Qt::DashLine);
        mediocre_line->setPen(mediocre_pen);

        QPen poor_pen;
        poor_pen.setColor(redColor);
        poor_pen.setStyle(Qt::DashLine);
        poor_line->setPen(poor_pen);

        QPen very_bad_pen;
        very_bad_pen.setColor(darkRedColor);
        very_bad_pen.setStyle(Qt::DashLine);
        very_bad_line->setPen(very_bad_pen);


        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignRight);
        chart->setAnimationOptions(QChart::SeriesAnimations);

    }
    void SimulationVisitor::visit(Sensor::HumiditySensor& humidity) {

        std::vector<double> hum_data = humidity.getHumData();
        std::vector<unsigned int> rains = humidity.getWeatherRainy();
        double max = Sensor::HumiditySensor::max.getRelativeHumidity();
        double min = Sensor::HumiditySensor::min.getRelativeHumidity();

        QLineSeries* series = new QLineSeries();
        unsigned int i = 0;
        for (auto it = hum_data.begin(); it != hum_data.end(); ++it) {
            series->append(i, *it);
            if ( min > *it ) min = *it;
            i++;
        }
        chart->addSeries(series);
        series->attachAxis(axisX);
        series->attachAxis(axisY);

        series->setName("Humidity %");

        unsigned int j = 0;
        for (auto it = rains.begin(); it != rains.end(); ++it) {
            if (j % 2 == 0){ // inizio pioggia
                QLineSeries* rain_start = new QLineSeries();
                rain_start->append(*it, min);
                rain_start->append(*it, max);
                chart->addSeries(rain_start);

                rain_start->attachAxis(axisX);
                rain_start->attachAxis(axisY);

                QPen rain_start_pen;
                rain_start_pen.setColor(QColor(0, 0, 255));
                rain_start_pen.setStyle(Qt::DashLine);
                rain_start->setPen(rain_start_pen);

                rain_start->setName("Rain start");
            }else{  //fine pioggia
                QLineSeries* rain_end = new QLineSeries();
                rain_end->append(*it, min);
                rain_end->append(*it, max);
                chart->addSeries(rain_end);

                rain_end->attachAxis(axisX);
                rain_end->attachAxis(axisY);

                QPen rain_end_pen;
                rain_end_pen.setColor(QColor(0, 255, 0));
                rain_end_pen.setStyle(Qt::DashLine);
                rain_end->setPen(rain_end_pen);

                rain_end->setName("Rain end");
            }
            j++;
        }

        axisX->setRange(0, i);
        axisY->setRange(0, 100);

        int count = 0;
        for (QLegendMarker* marker : chart->legend()->markers()) {
            marker->setVisible(count < 3);
            count++;
        }

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignRight);
        chart->setAnimationOptions(QChart::SeriesAnimations);

    }
    void SimulationVisitor::visit(Sensor::TemperatureSensor& temperature) {

        std::vector<double> min_data = temperature.getTempDataMin();
        std::vector<double> max_data = temperature.getTempDataMax();
        std::vector<double> mean_data = temperature.getTempDataMean();
        double max = 0;
        double min = 0;

        if (temperature.getDataNum() < 200){

            auto low = new QBarSet("Min");
            auto high = new QBarSet("Max");

            for (auto it = min_data.begin(); it != min_data.end(); ++it) {
                *low << *it;
                if ( min > *it ) min = *it;
            }

            for (auto it = max_data.begin(); it != max_data.end(); ++it) {
                *high << *it;
                if ( max < *it ) max = *it;
            }

            auto series = new QStackedBarSeries;
            series->append(low);
            series->append(high);

            chart->addSeries(series);
            series->attachAxis(axisX);
            series->attachAxis(axisY);
        }else{
            QLineSeries* series_min = new QLineSeries();
            unsigned int i = 0;
            for (auto it = min_data.begin(); it != min_data.end(); ++it) {
                series_min->append(i, *it);
                if ( min > *it ) min = *it;
                i++;
            }
            QLineSeries* series_max = new QLineSeries();
            unsigned int j = 0;
            for (auto it = max_data.begin(); it != max_data.end(); ++it) {
                series_max->append(j, *it);
                if ( max < *it ) max = *it;
                j++;
            }
            chart->addSeries(series_min);
            chart->addSeries(series_max);

            series_min->attachAxis(axisX);
            series_min->attachAxis(axisY);
            series_max->attachAxis(axisX);
            series_max->attachAxis(axisY);

            series_min->setName("Min");
            series_max->setName("Max");
        }

        QLineSeries* series_mean = new QLineSeries();
        unsigned int k = 0;
        for (auto it = mean_data.begin(); it != mean_data.end(); ++it) {
            series_mean->append(k, *it);
            k++;
        }

        chart->addSeries(series_mean);


        series_mean->attachAxis(axisX);
        series_mean->attachAxis(axisY);
        series_mean->setName("Mean");

        axisX->setRange(0, k);
        axisY->setRange(min, max);

//        display e stili:

        if (temperature.getSimulationScale() == 'c') axisY->setTitleText("Temperature C°");
        else if (temperature.getSimulationScale() == 'f') axisY->setTitleText("Temperature F°");
        else if (temperature.getSimulationScale() == 'k') axisY->setTitleText("Temperature K°");

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignRight);
        chart->setAnimationOptions(QChart::SeriesAnimations);

    }

    QChart* SimulationVisitor::getChart() const{
        return chart;
    }

    SimulationVisitor& SimulationVisitor::setChart(QChart* chart){
        this->chart = chart;
        return *this;
    }

    QValueAxis* SimulationVisitor::getXAxis() const{
        return axisX;
    }
    SimulationVisitor& SimulationVisitor::setXAxis(QValueAxis* x){
        this->axisX = x;
        return *this;
    }
    QValueAxis* SimulationVisitor::getYAxis() const{
        return axisY;
    }
    SimulationVisitor& SimulationVisitor::setYAxis(QValueAxis* y){
        this->axisY = y;
        return *this;
    }

    QChartView* SimulationVisitor::getChartView() const {
        return view_chart;
    }

    SimulationVisitor& SimulationVisitor::setChartView(QChartView* view_chart){
        this->view_chart = view_chart;
        return *this;
    }

}